int sensor;
int led = 9;
int bottun = 7;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(bottun, INPUT);
}

void loop() {
  while (digitalRead(bottun) == LOW) {
    sensor = analogRead(A0);

    Serial.print("Sensor value = ");
    Serial.println(sensor);
    delay(300);

    if (sensor < 200) {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
  }
}
