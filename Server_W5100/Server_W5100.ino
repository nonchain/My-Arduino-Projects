#include <SPI.h>
#include <Ethernet.h>

int led = 8; 
String readString;
EthernetServer server(80);
//IPAddress ip(192, 168, 0, 177);

#if defined(WIZ550io_WITH_MACADDRESS) // Use assigned MAC address of WIZ550io
;
#else
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
#endif  
 
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  Ethernet.begin(mac);
  server.begin();
  Serial.print("Server is at :");
  Serial.println(Ethernet.localIP());
}
 
void loop() {
 EthernetClient client = server.available();

 if(client){
  while(client.connected()){
    if(client.available()){
      char c = client.read();
      Serial.print(c);
    
      if(readString.length()<100){
        readString += c;
      }
      if(c == '\n'){
        Serial.print(readString);
        client.println("<HTTP/1.1 200 OK>");
        client.println("<Content-Type: text/html>");
        client.println("<Connection: close>");
        client.println();

        client.println("<!DOCTYPE html>");
        client.println("<html>");
        client.println("<head>");
        client.println("<title>web server </title>");
        client.println("</head>");
        client.println("<body>");
        client.println("<a href=\"/?button1on\"\"><button>LED ON</button></a>");
        client.println("<a href=\"/?button2off\"\"><button>LED OFF</button></a>");
        client.println("</br>");
        client.println("<form action = \"\" method = \"\" >");
        client.println("</br>");
        client.println("<input type = \"text\" name = \"\" >");
        client.println("<body style=background-color:blue>");
        client.println("</body>");
        client.println("</html>");

        delay(1);
        client.stop();

        if(readString.indexOf("?button1on")>0){
          digitalWrite(led, HIGH);
        }
        if(readString.indexOf("?button2off")>0){
          digitalWrite(led, LOW);
        }
        readString = "";
        }
      }
    }
  }
}
