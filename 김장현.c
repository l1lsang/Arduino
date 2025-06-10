#include <LedControl.h>

//(DIN핀, CLK핀, CS핀, 모듈개수)
LedControl lc = LedControl(12, 11, 10, 1); 

byte heart[] = {
  B01110010,
  B00010010,
  B00010010,
  B00000000,
  B00111100,
  B00100100,
  B00111100,
  B00000000
};

byte heart2[] = {
  B00000000,
  B01110010,
  B00100011,
  B01010010,
  B00001100,
  B00010010,
  B00001100,
  B00000000
};
byte heart3[] = {
  B01000110,
  B11100010,
  B01000110,
  B10100010,
  B01000000,
  B00100000,
  B00111100,
  B00000000
};

void setup() {
  lc.shutdown(0, false); // 절전모드를 끄기
  lc.setIntensity(0, 5); // 밝기 지정(0~15)
  lc.clearDisplay(0);  // 화면clear(이전 값 초기화)
}

void loop() {
  display_heart(0); // 하트모양 표시
  delay(500);
  display_heart(1); // 기본모양 표시
  delay(500);
  display_heart(2); // 기본모양 표시
  delay(500);
}

void display_heart(int a){
  if(a==0){ // 하트모양 표시
     for(int i=0; i<8; i++){
       lc.setRow(0, i, heart[i]);
      }
   } else if(a==1){
     for(int i=0; i<8; i++){
       lc.setRow(0, i, heart2[i]);
     }
   } else { // 기본모양 표시
    for(int i=0; i<8; i++){
      lc.setRow(0, i,heart3[i]);  //(deviceNumber, row, rowBit )
    }
   }
}
