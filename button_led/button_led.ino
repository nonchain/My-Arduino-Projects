
int green = 9;
int yellow = 11;
int red = 13;
int bottun = 7;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(bottun, INPUT);
}


void loop() {
  int i;
  while (digitalRead(bottun) == LOW){
    digitalWrite(green, HIGH);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, HIGH);
  }

 for (i = 13; i >8 ; i-=2) {
    if (i == 13) {
      digitalWrite(green, HIGH);
      delay(500);
      digitalWrite(green, LOW);
    } else if (i == 11) {
      digitalWrite(yellow, HIGH);
      delay(500);
      digitalWrite(yellow, LOW);
    } else {
      digitalWrite(red, HIGH);
      delay(500);
      digitalWrite(red, LOW);
    }
  }
}
