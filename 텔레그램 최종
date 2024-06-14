#include "CTBot.h"
#include <ArduinoJson.h>
#include <DHT.h>

#define dhtpin 5
#define dhttype DHT22
DHT dht(dhtpin, dhttype);
CTBot myBot;
String ssid = "senWiFi_Free"; // WiFi SSID
String pass = "tnfkr2021!";   // WiFi Password
String token = "6640765289:AAGWX1c10CO4ePEUoPdWNHpLAByCycPDHA4"; // Telegram Bot Token
int64_t chat_id = -1002044037502; // Chat ID
int AA = 4;
int AB = 14;
int BA = 12;
int BB = 13;
TBMessage msg;

unsigned long previousMillis = 0;
const long interval = 600000; // 10 minutes

void setup() {
   Serial.begin(9600);
   dht.begin();
   pinMode(AA, OUTPUT);
   pinMode(AB, OUTPUT);
   pinMode(BA, OUTPUT);
   pinMode(BB, OUTPUT);
   Serial.println();
   Serial.println("Connecting to WiFi...");
   myBot.wifiConnect(ssid, pass);
   delay(1000);

   myBot.setTelegramToken(token);
   if (myBot.testConnection()) {
      Serial.println("Connected successfully.");
      myBot.sendMessage(chat_id, "텔레그램 봇이 성공적으로 연결되었습니다");
   } else {
      Serial.println("Connection failed.");
   }
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    float h = dht.readHumidity();
    float t = dht.readTemperature();
    int v1 = analogRead(A0);
    myBot.sendMessage(chat_id, "습도: " + String(h) + ", 온도: " + String(t) + ", 토양습도: " + String(v1));

    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(", Temperature: ");
    Serial.print(t);
    Serial.print(", Soil Moisture: ");
    Serial.print(v1);
    Serial.println();

    if (v1 > 350) {
      Waterpump();
    }
  }

  if (myBot.getNewMessage(msg)) {
    Serial.println();
    Serial.println(msg.text);
    if (msg.text == "water") {
      myBot.sendMessage(chat_id, "물을 줍니다");
      Serial.println("물을 줍니다");
      Waterpump();
    } else {
      String reply = "Hello, " + msg.sender.username + ". water 명령어를 사용해서 물을 주세요";
      myBot.sendMessage(chat_id, reply);
      Serial.println("Use the command 'water' to water the plant.");
    }
  }
}

void Waterpump() {
  digitalWrite(AA, HIGH);
  digitalWrite(AB, LOW);
  digitalWrite(BA, HIGH);
  digitalWrite(BB, LOW);
  delay(15000); // Watering for 15 seconds
  digitalWrite(AA, LOW);
  digitalWrite(AB, LOW);
  digitalWrite(BA, LOW);
  digitalWrite(BB, LOW);
}
