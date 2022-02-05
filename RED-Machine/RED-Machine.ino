int ENB = 9;
int IN3 = 10;
int IN4 = 11;

int s2 = 2;
int s3 = 3; 
boolean sens2,sens3;

void setup() {
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  Serial.begin(9600);
  
}

void loop() {
 sens2 = digitalRead(s2);
 /*sens3 = digitalRead(s3);*/

 if(sens2){
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 150);
 } else {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, LOW);
 }

  Serial.print("s1= ");
  Serial.print(sens2);
  Serial.print(" s2= ");
  Serial.println(sens3);
  delay(100);
}
