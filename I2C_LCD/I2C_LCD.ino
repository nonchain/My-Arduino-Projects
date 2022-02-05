#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int j, i=0;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup()
{
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello!");
  delay(250);
  lcd.clear();
  for(j = 1; j<=100; j++){
  lcd.setCursor(6,1);
  lcd.print("%");
  lcd.print(j);
  delay(50);
  lcd.clear();
  i=j;
  }
  lcd.setCursor(6,1);
  lcd.print("%");
  lcd.print(i);
  delay(150);
  lcd.clear();
  lcd.setCursor(6,1);
  lcd.print("DONE");
}

void loop()
{
  
}
