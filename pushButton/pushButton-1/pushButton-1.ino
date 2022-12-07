int intputPort = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(intputPort, INPUT);
}

void loop()
{
  int trangThai = digitalRead(intputPort);
  Serial.println(trangThai);
  delay(500);
}
