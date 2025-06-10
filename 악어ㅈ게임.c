#include<Servo.h>
Servo myservo1;
Servo myservo2;
int melody[] = {262, 330, 392};
int pos = 0;

const int buzz = 12;
const int button01 = 3;
const int button02 = 4;
const int button03 = 5;
const int button04 = 6;
const int button05 = 7;
const int button06 = 8;
const int button07 = 9;
const int start_pin = 10;
void setup(){
  myservo1.attach(12);
  myservo1.write(90);
  myservo2.attach(13);
  myservo2.write(0);
pinMode(3, INPUT_PULLUP);
pinMode(4, INPUT_PULLUP);
pinMode(5, INPUT_PULLUP);
pinMode(6, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);
pinMode(8, INPUT_PULLUP);
pinMode(9, INPUT_PULLUP);
pinMode(10, INPUT_PULLUP);
pinMode(buzz, OUTPUT);
Serial.begin(9600);
randomSeed(analogRead(0));

}

void loop() {
  int bt_value =digitalRead(start_pin);
  Serial.println(bt_value);
  if(!bt_value){
    myservo1.write(0);
    myservo2.write(90);
    int value= random(1,7);
    Serial.println(value);
    while(true){
      if(value == 1 && !digitalRead(button01)){
        myservo1.write(90);
        myservo2.write(0);
        playSound();
        delay(100);
        break;
      }else if(value == 2 && !digitalRead(button02)){
        myservo1.write(90);
        myservo2.write(0);
        playSound();
        delay(100);
        break;
      }else if(value == 3 && !digitalRead(button03)){
        myservo1.write(90);
        myservo2.write(0);
        playSound();
        delay(100);
        break;
      }else if(value == 4 && !digitalRead(button04)){
        myservo1.write(90);
        myservo2.write(0);
        playSound();
        delay(100);
        break;
      }else if(value == 5 && !digitalRead(button05)){
        myservo1.write(90);
        myservo2.write(0);
        playSound();
        delay(100);
        break;
      }else if(value == 6 && !digitalRead(button06)){
        myservo1.write(90);
        myservo2.write(0);
        playSound();
        delay(100);
        break; 
      }else if(value == 7 && !digitalRead(button07)){
        myservo1.write(90);
        myservo2.write(0);
        playSound();
        delay(100);
        break; 
      }
    }
  }
}

void playSound(){
  for(int i = 0; i < 3; i++){
        tone(buzz, melody[i], 250);
        delay(400);
        noTone(buzz);
  }
}
