
#include <SPI.h>
#include <Ethernet.h>
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //Setting MAC Address


int num = 123;


char server[] = "195.201.172.7";
//IPAddress ip(195,201,172,177);
//IPAddress ip(172,217,3,110); // Google
EthernetClient client; 

/* Setup for Ethernet and RFID */

void setup() {
  Serial.begin(9600);
  
  if (Ethernet.begin(mac) == 0) {
  Serial.println("Failed to configure Ethernet using DHCP");
  Ethernet.begin(mac);
  }
  delay(1000);
  Serial.println("connecting...");
  Serial.print("Server is at : ");
  Serial.println(Ethernet.localIP());
  Sending_To_phpmyadmindatabase(); 
}
//------------------------------------------------------------------------------


/* Infinite Loop */
void loop(){
  //Sending_To_phpmyadmindatabase(); 
  //delay(300000); // interval
}


  void Sending_To_phpmyadmindatabase()   //CONNECTING WITH MYSQL
 {
   if (client.connect(server, 80)) {
   
    Serial.println("connected");
    // Make a HTTP request:
    Serial.println("GET /files/CustomersNumber/?number=56 HTTP/1.1");
    client.println("GET /files/CustomersNumber/?number=56 HTTP/1.1");   //YOUR URL
    //Serial.println("GET /view.php HTTP/1.1");
    //client.println("GET /view.php HTTP/1.1");   //YOUR URL
    client.println("Host: 195.201.172.7");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
 }
