#include <ESPmDNS.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "Agent47";
const char* password =  "kazemi1544@1544";

AsyncWebServer server(80);

void setup(){
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  if(!MDNS.begin("esp32")) {
     Serial.println("Error starting mDNS");
     return;
  }
  
  Serial.println(WiFi.localIP());
  
  server.on("/hello", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello World");
  });
  
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

}
