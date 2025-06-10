#include <SoftwareSerial.h>

SoftwareSerial HC05(2, 3); // RX, TX

void setup() {
 Serial.begin(9600);
 HC05.begin(38400);
 pinMode(8, INPUT);
 pinMode(9,INPUT);
 pinMode(10,INPUT);
 pinMode(11,INPUT);

}

void loop() { // run over and over
  int readValue = digitalRead(8);
  Serial.println(readValue);

  if(readValue ==HIGH) {
    HC05.print("1");
    delay(1000);
  }
  int readValue1 = digitalRead(9);
  Serial.println(readValue1);

  if(readValue1 ==HIGH) {
    HC05.print("2");
    delay(1000);
  }
  int readValue2 = digitalRead(10);
  Serial.println(readValue2);

  if(readValue2 ==HIGH) {
    HC05.print("3");
    delay(1000);
  }
  int readValue3 = digitalRead(11);
  Serial.println(readValue3);

  if(readValue3 ==HIGH) {
    HC05.print("4");
    delay(1000);
  }
}
