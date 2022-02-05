#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <Ethernet.h>

int s=0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

char number[5];
String num, num2;

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {2, 3, 5, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 8, 9}; //connect to the column pinouts of the keypad

EthernetServer server(80);
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  
  Serial.begin(9600);
  lcd.begin();
  Serial.println("Robojax 4x3 keypad");
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Number :");
  lcd.setCursor(0, 1);
  
  //delay(1050);
  //lcd.clear();

}

void loop() {
  // Robojax 4x3 keypad test
  char key = keypad.getKey();
    // just print the pressed key
  if(s<10){
   if (key){
    //lcd.setCursor(0, 1);
    Serial.println(key);
    lcd.print(key);
    number[s]=key;
    s++;
    if(key!='*'){
      num2 += key;
    }
  } 
 }
   // this checkes if 4 is pressed, then do something. Here  we print the text but you can control something.
  if (key =='*'){
    // if key matches what you are looking for
    /*lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Number :");
    lcd.setCursor(0, 1);*/
    lcd.clear();
    Serial.print("array :");
    for(int z=0; z<5; z++){
      lcd.print(number[z]);
      Serial.print(number[z]);
      
    }
    Serial.println();
    lcd.setCursor(0, 1);
    lcd.print(num2);
    Serial.print("num2 :");
    Serial.println(num2);
  }
  if (key =='#'){
    // if key matches what you are looking for
    sendData();
    delay(150);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("OK");
    
  }
  
}

void sendData(){
  lcd.clear();
  lcd.setCursor(0, 0);
  for(int j=0; j<3; j++){
    lcd.print("Sending");
    for(int i=8; i<11; i++){
      lcd.setCursor(i, 0);
      lcd.print(".");
      delay(250);
    }
    delay(300);
    lcd.clear();
  }
  
}
