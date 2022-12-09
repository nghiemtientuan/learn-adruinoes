#define servoPin 9  // servo Pin
int pos; // angle variable of servo
int pulsewidth; // pulse width variable of servo

void setup() {
  pinMode(servoPin, OUTPUT);  // set servo pin to OUTPUT
  controlServo(0); // set the angle of servo to 0°
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    controlServo(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    controlServo(pos);
    delay(15);  
  }
}

// function to control servo
void controlServo(int myAngle) {
  pulseWidth = myAngle * 11 + 500;  // calculate the value of pulse width
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseWidth);   // The duration of high level is pulse width
  digitalWrite(servoPin, LOW);
  delay((20 - pulseWidth / 1000));  // the cycle is 20ms, the low level last for the rest of time
}
