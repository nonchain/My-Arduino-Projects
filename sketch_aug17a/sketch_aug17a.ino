#include <SoftwareSerial.h>
SoftwareSerial Blue(2, 3);
long int data;
 
int LED = 13; // Led connected
long int password1 = 92;// light on
long int password2 = 79; // light off
 
char state = 0;
 
 
void setup()
{
   
pinMode(LED, OUTPUT); 
digitalWrite(LED, LOW);
Serial.begin(9600);
Blue.begin(9600);
 
}
 
void loop()
{
 
  while(Blue.available()==1) ;
 
 if(Blue.available()>1) 
{
data = Blue.parseInt();
 
} 
delay(100);
//Serial.print(data);
 
if (data == password1)
{
  
  digitalWrite(LED,HIGH);
  Serial.println("LED ON ");
  
   }
   
   if( data == password2)
   {
       digitalWrite(LED,LOW);
  Serial.println("LED OFF");
   }
 
 }
