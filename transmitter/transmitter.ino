/* Tranmsitter code for the Arduino Radio control with PWM output for motors
 * Install the NRF24 library 
 * Connect a NRF24 module to it like this:
    
    GND    ->   GND
    Vcc    ->   3.3V
    CE     ->   D9
    CSN    ->   D10
    CLK    ->   D13
    MOSI   ->   D11
    MISO   ->   D12

Please, like share and subscribe : https://www.youtube.com/Techsaw
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t my_radio_pipe = 0xE8E8F0F0E1LL; 

RF24 radio(9, 10);  

struct Data_to_be_sent {
  byte ch1;
  byte ch2;

};


Data_to_be_sent sent_data;



void setup()
{
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(my_radio_pipe);

  //Reset each channel value
  sent_data.ch1 = 127;
  sent_data.ch2 = 127;
 
}

////////////////////////////////////////////////////////////////


void loop()
{
  
  sent_data.ch1 = map( analogRead(A1), 0, 1024, 0, 255);
  sent_data.ch2 = map( analogRead(A2), 0, 1024, 0, 250);
  
;

  radio.write(&sent_data, sizeof(Data_to_be_sent));
}
