int Red = 3;
int Green = 5;
int Blue = 6;

int i=0, redValue=255, blueValue=255, greenValue=255;

void setup() {
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
  Serial.begin(9600);

}

void loop() {
   while(redValue > 1||greenValue > 1||blueValue > 1){
    setColor(redValue, greenValue, blueValue);
    if(redValue > 0){
      redValue-=6;
    }
    
    if(greenValue > 0){
      greenValue-=8;
    }
    
    if(blueValue > 0){
      blueValue-=4;
    }
    /*Serial.print("RED: ");
    Serial.println(redValue);
    Serial.print("GREEN: ");
    Serial.println(greenValue);
    Serial.print("BLUE: ");
    Serial.println(blueValue);*/
    delay(100);
    //delay(1000);
   }
   redValue=255; blueValue=255; greenValue=255;
   /*Serial.print("RED: ");
   Serial.println(redValue);
   while(greenValue != 0){
    setColor(redValue, greenValue, blueValue);
    greenValue--;
    delay(20);
   }
   
   Serial.print("GREEN: ");
   Serial.println(greenValue);
   while(blueValue != 0){
    setColor(redValue, greenValue, blueValue);
    blueValue--;
    delay(20);
    
   }
   
   Serial.print("BLUE: ");
   Serial.println(blueValue);
   delay(500);
   redValue=255; blueValue=255; greenValue=255;
   Serial.print("RED: ");
   Serial.println(redValue);
   delay(500);*/
  
}

void setColor(int a, int b, int c){
   analogWrite(Red, a);
   analogWrite(Green, b);
   analogWrite(Blue, c);
}
