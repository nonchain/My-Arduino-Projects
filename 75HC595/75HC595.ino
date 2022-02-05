int DS_pin = 8;
int STCP_pin = 9;
int SHCP_pin = 10;


void setup() {
  pinMode(DS_pin, OUTPUT);
  pinMode(STCP_pin, OUTPUT);
  pinMode(SHCP_pin, OUTPUT);

  Serial.begin(9600);
  writeing();
}

boolean registers[8];

void writeing(){
  digitalWrite(SHCP_pin, LOW);

  for(int i=7; i>=0; i--){
    digitalWrite(STCP_pin, LOW);
    digitalWrite(DS_pin, registers[i]);
    digitalWrite(STCP_pin, HIGH);
  }
  digitalWrite(SHCP_pin, HIGH);
}

void loop() {
  Serial.println("Start...");
  delay(1000);
  //ON
  for(int i = 0 ; i<8; i++){
    registers[i]=HIGH;
    delay(100);
    writeing();
    Serial.print("i : ");
    Serial.println(i);
  }
  //OFF
  for(int i = 0; i<8; i++){
    registers[i]=LOW;
    delay(100);
    writeing();
    Serial.print("i : ");
    Serial.println(i);
  }

}
