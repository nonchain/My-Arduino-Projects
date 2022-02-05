#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 11, 2, 3, 5, 7); //(RS,E,D4,D5,D6,D7)

int i, j;
float temp, adc;

void setup() {
  lcd.begin(16, 2); //(X,Y)
  Serial.begin(9600);
  analogReference(DEFAULT);   //Vref = 5V
  //analogReference(INTERNAL);    //Vref = 1.1V

  lcd.clear();
  delay(1200);
  lcd.print("Scanning");
  for (j = 0; j <3; j++) {
    for (i = 0; i <4; i++) {
      delay(550);
      lcd.print(".");
    }
    lcd.clear();
    lcd.print("Scanning");
  }
  lcd.print("...");
  delay(150);
  lcd.clear();
}


void loop() {
  adc = analogRead(A2);  
  temp = (4.8*adc)/10;     //Vref = 5V
  //tc = (1.07*adc)/10;  //Vref = 1.1V
  lcd.setCursor(0,1);
  lcd.print("Temp : ");
  lcd.print(temp);

  delay(1000);
  lcd.clear();
}
