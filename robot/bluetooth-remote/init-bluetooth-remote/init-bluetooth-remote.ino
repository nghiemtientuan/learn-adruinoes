char ble_val; //character variable: save the value of Bluetooth reception

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {  // Judge if there is data in serial buffer
    ble_val = Serial.read();  // Read data from serial buffer
    Serial.println(ble_val);  // Print
  }
}
