
#define NOTE_G4 392
#define NOTE_C5 523

int redLed = 8;
int activePiezo = 9;
int redButton = 10;
int yellowLed = 11;
int passivePiezo = 12;

int redButtonState  = 1; //안눌렸을때 1

void setup() {

  // led OUTPUT 셋업
  pinMode(redLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  
  // piezoPin OUTPUT 셋업
  pinMode(activePiezo,OUTPUT);
  pinMode(passivePiezo,OUTPUT);
  
  // button INPUT_PULLUP 셋업
  pinMode(redButton,INPUT_PULLUP);

  delay(500);

}

/////////////////////////////////////////////////////////////////////////////////

void playTone( int frequency , int duration){
  tone(passivePiezo, frequency, duration);
  delay(duration);
}

///////////////////////실습 : red 버튼 누루면 red led 켜지고 소리내기 ///////////////////////////

void loop() {
  
  redButtonState = digitalRead(redButton);  //버튼핀의 값을 읽어서...
  if(redButtonState == 0){   //값이 0(버튼이 눌러졌으면)
     digitalWrite(redLed,HIGH);    //redLed를 켜고
     digitalWrite(activePiezo,HIGH);
     //playTone(NOTE_G4,100);           // 0.1초간 소리내고
     delay(100);                      // 소리날동안 기다리고
     digitalWrite(redLed,LOW);     // redLed 끄고
     digitalWrite(activePiezo,LOW);
     delay(100);                      // 0.1초 기다린다.
  }

}





/*
  greenButtonState = digitalRead(greenButton);
  if(greenButtonState == 0){   //버튼이 눌러졌으면
     digitalWrite(greenLed,HIGH);
     playTone(NOTE_C5,100);
     delay(100);
     digitalWrite(greenLed,LOW);
     delay(100);
  }
*/








