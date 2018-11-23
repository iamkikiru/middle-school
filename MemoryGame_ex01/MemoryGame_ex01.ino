int piezoPin = 6; //정수형 변수 piezoPin을 만들고 6을 대입해라
int buttonPins[] = {2,3,4,5}; 
//정수형 배열 buttonPins[]를 만들고 2,3,4,5를 대입해라
int ledPins[] = {8,9,10,11};
//정수형 배열 ledPins[]를 만들고 8,9,10,11을 대입해라

void setup() {
  pinMode(piezoPin, OUTPUT);  //piezoPin을 OUTPUT으로 셋팅한다
  for(int i=0; i<4; i++){
    pinMode(ledPins[i],OUTPUT);
  }

  for(int i=0; i<4; i++){
    pinMode(buttonPins[i],INPUT_PULLUP);
  }

  Serial.begin(9600); 
  //baud rate를 9600으로 설정해서 시리얼통신을 시작해라
  Serial.println("준비완료");
}

void ledOn(){
 for(int i=0; i<4; i++){
    digitalWrite(ledPins[i],HIGH);
  }
}

void ledOff(){
  for(int i=0; i<4; i++){
    digitalWrite(ledPins[i],LOW);
  }  
}

void readButton(){
  int btnState = 1;
  for(int i=0; i<4; i++){     //4개의 버튼을 모두 체크하여 그중에 눌린것이 있는지 확인
      btnState = digitalRead(buttonPins[i]);
      if(btnState == 0){   //버튼이 눌러졌으면
        Serial.print(buttonPins[i]);
        Serial.println("  번 버튼이 눌렸어요");
      }
    }  
}


void loop() {
/*  ledOn();
  delay(1000);
  ledOff();
  delay(1000);
*/
  readButton();
}
