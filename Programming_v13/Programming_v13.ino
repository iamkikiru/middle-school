
#define NOTE_C4 262
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_C5 523

#define NOTE_C3 131
#define NOTE_G3 196

int redLed = 8;
int activeBuzzer = 9;
int redButton = 10;
int yellowLed = 11;
int passiveBuzzer = 12;

int redButtonState  = 1; //안눌렸을때 1


void setup() {

  // led OUTPUT 셋업
  pinMode(redLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  
  // piezoPin OUTPUT 셋업
  pinMode(activeBuzzer,OUTPUT);
  pinMode(passiveBuzzer,OUTPUT);
  
  // button INPUT_PULLUP 셋업
  pinMode(redButton,INPUT_PULLUP);

  delay(500);

}

/////////////////////////////////////////////////////////////////////////////////

void playStartMelody(){
  int startMelody[] = {NOTE_C4, NOTE_F4, NOTE_C4, NOTE_F4, NOTE_C4, NOTE_F4,
                       NOTE_C4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_G4};
  int startDuration[] = {100,   200,     100,     200,     100,      400,
                         100,   100,     100,     100,      200,     100,    500};
                       
  for(int i=0; i<13; i++){
    if(i%2 == 0 ){
      digitalWrite(redLed,HIGH);
    }
    if(i%2 == 1){
      digitalWrite(yellowLed,HIGH);
    }

    playTone(startMelody[i],startDuration[i]);
    ledOff();  
    delay(25);
  }
}

void ledOff(){
  digitalWrite(redLed,LOW);
  digitalWrite(yellowLed,LOW);
}
void ledOn(){
  digitalWrite(redLed,HIGH);
  digitalWrite(yellowLed,HIGH);
}
void playTone( int frequency , int duration){
  tone(passiveBuzzer, frequency, duration);
  delay(duration);
}

void pushButton(){
  int beeps[] = {NOTE_G3, NOTE_C3};
  int duration = 200;
  
  for(int i=0; i<3; i++){
    ledOn();
    playTone(beeps[0],duration);
    ledOff();
    playTone(beeps[1],duration);
  }
  delay(500);
}

void loop() {
  playStartMelody();

  int buttonState = 1;

  while(buttonState == 1) {
      redButtonState = digitalRead(redButton);
      if(redButtonState == 0) {
          pushButton();
          delay(1000);
          buttonState = 0;
      }
  }

}













