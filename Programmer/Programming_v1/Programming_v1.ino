
#define NOTE_G4 392
#define NOTE_C5 523

int yellowLed = 8;
int greenLed = 9;
int piezoPin = 10;
int yellowButton = 11;
int greenButton = 12;

int yellowButtonState  = 1; //안눌렸을때 1
int greenButtonState  = 1;  //안눌렸을때 1

void setup() {

  // led OUTPUT 셋업
  pinMode(yellowLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  
  // piezoPin OUTPUT 셋업
  pinMode(piezoPin,OUTPUT);
  
  // button INPUT_PULLUP 셋업
  pinMode(yellowButton,INPUT_PULLUP);
  pinMode(greenButton,INPUT_PULLUP);

  delay(500);

}

/////////////////////////////////////////////////////////////////////////////////

void playTone( int frequency , int duration){
  tone(piezoPin, frequency, duration);
  delay(duration);
}

///////////////////////실습 : green 버튼 누루면 green led 켜지고 소리내기 ///////////////////////////

void loop() {
  
  yellowButtonState = digitalRead(yellowButton);  //버튼핀의 값을 읽어서...
  if(yellowButtonState == 0){   //값이 0(버튼이 눌러졌으면)
     digitalWrite(yellowLed,HIGH);    //yellowLed를 켜고
     playTone(NOTE_G4,100);           // 0.1초간 소리내고
     delay(100);                      // 소리날동안 기다리고
     digitalWrite(yellowLed,LOW);     // yellowLed 끄고
     delay(100);                      // 0.1초 기다린다.
  }
 greenButtonState = digitalRead(greenButton);  //버튼핀의 값을 읽어서...
  if(greenButtonState == 0){   //값이 0(버튼이 눌러졌으면)
     digitalWrite(greenLed,HIGH);    //yellowLed를 켜고
     playTone(NOTE_C5,100);           // 0.1초간 소리내고
     delay(100);                      // 소리날동안 기다리고
     digitalWrite(greenLed,LOW);     // yellowLed 끄고
     delay(100);                      // 0.1초 기다린다.
  }

//미션 1 : greenButton, NOTE_C5


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








