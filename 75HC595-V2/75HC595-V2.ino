
/*
 * Same as HC595Test, but with leds
 */
#include <HC595.h>

const int chipCount = 1;  // Number of serialy connected 74HC595 (8 maximum)
const int latchPin = 9;  // Pin ST_CP (12) of the 74HC595
const int clockPin = 10;  // Pin SH_CP (11) of the 74HC595
const int dataPin = 8;   // Pin DS (14) of the 74HC595
int mic = A0;
int sig01;
int sig02;
float max_sig = 3.5;

//Constructor
HC595 ledArray(chipCount,latchPin,clockPin,dataPin);

int delayMs = 20;
int lastPin = ledArray.lastPin();

void setup() {
  ledArray.reset();
  pinMode(mic, INPUT);
  Serial.begin(9600);
}

void loop() {

  sig01 = analogRead(mic);
  delay(1);
  sig02 = analogRead(mic);
  
  Serial.println(sig01);
  if(sig01-sig02>=max_sig){
    
    ledArray.setPin(0, ON);
    ledArray.setPin(1, ON);
    delay(delayMs);
    
  }else{
    
    //ledArray.setPin(0, OFF);
    ledArray.setPin(1, OFF);
    
  }
  //**//
  if(sig01-sig02>=max_sig+2){
    
    /*ledArray.setPin(0, ON);
    ledArray.setPin(1, ON);*/
    ledArray.setPin(2, ON);
    ledArray.setPin(3, ON);
    ledArray.setPin(4, ON);
    delay(delayMs);
    
  }else{
    
    /*ledArray.setPin(0, OFF);
    ledArray.setPin(1, OFF);*/
    ledArray.setPin(2, OFF);
    ledArray.setPin(3, OFF);
    ledArray.setPin(4, OFF);
    
  }
  //**//
  if(sig01-sig02>max_sig+4){
    
    /*ledArray.setPin(0, ON);
    ledArray.setPin(1, ON);
    ledArray.setPin(2, ON);
    ledArray.setPin(3, ON);
    ledArray.setPin(4, ON);*/
    ledArray.setPin(5, ON);
    ledArray.setPin(6, ON);
    ledArray.setPin(7, ON);
    delay(delayMs);
    
  }else{
    
    /*ledArray.setPin(0, OFF);
    ledArray.setPin(1, OFF);
    ledArray.setPin(2, OFF);
    ledArray.setPin(3, OFF);
    ledArray.setPin(4, OFF);*/
    ledArray.setPin(5, OFF);
    ledArray.setPin(6, OFF);
    ledArray.setPin(7, OFF);
    
  }
  
}
