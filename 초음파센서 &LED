const int trig = 4;
const int echo = 3;
const int led = 8;
long duration = 0;
float distance = 0;

void setup() {
//핀 설정
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(led, OUTPUT);
Serial.begin(9600);
}

void loop() {
//초음파 발생
digitalWrite(trig, LOW);
digitalWrite(echo, LOW);
delayMicroseconds(3);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);

//초음파로 거리측정(변환)
duration = pulseIn(echo, HIGH); // 초음파 읽기
distance = duration/29/2; // cm 단위로 변환

//시리얼 모니터에 거리값 나타내기
Serial.print(distance);
Serial.println("cm");

//거리값으로 LED 켜고 끄기
if (distance < 10) digitalWrite(led, HIGH);
else digitalWrite(led, LOW);

delay(100);
