int led = 9;
int i = 0;

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  delay(500);
  while(i != 255){
    analogWrite(led, i);
    delay(20);
    i++;
  }
  while(i >= 10){
    analogWrite(led, i);
    delay(20);
    i--;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
