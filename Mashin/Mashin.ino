/* Driver L298 */
const int ENA = 5;
const int ENB = 9;
const int IN1 = 12;
const int IN2 = 13;
const int IN3 = 10;
const int IN4 = 11;
const int led = 7;
/* Joystick */
const int n = 20;
int vrx, vry;
const int xpin = A0;
const int ypin = A2;
const int sw = A4;
int index = 0;
boolean Status = 0;
/* For VRX */
int vrxArray[n] = {0};
int vrxTotal = 0;
int vrxAvrage = 0;
/*For VRY */
int vryArray[n] = {0};
int vryTotal = 0;
int vryAvrage = 0;
/**/


void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(sw, INPUT);
  Serial.begin(9600);
}

void loop() {
  int Speed = 0;
  vrx = VRX();
  vrx *= 2;
  SW();

  if (vrx > 520) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    Speed = map(vrx, 514, 1022, 0, 255);
    analogWrite(ENA, Speed);
    analogWrite(ENB, Speed);
  }

  else if (vrx < 500) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    Speed = map(vrx, 514, 0, 0, 255);
    analogWrite(ENA, Speed);
    analogWrite(ENB, Speed);
  }

  Serial.print("X=");
  Serial.print(vrx);
  Serial.print(" Speed=");
  Serial.print(Speed);
  Serial.print(" Status=");
  Serial.println(Status);
  delay(100);
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

void SW() {
  boolean key = digitalRead(sw);
  if ( key == 0) {
    delay(300); // for debuncing
    Status ^= 1;
  }
  if (Status == 1) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}
