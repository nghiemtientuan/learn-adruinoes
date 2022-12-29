#define SCL_Pin A5
#define SDA_Pin A4

unsigned char goLeds[] = {0x00, 0x00, 0x00, 0x3c, 0x42, 0x52, 0x34, 0x10, 0x00, 0x3c, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00};

void setup() {
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
}

void loop() {
  matrix_display(goLeds);
}

void matrix_display(unsigned char matrix_value[]) {
  IIC_start();  // use the function of the data transmission start condition
  IIC_send(0xc0);  // select address
  for (int i = 0; i < 16; i++) { // pattern data has 16 bits
     IIC_send(matrix_value[i]); // convey the pattern data
  }
  IIC_end();   // end the transmission of pattern data
  
  IIC_start();
  IIC_send(0x8A);  // display control, set pulse width to 4/16 s
  IIC_end();
}

void IIC_start() {
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
}


void IIC_send(unsigned char send_data) {
  for (char i = 0; i < 8; i++) {
      digitalWrite(SCL_Pin, LOW);
      delayMicroseconds(3);
      if (send_data & 0x01) {
        digitalWrite(SDA_Pin, HIGH);
      } else {
        digitalWrite(SDA_Pin, LOW);
      }
      delayMicroseconds(3);
      digitalWrite(SCL_Pin, HIGH);
      delayMicroseconds(3);
      send_data = send_data >> 1;
  }
}

void IIC_end() {
  digitalWrite(SCL_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
}
