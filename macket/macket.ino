const int n = 20;
int index = 0;
/* For VRX */
int vrxArray[n] = {0};
int vrxTotal = 0;
int vrxAvrage = 0;
int vrx = 0;
/*For VRY */
int vryArray[n] = {0};
int vryTotal = 0;
int vryAvrage = 0;
int vry = 0;
/* Pin Names */
const int IN3 = 11;
const int IN4 = 10;
const int ENB = 9;
int xpin = A0;
int ypin = A2;
int sw = A4;
boolean Status = 1, key;

int Speed = 0;
void setup() {
  Serial.begin(9600);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(sw, INPUT);
  analogWrite(ENB, 0);

}

void loop() {
  vrx = VRX();
  vry = VRY();
  vrx *= 2;

  if (vrx > 520) {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Speed = map(vrx, 514, 1022, 0, 255);
    analogWrite(ENB, Speed);
  } else if (vrx < 510) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Speed = map(vrx, 514, 0, 0, 255);
    analogWrite(ENB, Speed);
  } else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    Speed = 0;
  }

  Serial.print("X=");
  Serial.print(vrx);
  Serial.print(" Y=");
  Serial.print(vry * 2);
  Serial.print(" speed=");
  Serial.println(Speed);
  delay(90);

}

int VRX() {
  vrxTotal -= vrxArray[index];
  vrxArray[index] = analogRead(xpin);
  vrxTotal += vrxArray[index];
  index += 1;

  if (index >= n) {
    index = 0;
  }

  return (vrxTotal / n);
}

int VRY() {
  vryTotal -= vryArray[index];
  vryArray[index] = analogRead(ypin);
  vryTotal += vryArray[index];
  index += 1;

  if (index >= n) {
    index = 0;
  }

  return (vryTotal / n);
}
