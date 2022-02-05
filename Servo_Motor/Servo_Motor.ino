#include <Servo.h>

int servo_value;
Servo servo1;  
void setup()
{
  Serial.begin(9600);

  servo1.attach(9);  
  servo1.write(0);
  delay(1000);
  Serial.println("Plase enter Degree= ");
  
}

void loop()
{
  while (Serial.available() > 1) {

    servo_value = Serial.parseInt();
    servo1.write(servo_value);

    Serial.print(servo_value);
    Serial.println(" Degree");
    Serial.println("Plase enter Degree = ");
    delay(5);
  }
}
