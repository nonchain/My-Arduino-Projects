int L1 = 2;
int L2 = 4;
int L3 = 6;
int L4 = 8;

#define Mic A0


void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(Mic, INPUT);

  Serial.begin(9600);
}

void loop() {
  int sig = analogRead(Mic)*50;
  Serial.println(sig);

  if(sig>1){digitalWrite(L1, HIGH);}else{digitalWrite(L1, LOW);};
  if(sig>300){digitalWrite(L2, HIGH);}else{digitalWrite(L2, LOW);};
  if(sig>680){digitalWrite(L3, HIGH);}else{digitalWrite(L3, LOW);};
  if(sig>950){digitalWrite(L4, HIGH);}else{digitalWrite(L4, LOW);};

}
