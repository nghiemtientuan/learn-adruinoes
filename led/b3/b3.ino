int green = 6;
int red = 7;
int yellow = 8;

void setup()
{
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);

  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
  digitalWrite(yellow, HIGH);
}

void loop()
{
  delay(500);
  digitalWrite(green, LOW);
  delay(500);
  digitalWrite(red, LOW);
  delay(500);
  digitalWrite(yellow, LOW);

  delay(500);
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
  digitalWrite(yellow, HIGH);
}
