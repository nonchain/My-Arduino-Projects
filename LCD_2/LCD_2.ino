#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 11, 2, 3, 5, 7); //(RS,E,D4,D5,D6,D7)

int i, j;
int sensor;

void setup() {
  lcd.begin(16, 2); //(X,Y)
  Serial.begin(9600);

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
  sensor = analogRead(A0);
  lcd.print("Sensor = ");
  lcd.print(sensor);
  delay(900);
  lcd.clear();
}
