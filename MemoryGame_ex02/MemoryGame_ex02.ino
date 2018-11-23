#define NOTE_C4 262
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_C5 523

#define NOTE_C3 131
#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247



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
  for(int i=0; i<4; i++){   
    btnState = digitalRead(buttonPins[i]);
    if(btnState == 0){
      Serial.print(buttonPins[i]);
      Serial.println(" 버튼이 눌렸어요");
    }   
  }
}
//소리
void playTone(int frequency, int duration){
  tone(piezoPin, frequency, duration);
  delay(duration);
  
}

void playTurnMelody(){
  int turnMelody[] = {NOTE_C4,NOTE_C4,NOTE_G4,NOTE_C5,NOTE_G4,NOTE_C5};
  int turnDuration[] = {100,  100,   100,  300,   100,   300};

  for(int i=0; i<6; i++){
    playTone(turnMelody[i],turnDuration[i]);
    delay(25);
  }

}


void loop() {
/*  ledOn();
  delay(1000);
  ledOff();
  delay(1000);
*/
  readButton();

  //playTone(262, 100);
  //playTone(330, 100);
  //playTone(349, 100);

  playTurnMelody();
  
}
