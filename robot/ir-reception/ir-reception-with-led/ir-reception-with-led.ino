#include <IRremoteTank.h>

#define OK_BUTTON = 0xFF02FD

int RECV_PIN = A0; // define the pin of IR receiver as A0
int LED_PIN = 10; // define the pin of LED
int a = 0;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Initialize the IR receiver 
  pinMode(LED_PIN, OUTPUT); // set LED_pin to OUTPUT
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == OK_BUTTON) {
      if (a == 0) {
        // according to the above key value, press“OK”on remote control, LED will be controlled
        digitalWrite(LED_PIN, HIGH); // LED will be on
        a = 1;
      } else { // press again
        digitalWrite(LED_PIN, LOW); // LED will go off
        a = 0;
      }
    }
    irrecv.resume(); // receive the next value
  }
}
