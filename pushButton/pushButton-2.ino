int congTac = 2;
int led = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(congTac, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop()
{
  int trangThai = digitalRead(congTac);
  Serial.println(trangThai);
  
  digitalWrite(led, LOW);
  if (trangThai != 1) {
    digitalWrite(led, HIGH);
  }
}
