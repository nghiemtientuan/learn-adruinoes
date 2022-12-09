int analogInPin = A1;  // Analog input pin that the photocell is attached to
int led = 10; // Analog output pin that the LED is attached to

// values
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  Serial.println(sensorValue);
  
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(led, outputValue);
  delay(2);
}
