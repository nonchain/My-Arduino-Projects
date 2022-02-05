const int numReadings = 10;        // More is better but has delay

int vry_readings[numReadings];      // the readings from the analog input
int vry_readIndex = 0;              // the index of the current reading
int vry_total = 0;                  // the running total
int vry_average = 0;                // the average

int vrx_readings[numReadings];      // the readings from the analog input
int vrx_readIndex = 0;              // the index of the current reading
int vrx_total = 0;                  // the running total
int vrx_average = 0;                // the average

boolean select=1,key;

int vry_value;
int vrx_value;


const int vry_pin = A2;
const int vrx_pin = A0;
const int sw = A4;

const int led1 = 10;
const int led2 = 11;
const int led3 = 9;

void setup() {
  Serial.begin(9600);
 pinMode(sw,INPUT);
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(led3,OUTPUT);
 
   for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    vry_readings[thisReading] = 0;
    vrx_readings[thisReading] = 0;} 
}

void loop() {

  sw_reading();
  vry_reading();
  vrx_reading();

if(vry_average > 530){
  vry_value = vry_average;
  vry_value = map(vry_value, 530, 1023, 0, 255);
  analogWrite(led2,vry_value); //PWM
}
else{
  vry_value = vry_average;
  vry_value = map(vry_value, 530, 0, 0, 255);
    analogWrite(led2,vry_value);}

    
if(vrx_average > 500){
  vrx_value =vrx_average;
  vrx_value = map(vrx_value, 500, 1023, 0, 255);
  analogWrite(led1,vrx_value);
}
else{
  vrx_value = vrx_average;
  vrx_value = map(vrx_value, 515, 0, 0, 255);
    analogWrite(led1,vrx_value);}    

Serial.print("vrx=");
Serial.print(vrx_average);
Serial.print(" vry=");
Serial.print(vry_average);
Serial.print(" key=");
Serial.println(select);

delay(100);

}

void sw_reading(){
  
   if( digitalRead(sw) == 0){
   delay(300); // for debuncing
   select ^= 1;
     }   
 
   if(select == 1){
    digitalWrite(led3,HIGH);
    }
  
    else{
      digitalWrite(led3,LOW);
      }  
    }


int vry_reading(){
    // subtract the last reading:
  vry_total = vry_total - vry_readings[vry_readIndex];
  // read from the sensor:
  vry_readings[vry_readIndex] = analogRead(vry_pin);
  // add the reading to the total:
  vry_total = vry_total + vry_readings[vry_readIndex];
  // advance to the next position in the array:
  vry_readIndex += 1;

  // if we're at the end of the array...
  if (vry_readIndex >= numReadings) {
    // ...wrap around to the beginning:
    vry_readIndex = 0;
  }

  // calculate the average:
  vry_average = vry_total / numReadings;
  
  return(vry_average); 
}


int vrx_reading(){
  
    // subtract the last reading:
  vrx_total = vrx_total - vrx_readings[vrx_readIndex];
  // read from the sensor:
  vrx_readings[vrx_readIndex] = analogRead(vrx_pin);
  // add the reading to the total:
  vrx_total = vrx_total + vrx_readings[vrx_readIndex];
  // advance to the next position in the array:
  vrx_readIndex = vrx_readIndex + 1;

  // if we're at the end of the array...
  if (vrx_readIndex >= numReadings) {
    // ...wrap around to the beginning:
    vrx_readIndex = 0;
  }

  // calculate the average:
  vrx_average = vrx_total / numReadings;
  
  return(vrx_average); 
}
