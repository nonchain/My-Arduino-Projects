#include <SoftwareSerial.h> // TX RX software library for bluetooth

#include <Servo.h> // servo library 
Servo myservo; // servo name

int bluetoothTx = 1; // bluetooth tx to 10 pin
int bluetoothRx = 0; // bluetooth rx to 11 pin
int led = 13;

//SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  myservo.attach(9); // attach servo signal wire to pin 9
  //Setup usb serial connection to computer
  Serial.begin(9600);

  pinMode(led, OUTPUT);
  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}

void loop()
{
  //Read from bluetooth and write to usb serial
  if(bluetooth.available()> 0 ) // receive number from bluetooth
  {
    

    int data = bluetooth.read();
    if(data==20){
      digitalWrite(led, HIGH);
    }else if(data==10){
      digitalWrite(led, LOW);
    }else{
      int servopos = data; // save the received number to servopos
    Serial.println(servopos); // serial print servopos current number received from bluetooth
    myservo.write(servopos); // roate the servo the angle received from the android app
    }
  }


}
