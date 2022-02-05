const int lamp = 8;


void setup() {
  Serial.begin(9600);
  pinMode(lamp , OUTPUT);

}

void loop() {
  int c = analogRead(A0);
  Serial.println(c);
  delay(100);
if ( c<80 ){
  digitalWrite(8,HIGH);
   

}
else{

digitalWrite(8,LOW);

}
}
