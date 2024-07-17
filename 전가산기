const int buttonPin = 10;  // 버튼이 연결된 핀 번호
const int buttonPin2 = 11;  // 버튼이 연결된 핀 번호
const int buttonPin3 = 12;  // 버튼이 연결된 핀 번호


void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // 버튼 핀을 입력으로 설정하고 내부 풀업 저항을 활성화
  pinMode(buttonPin2, INPUT_PULLUP);  // 버튼 핀을 입력으로 설정하고 내부 풀업 저항을 활성화
  pinMode(buttonPin3, INPUT_PULLUP);  // 버튼 핀을 입력으로 설정하고 내부 풀업 저항을 활성화

  pinMode(3, OUTPUT);          // LED 핀을 출력으로 설정
  pinMode(4, OUTPUT);         // 두 번째 LED 핀을 출력으로 설정
  pinMode(5, OUTPUT);         // 두 번째 LED 핀을 출력으로 설정

  Serial.begin(9600);                // 시리얼 통신을 시작하며, 통신 속도를 9600bps로 설정
}

void loop() {
  int buttonState = digitalRead(buttonPin);  // 버튼의 상태를 읽어옴
  int buttonState2 = digitalRead(buttonPin2);  // 버튼의 상태를 읽어옴
  int buttonState3 = digitalRead(buttonPin3);  // 버튼의 상태를 읽어옴

  // 버튼이 눌렸을 때 (내부 풀업 저항을 사용하므로 버튼이 눌리면 LOW가 됨)
  if (buttonState == LOW) {
    //Serial.println("pushed");  // 시리얼 모니터에 'push'을 출력
    digitalWrite(3,HIGH); // LOW로 바꿔보세요
    delay(50);          // 다음 입력을 받기 전에 100ms 동안 기다림 (디바운싱)
  }
  else{
    //Serial.println("not pushed");
    digitalWrite(3,LOW); // LOW로 바꿔보세요
    delay(50);
  }

    // 버튼이 눌렸을 때 (내부 풀업 저항을 사용하므로 버튼이 눌리면 LOW가 됨)
  if (buttonState2 == LOW) {
    //Serial.println("2 pushed");  // 시리얼 모니터에 'push'을 출력
    digitalWrite(4,HIGH); // LOW로 바꿔보세요
    delay(50);          // 다음 입력을 받기 전에 100ms 동안 기다림 (디바운싱)
  }
  else{
    //Serial.println("2 not pushed");
    digitalWrite(4,LOW); // LOW로 바꿔보세요
    delay(50);
  }
  if (buttonState3 == LOW) {
    //Serial.println("3 pushed");  // 시리얼 모니터에 'push'을 출력
    digitalWrite(5,HIGH); // LOW로 바꿔보세요
    delay(50);          // 다음 입력을 받기 전에 100ms 동안 기다림 (디바운싱)
  }
  else{
    //Serial.println("2 not pushed");
   digitalWrite(5,LOW); // LOW로 바꿔보세요
   delay(50);
  }
  //delay(00);
}
