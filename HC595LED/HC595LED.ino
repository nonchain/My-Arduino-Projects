
/*
 * Same as HC595Test, but with leds
 */
#include <HC595.h>

const int chipCount = 1;  // Number of serialy connected 74HC595 (8 maximum)
const int latchPin = 9;  // Pin ST_CP (12) of the 74HC595
const int clockPin = 10;  // Pin SH_CP (11) of the 74HC595
const int dataPin = 8;   // Pin DS (14) of the 74HC595
int mic = 6;
boolean sig = 0;

//Constructor
HC595 ledArray(chipCount,latchPin,clockPin,dataPin);

int delayMs = 100;
int lastPin = ledArray.lastPin();

void setup() {
  ledArray.reset();
  pinMode(mic, INPUT);
  Serial.begin(9600);
}

void loop() {

  sig = digitalRead(mic);
  
  Serial.println(sig);
  if(sig==0){
    /*for (int i = 0 ; i <= lastPin ; i++) {
      ledArray.setPin(i, ON);
      //delay(delayMs);
    }*/
    //delay(1000);
    ledArray.setPin(0, ON);
    ledArray.setPin(1, ON);
    ledArray.setPin(2, ON);
    ledArray.setPin(3, ON);
    ledArray.setPin(4, ON);
    ledArray.setPin(5, ON);
    ledArray.setPin(6, ON);
    ledArray.setPin(7, ON);
  }else{
    /*for (int i = lastPin ; i >=0 ; i--) {
      ledArray.setPin(i, OFF);
      //delay(delayMs);
    }*/
    //delay(1000);
    ledArray.setPin(0, OFF);
    ledArray.setPin(1, OFF);
    ledArray.setPin(2, OFF);
    ledArray.setPin(3, OFF);
    ledArray.setPin(4, OFF);
    ledArray.setPin(5, OFF);
    ledArray.setPin(6, OFF);
    ledArray.setPin(7, OFF);
  }
  /*for (int i = 0 ; i <= lastPin ; i++) {
    ledArray.setPin(i, TOGGLE);
    delay(delayMs);
  }
  for (int i = 0 ; i <= lastPin ; i++) {
    ledArray.setPin(i, TOGGLE);
    delay(delayMs);
  }*/
}
