int led = 7;
int mic = 8;
bool sig = 0;

void setup() {
  pinMode(mic, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  sig = digitalRead(mic);

  if(sig==0){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }

}
