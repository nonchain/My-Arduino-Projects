int music  = A0;
int output,a;
int pot=A1;
int number_of_led[3] = { 11,7,4}; // Assign the pins for the leds
void setup()
{
for (a = 0; a < 3; a++)  
  pinMode(number_of_led[a], OUTPUT);

Serial.begin(9600);
}

void loop()
{
//pot=analogRead(A1);
output = analogRead(music);
//pot=map (potval,0,1024,5,40);
//output = output/potval;   
Serial.println(output);

  if (output == 0) 
   {
   for(a = 0; a < 3; a++)
     {
     digitalWrite(number_of_led[a], LOW);
     }
  }
  
  else
  {
   for (a = 0; a < output; a++)
    {
     digitalWrite(number_of_led[a], HIGH);
    }
    
    for(a = a; a < 3; a++) 
     {
      digitalWrite(number_of_led[a], LOW);
    
     }
  }
}
