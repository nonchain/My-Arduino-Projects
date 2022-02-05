/* Driver L298 */
const int ENA = 5;
const int ENB = 6;
const int IN1 = 10;
const int IN2 = 11;
const int IN3 = 12;
const int IN4 = 13;
const int led_go = 7;
const int led_stop = 8;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(led_go, OUTPUT);
  pinMode(led_stop, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int Speed = 0;
  while (Serial.available() > 1) {

    Speed = Serial.parseInt();
    Serial.println(Speed);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, Speed);
    analogWrite(ENB, Speed);
  }
  
    
}
