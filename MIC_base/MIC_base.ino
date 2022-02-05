#define MIC 6

long int mic_v = 0;


void setup() {
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 //pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(MIC, INPUT);

 Serial.begin(9600);
}

void loop() {

  mic_v = digitalRead(MIC);
  Serial.println(mic_v);

  if(mic_v==0){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    //digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
  else {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    //digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }

}
