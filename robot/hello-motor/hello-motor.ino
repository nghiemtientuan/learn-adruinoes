// define dinh nghia hang so
#define ML_Ctrl 13  // define the direction control pin of left motor
#define ML_PWM 11   // define the PWM control pin of left motor - toc do
#define MR_Ctrl 12  // define direction control pin of right motor
#define MR_PWM 3    // define the PWM control pin of right motor - toc do

#define UP_VALUE LOW
#define BACK_VALUE HIGH

#define SPEED 200 // The PWM value is in the range of 0-255

void setup()
{
  pinMode(ML_Ctrl, OUTPUT);
  pinMode(ML_PWM, OUTPUT);
  pinMode(MR_Ctrl, OUTPUT);
  pinMode(MR_PWM, OUTPUT);
}

void loop()
{
  // front
  runFront();
  delay(2000);

  // back
  runBack();
  delay(2000);

  // left
  runLeft();
  delay(2000);

  // right
  runRight();
  delay(2000);

  // stop
  stopped();
  delay(2000);
}

void runFront() {
  digitalWrite(ML_Ctrl, UP_VALUE);
  analogWrite(ML_PWM, SPEED);
  digitalWrite(MR_Ctrl, UP_VALUE);
  analogWrite(MR_PWM, SPEED);
}

void runBack() {
  digitalWrite(ML_Ctrl, BACK_VALUE);
  analogWrite(ML_PWM, SPEED); 
  digitalWrite(MR_Ctrl, BACK_VALUE);
  analogWrite(MR_PWM, SPEED);
}

void runLeft() {
  digitalWrite(ML_Ctrl, BACK_VALUE);
  analogWrite(ML_PWM, SPEED);
  digitalWrite(MR_Ctrl, UP_VALUE);
  analogWrite(MR_PWM, SPEED);
}

void runRight() {
  digitalWrite(ML_Ctrl, UP_VALUE);
  analogWrite(ML_PWM, SPEED);
  digitalWrite(MR_Ctrl, BACK_VALUE);
  analogWrite(MR_PWM, SPEED);
}

void stopped() {
  analogWrite(ML_PWM, 0);
  analogWrite(MR_PWM, 0);
}
