#include <SoftwareSerial.h>
#define rxPin 8
#define txPin 12
#define baud 9600

String buffer = "";

SoftwareSerial bt(rxPin, txPin);

void setup() {
  Serial.begin(baud);
  bt.begin(baud);
}

void loop() {
    while (bt.available() > 0) {
      char data = (char) bt.read();
      buffer += data;
      if (data == '\n') {
        Serial.println(buffer);
        bt.print("Your message: "+ buffer);
        buffer = "";
      }
  }
  /*
  if (Serial.available() > 0) {
    buffer = Serial.read();
    bt.print(buffer);
  }
  */
}
