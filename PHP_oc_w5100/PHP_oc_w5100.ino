
#include <SPI.h>
#include <Ethernet.h>
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //Setting MAC Address

bool printWebData = true;
String number ="09124416408", type="11";
String readString;

char server[] = "ketabnabb.ir";
IPAddress ip(192,168,1,11);
byte gateway[] = {192,168,1,10};
byte subnet[] = {255,255,255,0};
//byte myDns[] = {192,168,1,252};
byte myDns[] = {8,8,8,8};
EthernetClient client; 

/* Setup for Ethernet and RFID */

void setup() {
  Serial.begin(9600);
  
  Ethernet.begin(mac, ip, myDns, gateway, subnet);
  
  delay(1000);
  Serial.print("Connecting from ");
  Serial.print(ip);
  Serial.print(" to ");
  Serial.println(server);
  Serial.println();
  Ethernet.begin(mac, ip, myDns, gateway, subnet);
  //Sending_To_phpmyadmindatabase();
  //Getting_From_phpmyadmindatabase();
  //write_info();
}
//------------------------------------------------------------------------------


/* Infinite Loop */
void loop(){
  /*delay(1000);
  Serial.print("Connecting from ");
  Serial.print(ip);
  Serial.print(" to ");
  Serial.println(server);
  Serial.println();
  Ethernet.begin(mac, ip, myDns, gateway, subnet);
  Sending_To_phpmyadmindatabase();
  write_info();*/
  for(int i =0; i<8;i++) {
    Getting_From_phpmyadmindatabase();
    write_info();
    delay(500);
  }
  //delay(300000); // interval
  
}


void Getting_From_phpmyadmindatabase()   //CONNECTING WITH MYSQL
 {
   if (client.connect(server, 80)) {
   
    Serial.print("GET /files/CustomersNumber/APInumber.php?number=09124416408&type=11&token=766577452289383");
    /*Serial.print(number);
    Serial.print("&type=");
    Serial.print(type);
    Serial.print("&token=766577452289383");*/
    Serial.println(" HTTP/1.1");
    Serial.print("Host: ");
    Serial.println(server);
    Serial.println("Connection: close");
    Serial.println();
    
    client.print("GET /files/CustomersNumber/APInumber.php?number=09124416408&type=11&token=766577452289383");
    /*client.print(number);
    client.print("&type=");
    client.print(type);
    client.print("&token=766577452289383");*/
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
  
}

void write_info(){
  while (client.connected()) {
    /*int len = client.available();
    if (len > 0) {
      byte buffer[80];
      if (len > 80) len = 80;
      client.read(buffer, len);
      if (printWebData) {
        Serial.write(buffer, len);
      }
    }*/
    if(client.available()){
      char c = client.read();
      readString += c;
      
      Serial.print(c);
      if(readString.indexOf("error")>0){
         Serial.println();
         Serial.print("544");
       }
    }
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println();
    Serial.println("Disconnected");
    Serial.println();
    client.stop();
    delay(10000);
  }
}
