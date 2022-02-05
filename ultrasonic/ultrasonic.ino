int trig = 12;
int echo = 8;
int led = 10;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long T, cm;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  T = pulseIn(echo, HIGH);
  cm = lenth(T);

  if(cm<20){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
  
  Serial.print(cm);
  Serial.println("cm");
  delay(300);
}

unsigned long lenth(unsigned long x)
{
  return (x/29)/2;
}
