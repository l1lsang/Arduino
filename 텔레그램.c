#include "CTBot.h"
#include <ArduinoJson.h>
#include <DHT.h>

#define dhtpin 5
#define dhttype DHT22
DHT dht(dhtpin, dhttype);
CTBot myBot;
String ssid = "senWiFi_Free"; // 공유기 연결 wifi SSID. 2.4GHz 사용할 것. 5G는 연결 안됨. 
String pass = "tnfkr2021!";   // 공유기 연결 wifi 비밀번호
String token = "6640765289:AAGWX1c10CO4ePEUoPdWNHpLAByCycPDHA4"; // 텔레그람 봇파더로부터 부여 받은 봇토큰
int64_t chat_id = -1002044037502; // 대화 ID (텔레그램에서 얻을 수 있음)
int AA = 4;
int AB = 14;
int BA = 12;
int BB = 13;
TBMessage msg;

void setup() { 
   Serial.begin(9600);  // open serial port, set the baud rate as 9600 bps 
   dht.begin();
   pinMode(AA, OUTPUT);
   pinMode(AB, OUTPUT);
   pinMode(BA, OUTPUT);
   pinMode(BB, OUTPUT);
   Serial.println();
   Serial.println("WiFi 연결중입니다..");
   myBot.wifiConnect(ssid, pass);
   delay(1000);

   myBot.setTelegramToken(token);
   if (myBot.testConnection()) {
      Serial.println("연결이 잘 되었습니다.");
      myBot.sendMessage(chat_id, "텔레그램 봇 연결이 성공적으로 완료되었습니다!");
   } else {
      Serial.println("연결이 잘 되지않았습니다.");
   }
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int v1 = analogRead(A0);
  myBot.sendMessage(chat_id, "습도: " + String(h) + ","+"온도: " + String(t)+ ","+ "토양습도: " + String(v1));

  Serial.print("humidity:");
  Serial.print(h);
  Serial.print(",");
  Serial.print("temperature:");
  Serial.print(t);
  Serial.print(",");
  Serial.print("val:");
  Serial.print(v1);
  Serial.print("\n");
  
  if(v1 < 400){
    Waterpump();
  } else {
    delay(10000);
  }

  if (myBot.getNewMessage(msg)) {
    Serial.println();
    Serial.println(msg.text);
    if (msg.text == "water") { 
      myBot.sendMessage(chat_id, "물을 줍니다.."); 
      Serial.println("식물에 물을 줍니다..");
      Waterpump();
    }
    else { 
String reply;
reply = (String)"안녕하세요? " + msg.sender.username + (String)"님, 'water' 메세지로 식물에 물을 주세요..";
myBot.sendMessage(chat_id, reply);
Serial.println("'water' 메세지로 식물에 물을 주세요.."); 
}
  }
}

void Waterpump() {
  digitalWrite(AA, HIGH);
  digitalWrite(AB, LOW);
  digitalWrite(BA, HIGH);
  digitalWrite(BB, LOW);
  delay(3000);
  digitalWrite(AA, LOW);
  digitalWrite(AB, LOW);
  digitalWrite(BA, LOW);
  digitalWrite(BB, LOW);
  delay(2000);
}
