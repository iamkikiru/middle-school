//1. 변수설정
//2. 소리내기 playTone(), playStratMelody(), playTurnMelody()
//3. LED 켜기
//4. 로직

#define NOTE_C4 262
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_C5 523

#define NOTE_C3 131
#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247

int piezoPin = 6;
int buttonPins[] = {2,3,4,5};
int ledPins[] = {8,9,10,11};

int turn = 0;
int buttonState  = 1;
int questions[100];
int answers[100];

void setup() {

  pinMode(piezoPin,OUTPUT);
  
  // ledPins[] OUTPUT 셋업
  for(int i=0; i<4; i++){
    pinMode(ledPins[i],OUTPUT);
  }
  
  // buttonPins[] INPUT_PULLUP 셋업
  for(int i=0; i<4; i++){
    pinMode(buttonPins[i],INPUT_PULLUP);
  }


  playStartMelody();

  Serial.begin(9600);
  delay(1000);
  Serial.println("Ready");
}

//실습0 : 모든 LED 켜기
void ledOn(){
  for(int i=0; i<4; i++){
    digitalWrite(ledPins[i],HIGH);
  }
}

//실습0 : 모든 LED 끄기
void ledOff(){
  for(int i=0; i<4; i++){
    digitalWrite(ledPins[i],LOW);
  }
}

//실습1 : 버튼눌림 확인하기
void buttonCheck(){
  int buttonPush = 1;
  for(int i=0; i<4; i++){
    buttonPush = digitalRead(buttonPins[i]);
    if(buttonPush == 0){
      Serial.print(buttonPins[i]);
      Serial.println("번째 버튼이 눌렸습니다");
    }
  }
}


//실습1 : 한음 소리내기
void playTone( int frequency , int duration){
  tone(piezoPin, frequency, duration);
  delay(duration);
}

//실습2 : turnMelody 소리내기
//NOTE_C4 262, NOTE_C4 262, NOTE_G4 392, NOTE_C5 523, NOTE_G4 392,NOTE_C5 523

void playTurnMelody(){
  int turnMelody[] = { NOTE_C4, NOTE_C4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5};   
  int turnDuration[] = { 100,   100,      100,    300,      100,     300};
  
  for(int i=0; i<6; i++){
    playTone(turnMelody[i], turnDuration[i]);
    delay(25);
  }
}

//실습3 : startMelody 소리내기
void playStartMelody(){
  int startMelody[] = {NOTE_C4, NOTE_F4, NOTE_C4, NOTE_F4, NOTE_C4, NOTE_F4,
                     NOTE_C4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_G4};
  int startDuration[] = {100,   200,     100,     200,     100,      400,
                       100,   100,     100,     100,      200,     100,    500};
                       
  for(int i=0; i<13; i++){
    
    if(i==0 || i==2 || i==4 || i==6){
      digitalWrite(ledPins[0],HIGH);
    }
    if(i==1 || i==3 || i==5 || i==7 || i==9 || i==11){
      digitalWrite(ledPins[1],HIGH);
    }
    if(i==8 || i==12){    //G4
      digitalWrite(ledPins[2],HIGH);
    }
    if(i==10){
      digitalWrite(ledPins[3],HIGH);
    }  
    
    playTone(startMelody[i],startDuration[i]);
    ledOff();  
    delay(25);
  }
}

//실습4 : 문제내기(소리+LED)
void showQuestion(int q){
  int beeps[] = {NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C3};
  int duration = 100;
  int t1 = 300;
  int t2 = 100;
  
    digitalWrite(ledPins[q],HIGH);
    playTone(beeps[q],duration);
    delay(t1);
    digitalWrite(ledPins[q],LOW);
    delay(t2);  
}

//실습5 : 버튼을 눌렀는지 계속 확인하기
void yourAnswer(){
  for(int index = 0; index <= turn;){ // 버튼이 눌러지기전까지 무한루핑
    
    for(int j=0; j<4; j++){     //4개의 버튼을 모두 체크하여 그중에 눌린것이 있는지 확인
      buttonState = digitalRead(buttonPins[j]);
      if(buttonState == 0){   //버튼이 눌러졌으면
        addAndCheck(index,buttonPins[j]);   //대답 배열에 넣고 비교
        index++;
      } //if 끝.
    } //for 끝. 버튼 1개누를때마다 answers[]에 add 및 Check
    
  } //for 끝. 모든 turn에 대한 답변완료
  
  delay(500);
  turn++;   //다 맞췄으면 turn을 증가시켜 새로운 문제를 내도록함
}

//실습6 : 대답은행에 넣고 문제은행과 비교하기
void addAndCheck( int index, int btnNum){
  int beeps[] = {NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C3};
  int duration = 100;
  int t1 = 200;
  int t2 = 250;
  
  //answers[]에 add
  switch(btnNum){
    case 2:
      digitalWrite(ledPins[0],HIGH);
      playTone(beeps[0],duration);
      delay(t1);
      digitalWrite(ledPins[0],LOW);
      answers[index] = 0;
      delay(t2);
      break;
    case 3:
      digitalWrite(ledPins[1],HIGH);
      playTone(beeps[1],duration);
      delay(t1);
      digitalWrite(ledPins[1],LOW);
      answers[index] = 1;
      delay(t2);
      break;
    case 4:
      digitalWrite(ledPins[2],HIGH);
      playTone(beeps[2],duration);
      delay(t1);
      digitalWrite(ledPins[2],LOW);
      answers[index] = 2;
      delay(t2);
      break;
    case 5:
      digitalWrite(ledPins[3],HIGH);
      playTone(beeps[3],duration);
      delay(t1);
      digitalWrite(ledPins[3],LOW);
      answers[index] = 3;
      delay(t2);
      break;
  } //switch 끝

  // answers[]와 questions[]의 각 index에 대한 값 비교
  if(answers[index] != questions[index]){
    fail();
  }
  
}

//실습7 : 틀렸을때 소리내고 초기화 하기
void fail(){
  int beeps[] = {NOTE_G3, NOTE_C3};
  int duration = 200;
  
  for(int i=0; i<3; i++){
    ledOn();
    playTone(beeps[0],duration);
    ledOff();
    playTone(beeps[1],duration);
  }
  delay(500);
  turn = -1;    //턴이 초기화됨
}

void loop() {
  /*  ledOn();
  delay(1000);
  ledOff();
  delay(1000);
*/
  //readButton();

  //playTone(262, 100);
  //playTone(330, 100);
  //playTone(349, 100);

  //playTurnMelody();

  // 
  //실습3.시작멜로디 실행

  //실습4. 문제내기
  
  //실습 5,6,7 코드완성

  //스케치 작성
}


