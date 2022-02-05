float tc ;
float adc;

void setup() {
  Serial.begin(9600);
  analogReference(DEFAULT);   //Vref = 5V
  //analogReference(INTERNAL);    //Vref = 1.1V
}

void loop() {
  adc = analogRead(A0);  
  tc = (4.8*adc)/10;     //Vref = 5V
  //tc = (1.07*adc)/10;  //Vref = 1.1V
  Serial.println(tc);

  delay(500);
}
