int ledPin = 10;
int value;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (value = 0; value < 255; value = value + 1) {
    analogWrite(ledPin, value); // LED lights gradually light up
    delay(5);
  }
  for (value = 255; value > 0; value = value - 1) {
    analogWrite(ledPin, value); // LED gradually goes out
    delay(5);
  }
}
