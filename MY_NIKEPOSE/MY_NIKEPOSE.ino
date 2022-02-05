// Ethernet
#include <SPI.h>
#include <Ethernet.h>
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //Setting MAC Address 
// I2C_LCD
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
// KeyPad
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {2, 3, 5, 6}; 
byte colPins[COLS] = {7, 8, 9}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

bool printWebData = true, sent_ = false, tok = false;
int s=0, t=0, j, i;
String number, type;
String readString;

// Set Ethernet Address
char server[] = "ketabnabb.ir";
IPAddress ip(192,168,1,17);
byte gateway[] = {192,168,1,1};
byte subnet[] = {255,255,255,0};
byte myDns[] = {8,8,8,8}; //Google
EthernetClient client;

void setup() {
  // LCD
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  delay(1000);
  // Ethernet
  Serial.print("Connecting from ");
  Serial.print(ip);
  Serial.print(" to ");
  Serial.println(server);
  Serial.println();
  Ethernet.begin(mac, ip, myDns, gateway, subnet);
  load_func();
  
}

void loop(){
  if(!sent_){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Number :");
    lcd.setCursor(0, 1);
    sent_=true;
  }
  else{
    getData();
  }
  
}

void getData(){
  char key = keypad.getKey();
    // just print the pressed key
 
  if(s<11){
    if (key){
    //lcd.setCursor(0, 1);
    lcd.print(key);
    s++;
     if(key!='*' || key!='#'){
      number += key;
     }
   } 
 }else if(s>=11&s<13){
    
  if (key){
    //lcd.setCursor(0, 1);
    lcd.print(key);
    s++;
     if(key!='*' || key!='#'){
      type += key;
     }
   } 
 }

 if (key =='#'){
    // if key matches what you are looking for
    Sending_To_phpmyadmindatabase();
    sendData();
    write_info();
}

  if (key =='*'){
    // if key matches what you are looking for
    clear_Data();
  }
}


void Sending_To_phpmyadmindatabase()   //CONNECTING WITH MYSQL
 {
   if (client.connect(server, 80)) {

    Serial.print("GET /files/CustomersNumber/APInumber.php?number=");
    Serial.print(number);
    Serial.print("&type=");
    Serial.print(type);
    Serial.print("&token=766577452289383");
    Serial.println(" HTTP/1.1");
    Serial.print("Host: ");
    Serial.println(server);
    Serial.println("Connection: close");
    Serial.println();
    //client.println("GET /files/CustomersNumber/?number=99 HTTP/1.1");
    client.print("GET /files/CustomersNumber/APInumber.php?number=");
    client.print(number);
    client.print("&type=");
    client.print(type);
    client.print("&token=766577452289383");
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("failed to send");
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
        sendData();
      }
    }*/
    if(client.available()){
      char c = client.read();
      readString += c;
      
      Serial.print(c);
      if(readString.indexOf("100")>0){
         lcd.clear();
         lcd.setCursor(1, 0);
         lcd.print("--Data Error--");
       }else if(readString.indexOf("200")>0){
         lcd.clear();
         lcd.setCursor(2, 0);
         lcd.print("User Already");
         lcd.setCursor(5, 1);
         lcd.print("Exist");
       }else if(readString.indexOf("300")>0){
         lcd.clear();
         lcd.setCursor(0, 0);
         lcd.print("Connection Lost!");
       }else{
        //
       }
    }
  }
  
  if (!client.connected()) {
    lcd.clear();
    lcd.setCursor(6, 1);
    lcd.print("DONE");
    delay(1800);
    number = "";
    sent_=false;
    s = 0;
    client.stop();
  }
}

void load_func(){
  lcd.clear();
  lcd.setCursor(0, 0);
  for(j = 1; j<=100; j++){
    lcd.print("   Connecting");
    lcd.setCursor(6,1);
    lcd.print("%");
    lcd.print(j);
    delay(50);
    lcd.clear();
    i=j;
  }
  lcd.setCursor(6,1);
  lcd.print("%");
  lcd.print(i);
  delay(800);
  lcd.clear();
  lcd.setCursor(6,1);
  lcd.print("DONE");
  delay(600);
  
}

void sendData(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wait...");
  delay(3000);
  lcd.clear();
  for(int j=0; j<3; j++){
    lcd.print("Sending");
    for(int i=8; i<11; i++){
      lcd.setCursor(i, 0);
      lcd.print(".");
      delay(200);
    }
    delay(250);
    lcd.clear();
  }
  
}

void clear_Data(){
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("--CLEAR--");
  delay(500);
  s = 0;
  number = "";
  sent_=false;
}
