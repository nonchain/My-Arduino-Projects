#include <SoftwareSerial.h>
SoftwareSerial Blue(2, 3); //(TX, RX)
long int data;

int relay_1 = 5;
int relay_2 = 6;
int relay_3 = 7;

char state = 0;

void setup() {
  Serial.begin(9600);
  Blue.begin(9600);
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(relay_3, OUTPUT);
  digitalWrite(relay_1, HIGH);
  digitalWrite(relay_2, HIGH);
  digitalWrite(relay_3, HIGH);
}

void loop() {
  while(Blue.available()==1||Blue.available()==0) ;
 
 while(Blue.available()>1||Blue.available()>0) 
  {
    data = Blue.parseInt();
    //value = data;
  } 
  delay(5);
  Serial.println(data);
  if(data==1){
    digitalWrite(relay_1, LOW);
    return;
    
  }
  else if(data==2){
    digitalWrite(relay_2, LOW);
    return;
    
  }
  else if(data==3){
    digitalWrite(relay_3, LOW);
    return;
  }
  else if(data==4){
    digitalWrite(relay_1, HIGH);
    return;
    
  }
  else if(data==5){
    digitalWrite(relay_2, HIGH);
    return;
    
  }
  else if(data==6){
    digitalWrite(relay_3, HIGH);
    return;
    
  }

}
