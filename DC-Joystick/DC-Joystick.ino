int vrx = 0;
int vry = 0;

const int vrxpin = A0;
const int vrypin = A2;
const int sw = A4;
int IN1 = 7;
int IN2 = 8;
int ENA = 9;

int Speed = 0;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(sw, INPUT);
  analogWrite(ENA, 0);
}
void loop() {

  boolean key = digitalRead(sw);
  vrx = analogRead(vrxpin);
  vry = analogRead(vrypin);

  /*while (vrx > 47) {
    Speed = 0;
    }*/

  if (vrx > 501) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    Speed = map(vrx, 501, 1022, 0, 255);
      analogWrite(ENA, Speed);
    }
  
  else if (vrx < 495) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    Speed = map(vrx, 499, 0, 255, 0);
      analogWrite(ENA, Speed);
    }
     if (Speed == 0) {
      Speed = 0;
      analogWrite(ENA, Speed);
    }
  
  else if (key == LOW) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    if (Speed > 5) {
      Speed = 0;
      analogWrite(ENA, Speed);
      delay(100);
    }
  }
  Serial.print("(X=");
  Serial.print(vrx);
  Serial.print(" Y=");
  Serial.print(vry);
  Serial.print(" key=");
  Serial.print(key);
  /*Serial.print(" Xspeed=");
  Serial.print(x);*/
  Serial.print(" speed= ");
  Serial.println(Speed);
  delay(200);
}
