// servo
#include <Servo.h>
Servo headServo;
int headPosition = 0;

// motors
#define MOTOR_LEFT_Ctrl 13  // direction control
#define MOTOR_LEFT_PWM 11   // define toc do
#define MOTOR_RIGHT_Ctrl 12  // direction control
#define MOTOR_RIGHT_PWM 3    // define the toc do
#define MOTOR_UP_VALUE LOW
#define MOTOR_BACK_VALUE HIGH
#define MOTORS_SPEED 200

// maxtrix leds
#define SCL_Pin A5
#define SDA_Pin A4

int rightSensor = A1;
int leftSensor = A2;
int rightSensorValue = 0;
int leftSensorValue = 0;

unsigned long time;

// Display
unsigned char clear[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char STOP[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char LEFT[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char RIGHT[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char AHEAD[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};

void setup() {
  // logs
  Serial.begin(9600);

  // servo
  headServo.attach(9);

  // motors setups
  pinMode(MOTOR_LEFT_Ctrl, OUTPUT);
  pinMode(MOTOR_LEFT_PWM, OUTPUT);
  pinMode(MOTOR_RIGHT_Ctrl, OUTPUT);
  pinMode(MOTOR_RIGHT_PWM, OUTPUT);

  // matrix leds setup
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);

  // timing
  time = millis();
  matrix_display(clear);
}

void loop() {
  // loop in 2s
  if ((unsigned long) (millis() - time) > 50) {
    // matrix_display(clear);

    rightSensorValue = analogRead(rightSensor);
    Serial.print("rightSensorValue: ");
    Serial.println(rightSensorValue);
    leftSensorValue = analogRead(leftSensor);
    Serial.print("leftSensorValue: ");
    Serial.println(leftSensorValue);

    // right and left is less light
    if (rightSensorValue <= 200 and leftSensorValue <= 200) {
      // stop
      Serial.println("stop");
      matrix_display(STOP);
      headChangePosition(90);
      stopped();
    } else {
      // right > left
      if (rightSensorValue - leftSensorValue > 200) {
        // turn right
        Serial.println("turn right");
        matrix_display(RIGHT);
        headChangePosition(45);
        runRight();
      } else {
        // right < left
        if (leftSensorValue - rightSensorValue > 200) {
          // turn left
          Serial.println("turn left");
          matrix_display(LEFT);
          headChangePosition(135);
          runLeft();
        } else {
          // strage ahead
          Serial.println("strage ahead");
          matrix_display(AHEAD);
          headChangePosition(90);
          runAhead();
        }
      }
    }
    
    time = millis();
  }
}

/* Leds display */
void matrix_display(unsigned char matrix_value[]) {
  IIC_start();  // use the function of the data transmission start condition
  IIC_send(0xc0);  // select address
  for (int i = 0; i < 16; i++) { // pattern data has 16 bits
     IIC_send(matrix_value[i]); // convey the pattern data
  }
  IIC_end();   // end the transmission of pattern data
  
  IIC_start();
  IIC_send(0x8A);  // display control, set pulse width to 4/16 s
  IIC_end();
}

void IIC_start() {
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
}


void IIC_send(unsigned char send_data) {
  for (char i = 0; i < 8; i++) {
      digitalWrite(SCL_Pin, LOW);
      delayMicroseconds(3);
      if (send_data & 0x01) {
        digitalWrite(SDA_Pin, HIGH);
      } else {
        digitalWrite(SDA_Pin, LOW);
      }
      delayMicroseconds(3);
      digitalWrite(SCL_Pin, HIGH);
      delayMicroseconds(3);
      send_data = send_data >> 1;
  }
}

void IIC_end() {
  digitalWrite(SCL_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
}
/* END Leds display */

/* Servo change */
void headChangePosition(int to) {
  if (to != headPosition) {
    headServo.write(to);
    headPosition = to;
  }
}
/* END Servo change */

/* Motors change */
void runAhead() {
  digitalWrite(MOTOR_LEFT_Ctrl, MOTOR_UP_VALUE);
  analogWrite(MOTOR_LEFT_PWM, MOTORS_SPEED);
  digitalWrite(MOTOR_RIGHT_Ctrl, MOTOR_UP_VALUE);
  analogWrite(MOTOR_RIGHT_PWM, MOTORS_SPEED);
}

void runBack() {
  digitalWrite(MOTOR_LEFT_Ctrl, MOTOR_BACK_VALUE);
  analogWrite(MOTOR_LEFT_PWM, MOTORS_SPEED); 
  digitalWrite(MOTOR_RIGHT_Ctrl, MOTOR_BACK_VALUE);
  analogWrite(MOTOR_RIGHT_PWM, MOTORS_SPEED);
}

void runLeft() {
  digitalWrite(MOTOR_LEFT_Ctrl, MOTOR_BACK_VALUE);
  analogWrite(MOTOR_LEFT_PWM, MOTORS_SPEED);
  digitalWrite(MOTOR_RIGHT_Ctrl, MOTOR_UP_VALUE);
  analogWrite(MOTOR_RIGHT_PWM, MOTORS_SPEED);
}

void runRight() {
  digitalWrite(MOTOR_LEFT_Ctrl, MOTOR_UP_VALUE);
  analogWrite(MOTOR_LEFT_PWM, MOTORS_SPEED);
  digitalWrite(MOTOR_RIGHT_Ctrl, MOTOR_BACK_VALUE);
  analogWrite(MOTOR_RIGHT_PWM, MOTORS_SPEED);
}

void stopped() {
  analogWrite(MOTOR_LEFT_PWM, 0);
  analogWrite(MOTOR_RIGHT_PWM, 0);
}
/* END Motors change */
