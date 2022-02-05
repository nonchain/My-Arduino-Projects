const int n = 20;
int m = 1;
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
const int IN1 = 7;
const int IN2 = 8;
const int ENA = 3;
int xpin = A0;
int ypin = A2;
int sw = A4;
boolean Status = 1, key;

int Speed = 0;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(sw, INPUT);
  analogWrite(ENA, 0);
}

void loop() {
  vrx = VRX();
  vry = VRY();
  vrx *= 2;
  // delay(200);

  if (vrx > 501) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    Speed = map(vrx, 498, 1022, 0, 255);
    analogWrite(ENA, Speed*m);
  } else if (vrx < 497) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    Speed = map(vrx, 498, 0, 0, 255);
    analogWrite(ENA, Speed);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
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
