#include "pitches.h"

int notes[] = {NOTE_G4, NOTE_G4, NOTE_G4, NOTE_DS4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_D4};
int Time[] = {4,4,4,1,4,4,4,1};

int mobile_notes[]={NOTE_C4, NOTE_DS4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_F4, NOTE_DS4};
int mobile_durations[]={8,8,4,8,8,8,8,16,16,2}; // 4= Note Siah   8= Note Chang

int sensor;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensor = analogRead(A0);
  Serial.print("Sensor value = ");
  Serial.println(sensor);

  if(sensor<200){
    Piano();
    delay(500);
  }else{
    mobile();
    delay(500);
  }

}

void Piano(){
  int i;
  for(i=0; i<8; i++){
    int T = 1000/Time[i];
    tone(11, notes[i], T);

    int performance = T * 1.5;
    delay(performance);
  }
}

void mobile(){
 
 for( int thisNote=0; thisNote < 10; thisNote++){
  int mobile_duration = 1000/mobile_durations[thisNote];
  tone(11, mobile_notes[thisNote],mobile_duration);
 
 //Ta'Ayiine Meghdare Tempo Ahang
int pauseBetweenNotes = mobile_duration * 1.43;
delay(pauseBetweenNotes);
 }
}
