int IN1 = 7;
int IN2 = 8;
int ENA = 3;
int key1 = 11;
int key2 = 13;
int key3 = 12;

int Speed = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(key1, INPUT_PULLUP);
  pinMode(key2, INPUT_PULLUP);
  pinMode(key3, INPUT_PULLUP);
  analogWrite(ENA, 0);
  Serial.begin(9600);
}

void loop() {
  while ((digitalRead(key1) == HIGH) && (digitalRead(key2) == HIGH) && (digitalRead(key3) == HIGH) ) {
    Speed = 0;
  }
  boolean bt1 = digitalRead(key1);
  boolean bt2 = digitalRead(key2);
  boolean bt3 = digitalRead(key3);

  if (bt1 == LOW) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    if (Speed < 255) {
      Speed += 5;
      analogWrite(ENA, Speed);
      delay(90);
    }
    else if (Speed > 255) {
      Speed = 255;
      analogWrite(ENA, Speed);
    }
  } else if (bt2 == LOW) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    if (Speed < 255) {
      Speed += 5;
      analogWrite(ENA, Speed);
      delay(90);
    }
    else if (Speed > 255) {
      Speed = 255;
      analogWrite(ENA, Speed);
    }
  } 
  if (bt3 == LOW ) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    if (Speed > 5) {
      Speed = 0;
      analogWrite(ENA, Speed);
      delay(100);
    }
  }
  Serial.print("speed= ");
  Serial.println(Speed);
}
