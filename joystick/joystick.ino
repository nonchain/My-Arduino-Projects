int vrx = 0;
int vry = 0;

const int led1 = 2;
const int led2 = 4;
const int vrxpin = A0;
const int vrypin = A2;
const int sw = A4;

void setup() {
  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sw, INPUT);

}

void loop() {
  boolean key = digitalRead(sw);
  vrx = analogRead(vrxpin);
  vry = analogRead(vrypin);

 /* vrx = analogRead(vrxpin);
  vry = analogRead(vrypin);*/

  Serial.print("(X=");
  Serial.print(vrx);
  Serial.print(" Y=");
  Serial.print(vry);
  Serial.print(" key=");
  Serial.println(key);

  delay(200);

  if (vrx < 15) {
    digitalWrite(led1, HIGH);
  } else if (vry > 90) {
    digitalWrite(led2, HIGH);
  } else if (key == 0) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
}
