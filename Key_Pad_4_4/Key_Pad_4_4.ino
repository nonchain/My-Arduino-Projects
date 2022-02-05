M#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int s=0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

char number[5];

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 5, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 8, 9, 10}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  
  Serial.begin(9600);
  
  Serial.println("Robojax 4x4 keypad");
}

void loop() {
  // Robojax 4x4 keypad test
  char key = keypad.getKey();
    // just print the pressed key
   if (key){
   
    Serial.print(key);
    Serial.print(" ");
    
  } 
}
