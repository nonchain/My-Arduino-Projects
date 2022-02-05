int led = 13;

void setup() {
  pinMode(led,OUTPUT);

}

void loop() {
  digitalWrite(led, HIGH);
  delay(1500);
  digitalWrite(led, LOW);
  delay(400);

}
