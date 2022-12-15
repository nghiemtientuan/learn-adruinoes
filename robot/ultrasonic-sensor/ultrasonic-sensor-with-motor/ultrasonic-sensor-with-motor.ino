#define ML_Ctrl 13  // define the direction control pin of left motor
#define ML_PWM 11   // define PWM control pin of left motor
#define MR_Ctrl 12  // define the direction control pin of right motor
#define MR_PWM 3   // define PWM control pin of right motor
#define Trig 5  // ultrasonic trig Pin
#define Echo 4  // ultrasonic echo Pin
#define servoPin 9  // servo Pin

int frontDistance;
int rightDistance;
int leftDistance;

void setup() {
  pinMode(servoPin, OUTPUT);
  procedure(90); // set servo to 90°
  
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(ML_Ctrl, OUTPUT);
  pinMode(ML_PWM, OUTPUT);
  pinMode(MR_Ctrl, OUTPUT);
  pinMode(MR_PWM, OUTPUT);
}

void loop() {
  // Using ultrasonic sensor get current front distance
  frontDistance = getDistance();
  
  if (frontDistance < 20) {
      // when the front distance detected is less than 20 
      carStop();  // robot stops
      delay(500); // delay in 500ms

      // Ultrasonic turns left
      controlServo(160);
      for (int j = 1; j <= 10; j = j + 1) {
        // for statement, the data will be more accurate if ultrasonic sensor detect a few times.
        // Using ultrasonic sensor get current left distance
        leftDistance = getDistance();
      }
      delay(300);

      // Ultrasonic turns right
      controlServo(20);
      for (int k = 1; k <= 10; k = k + 1) {
        // Using ultrasonic sensor get current right distance
        rightDistance = getDistance();
      }

      // robot will turn to the longer distance side when left or right distance is less than 50cm.
      if (leftDistance < 50 || rightDistance < 50) {
        // left distance is greater than right side  
        if (leftDistance > rightDistance) {    
          conctrolServo(90);  // Ultrasonic platform turns back to right ahead         
          carLeft();  // robot turns left
          delay(500);  // turn left for 500ms
          
          carFront();
        } else {
          conctrolServo(90);
          carRight(); // robot turns right
          delay(500);
          
          carFront();
        }
      } else {
        int random2 = random(1, 100);
        
        // If both side is greater than or equal to 50cm, turn left or right randomly
        if ((long) (random2) % (long) (2) == 0) {  // When the random number is even
          conctrolServo(90);
          carLeft(); // tank robot turns left
          delay(500);
          
          carFront();
        } else {
          conctrolServo(90);
          carRight(); // robot turns right
          delay(500);
          
          carFront();
       }
     }
  } else {
    // If the front distance is greater than or equal to 20cm, robot car will go front
    carFront();
  }
}

void carFront() {
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, 200);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 200);
}

void carBack() {
  digitalWrite(MR_Ctrl, HIGH);
  analogWrite(MR_PWM, 200);
  digitalWrite(ML_Ctrl, HIGH);
  analogWrite(ML_PWM, 200);
}

void carLeft() {
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, 255);
  digitalWrite(ML_Ctrl, HIGH);
  analogWrite(ML_PWM, 255);
}

void carRight() {
  digitalWrite(MR_Ctrl, HIGH);
  analogWrite(MR_PWM, 255);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 255);
}

void carStop() {
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, 0);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 0);
}

// The function to control servo
void controlServo(int myangle) {
  for (int i = 0; i <= 50; i = i + 1) {
    int pulsewidth = myangle * 11 + 500;
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulsewidth);
    digitalWrite(servoPin, LOW);
    delay((20 - pulsewidth / 1000));
  }
}

// The function to control ultrasonic sensor
float getDistance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  float distance = pulseIn(Echo, HIGH) / 58.00;  // 2 * 29.1 = 58.2
  delay(10);
  
  return distance;
}
