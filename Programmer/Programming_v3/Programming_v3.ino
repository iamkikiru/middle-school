
#define NOTE_C4 262
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_C5 523

#define NOTE_C3 131
#define NOTE_G3 196

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

void playStartMelody(){
  int startMelody[] = {NOTE_C4, NOTE_F4, NOTE_C4, NOTE_F4, NOTE_C4, NOTE_F4,
                     NOTE_C4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_G4};
  int startDuration[] = {100,   200,     100,     200,     100,      400,
                       100,   100,     100,     100,      200,     100,    500};
                       
  for(int i=0; i<13; i++){
    if(i%2 == 0 ){
      digitalWrite(yellowLed,HIGH);
    }
    if(i%2 == 1){
      digitalWrite(greenLed,HIGH);
    }

    playTone(startMelody[i],startDuration[i]);
    ledOff();  
    delay(25);
  }
}

void ledOff(){
  digitalWrite(yellowLed,LOW);
  digitalWrite(greenLed,LOW);
}
void ledOn(){
  digitalWrite(yellowLed,HIGH);
  digitalWrite(greenLed,HIGH);
}
void playTone( int frequency , int duration){
  tone(piezoPin, frequency, duration);
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
      yellowButtonState = digitalRead(yellowButton);
      greenButtonState = digitalRead(greenButton);
      if(yellowButtonState == 0 || greenButtonState == 0) {
          pushButton();
          delay(1000);
          buttonState = 0;
      }
  }

}













