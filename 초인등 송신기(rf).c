#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // SPI 버스에 nRF24L01 라디오를 설정하기 위해 CE, CSN를 선언.
const byte address[6] = "00001"; 

void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  radio.begin();
  radio.openWritingPipe(address); //이전에 설정한 5글자 문자열인 데이터를 보낼 수신의 주소를 설정
  radio.setPALevel(RF24_PA_MIN); //전원공급에 관한 파워레벨을 설정합니다. 모듈 사이가 가까우면 최소로 설정합니다.

  radio.stopListening();  //모듈을 송신기로 설정
  Serial.println("Setup completed");
}

void loop() { // run over and over
  int readValue = digitalRead(3);
  Serial.print("Read pin 3: ");
  Serial.println(readValue);

  if(readValue == HIGH) {
    const char text[] = "1";
    bool success = radio.write(&text, sizeof(text)); //해당 메시지를 수신자에게 보냄
    if(success) {
      Serial.println("Message 1 sent successfully");
    } else {
      Serial.println("Failed to send message 1");
    }
    delay(1000);
  }
  
  int readValue1 = digitalRead(4);
  Serial.print("Read pin 4: ");
  Serial.println(readValue1);

  if(readValue1 == HIGH) {
    const char text[] = "2";
    bool success = radio.write(&text, sizeof(text)); //해당 메시지를 수신자에게 보냄
    if(success) {
      Serial.println("Message 2 sent successfully");
    } else {
      Serial.println("Failed to send message 2");
    }
    delay(1000);
  }
  
  int readValue2 = digitalRead(5);
  Serial.print("Read pin 5: ");
  Serial.println(readValue2);

  if(readValue2 == HIGH) {
    const char text[] = "3";
    bool success = radio.write(&text, sizeof(text)); //해당 메시지를 수신자에게 보냄
    if(success) {
      Serial.println("Message 3 sent successfully");
    } else {
      Serial.println("Failed to send message 3");
    }
    delay(1000);
  }
  
  int readValue3 = digitalRead(6);
  Serial.print("Read pin 6: ");
  Serial.println(readValue3);

  if(readValue3 == HIGH) {
    const char text[] = "4";
    bool success = radio.write(&text, sizeof(text)); //해당 메시지를 수신자에게 보냄
    if(success) {
      Serial.println("Message 4 sent successfully");
    } else {
      Serial.println("Failed to send message 4");
    }
    delay(1000);
  }
}
