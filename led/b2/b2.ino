int redLed = 7;
int greenLed = 8;

void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop()
{
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
}
