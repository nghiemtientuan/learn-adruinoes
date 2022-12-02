int congTac = 2;
int led = 3;

int status = LOW;

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
  
  // check push button
  if (trangThai == 0) {
    status = status == LOW ? HIGH : LOW;
    digitalWrite(led, status);
    delay(1000);
  }
}
