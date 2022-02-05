#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);

int led = 2;
int state = 0;
int flag = 0;


void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  
  Serial.begin(9600);
  
  lcd.begin();
  lcd.setCursor(3,0);
  lcd.print("LED IS OFF");
  lcd.backlight();
}

void loop() {
  //digitalWrite(led, HIGH);
  if(Serial.available()>0){
    state = Serial.read();
    flag=0;
  }
  if(state == '0'){
    digitalWrite(led, LOW);
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("LED IS OFF");
    Serial.println("LED IS OFF");
    flag=1;
  }
  else if(state == '1'){
    digitalWrite(led, HIGH);
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("LED IS ON");
    Serial.println("LED IS ON");
    flag=1;
  }
}
