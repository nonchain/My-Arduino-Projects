//int soil = 7;
int soil = A0;
int led = 9;
int val = 0, light = 0;

void setup() {
  pinMode(soil, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  //val = digitalRead(soil);
  val = analogRead(soil);
  light = map(val, 30, 1023, 255, 0); 
  Serial.print("val : ");
  Serial.println(val);
  Serial.print("light : ");
  Serial.println(light);
  analogWrite(led,light);
  delay(100);

  

}
