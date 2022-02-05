int led = 13;
int state = 0;
int flag = 0;


void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.begin(9600);
}

void loop() {
  //digitalWrite(led, HIGH);
  if(Serial.available()>0){
    state = Serial.read();
    flag=0;
  }
  if(state == '0'){
    digitalWrite(led, LOW);
    Serial.println("LED IS OFF");
    flag=1;
  }
  else if(state == '1'){
    digitalWrite(led, HIGH);
    Serial.println("LED IS ON");
    flag=1;
  }
}
