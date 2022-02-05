#include <SoftwareSerial.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

SoftwareSerial Blue(2, 3); //(TX, RX)
LiquidCrystal_I2C lcd(0x3F, 16, 2);



long int data;
int j ,i=0, redValue=255, blueValue=255, greenValue=255;
int de_lay = 12, code=0, value;
boolean cc = false;
int fade_1 = 250, fade_2 = 5;
int RGB_fade1, RGB_fade2;

long int R = 9;
long int G = 10;
long int B = 11;
long int R2 = 3;
long int G2 = 5;
long int B2 = 6;
long int relay = 13;

long int password1 = 330;// light on
long int password2 = 400; // light off
 
char state = 0;

void setup() {
  Blue.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  analogWrite(R, 255);
  analogWrite(G, 255);
  analogWrite(B, 255);
  pinMode(R2, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(B2, OUTPUT);
  analogWrite(R2, 255);
  analogWrite(G2, 255);
  analogWrite(B2, 255);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);

}

void loop() {
  while(Blue.available()==1||Blue.available()==0) ;
   //Serial.println(data);
 fadePosition:
 while(Blue.available()>1||Blue.available()>0) 
  {
    data = Blue.parseInt();
    delay(5);
    //return;
    //value = data;
  } 
  if(data==55){
    cc = false;
    fade_1 = 250;
    fade_2 = 5;
    digitalWrite(relay, HIGH);
    redValue = 255;
    greenValue = 255;
    blueValue = 255;
    setColor(redValue, greenValue, blueValue);
    setColor2(redValue, greenValue, blueValue);
    return;
  }
   if(data==99){
    cc = false;
    digitalWrite(relay, LOW);
    redValue = 10;
    greenValue = 10;
    blueValue = 10;
    setColor(redValue, greenValue, blueValue);
    setColor2(redValue, greenValue, blueValue);
    delay(800);
    redValue = 255;
    greenValue = 255;
    blueValue = 255;
    setColor(redValue, greenValue, blueValue);
    setColor2(redValue, greenValue, blueValue);
    return;
   // fading(redValue, greenValue, blueValue);
  }
  if(data>=10&&data<=305){
    cc = false;
    getRGBCode(data);
    
    //Serial.println(data);
  }
  if(data>=410&&data<=650){
    getRGBFade(data);
    
    goto fadePosition;
  }
  if(data==720){
    fadingRGB();
    //fadingRGB_2();
    goto fadePosition;
  }
  
}

void setColor(int a, int b, int c){
   analogWrite(R, a);
   analogWrite(G, b);
   analogWrite(B, c);
   //setFade(a, b, c);
}
void setColor2(int a, int b, int c){
   analogWrite(R2, a);
   analogWrite(G2, b);
   analogWrite(B2, c);
}

void fadingRGB(){
  while(fade_1>=5&&fade_2<=250){
    setColor(fade_1, fade_1, fade_1);
    setColor2(fade_2, fade_2, fade_2);
    delay(de_lay);
    fade_1--;
    fade_2++;
  }
  delay(5);
  while(fade_2>=5&&fade_1<=250){
    setColor(fade_1, fade_1, fade_1);
    setColor2(fade_2, fade_2, fade_2);
    delay(de_lay);
    fade_2--;
    fade_1++;
  }
  delay(5);
}
void fadingRGB_red(int a, int b, int c, int d){
  
  while(a<=253&&b>=1){
    setColor(a, c, d);
    setColor2(b, c, d);
    delay(de_lay);
    a++;
    b--;
  }
  
  //RGB_fade1 = 250; 
  //RGB_fade2 = 250;
  delay(5);
  while(b<=253&&a>=1){
    setColor(a, c, d);
    setColor2(b, c, d);
    delay(de_lay);
    b++;
    a--;
  }
  delay(5);
}
void fadingRGB_green(int a, int b, int c, int d){
  
  while(a<=253&&b>=1){
    setColor(c, a, d);
    setColor2(c, b, d);
    delay(de_lay);
    a++;
    b--;
  }
  
  //RGB_fade1 = 250; 
  //RGB_fade2 = 250;
  delay(5);
  while(b<=253&&a>=1){
    setColor(c, a, d);
    setColor2(c, b, d);
    delay(de_lay);
    b++;
    a--;
  }
  delay(5);
}
void fadingRGB_blue(int a, int b, int c, int d){
  
  while(a<=253&&b>=1){
    setColor(c, d, a);
    setColor2(c, d, b);
    delay(de_lay);
    a++;
    b--;
  }
  
  //RGB_fade1 = 250; 
  //RGB_fade2 = 250;
  delay(5);
  while(b<=253&&a>=1){
    setColor(c, d, a);
    setColor2(c, d, b);
    delay(de_lay);
    b++;
    a--;
  }
  delay(5);
}

void getRGBCode(int data){
  // RGB 1
  /*red*/
  if(data==10){
    redValue = 0;
    greenValue = 0;
    blueValue = 0;
    setColor(redValue, greenValue, blueValue);
    return;
  }
  else if(data==11){
    redValue = 0;
    greenValue = 255;
    blueValue = 255;
    setColor(redValue, greenValue, blueValue);
    //fading(redValue, greenValue, blueValue);
    return;
  }
  else if(data==12){
    redValue = 0;
    greenValue -= 63.75;
    blueValue = 255;
    setColor(redValue, greenValue, blueValue);
    return;
  }
  else if(data==13){
    redValue = 0;
    greenValue -= 127.5;
    blueValue = 255;
    setColor(redValue, greenValue, blueValue);
    return;
  }
  else if(data==14){
    redValue = 0;
    greenValue -= 191.25;
    blueValue = 255;
    setColor(redValue, greenValue, blueValue);
    return;
  }
  else if(data==15){
    redValue = 0;
    greenValue = 0;
    blueValue = 255;
    setColor(redValue, greenValue, blueValue);
    return;
  }
  /*green*/
  else if(data==21){
    redValue = 255;
    greenValue = 0;
    blueValue = 255;
    setColor(redValue, greenValue, blueValue);
    return;
  }else if(data==22){
    redValue = 255;
    greenValue = 0;
    blueValue -= 63.75;
    setColor(redValue, greenValue, blueValue);
    return;
  }
  else if(data==23){
    redValue = 255;
    greenValue = 0;
    blueValue -= 127.5;
    setColor(redValue, greenValue, blueValue);
    return;
  }
  else if(data==24){
    redValue = 255;
    greenValue = 0;
    blueValue -= 191.25;
    setColor(redValue, greenValue, blueValue);
    return;
  }
  else if(data==25){
    redValue = 255;
    greenValue = 0;
    blueValue = 0;
    setColor(redValue, greenValue, blueValue);
    return;
  }
  /*blue*/
  else if(data==31){
    redValue = 255;
    greenValue = 255;
    blueValue = 0;
    setColor(redValue, greenValue, blueValue);
    return;
  }else if(data==32){
    redValue -= 63.75;
    greenValue  = 255;
    blueValue = 0;
    setColor(redValue, greenValue, blueValue);
    return;
  }
  else if(data==33){
    redValue -= 127.5;
    greenValue  = 255;
    blueValue = 0;
    setColor(redValue, greenValue, blueValue);
    return;
  }
  else if(data==34){
    redValue -= 191.25;
    greenValue = 255 ;
    blueValue = 0;
    setColor(redValue, greenValue, blueValue);
    return;
  }
  else if(data==35){
    redValue = 05;
    greenValue = 255;
    blueValue = 0;
    setColor(redValue, greenValue, blueValue);
    return;
  }
  // RGB 2
  /*red*/
   if(data==100){
    redValue = 0;
    greenValue = 0;
    blueValue = 0;
    setColor2(redValue, greenValue, blueValue);
    return;
  }
  else if(data==101){
    redValue = 0;
    greenValue = 255;
    blueValue = 255;
    setColor2(redValue, greenValue, blueValue);
    return;
  }
  else if(data==102){
    redValue = 0;
    greenValue -= 63.75;
    blueValue = 255;
    setColor2(redValue, greenValue, blueValue);
    return;
    
  }
  else if(data==103){
    redValue = 0;
    greenValue -= 127.5;
    blueValue = 255;
    setColor2(redValue, greenValue, blueValue);
    return;
  }
  else if(data==104){
    redValue = 0;
    greenValue -= 191.25;
    blueValue = 255;
    setColor2(redValue, greenValue, blueValue);
    return;
  }
  else if(data==105){
    redValue = 0;
    greenValue = 0;
    blueValue = 255;
    setColor2(redValue, greenValue, blueValue);
    return;
  }
  /*green*/
  else if(data==201){
    redValue = 255;
    greenValue = 0;
    blueValue = 255;
    setColor2(redValue, greenValue, blueValue);
    return;
  }else if(data==202){
    redValue = 255;
    greenValue = 0;
    blueValue -= 63.75;
    setColor2(redValue, greenValue, blueValue);
    return;
  }
  else if(data==203){
    redValue = 255;
    greenValue = 0;
    blueValue -= 127.5;
    setColor2(redValue, greenValue, blueValue);
    return;
  }
  else if(data==204){
    redValue = 255;
    greenValue = 0;
    blueValue -= 191.25;
    setColor2(redValue, greenValue, blueValue);
    return;
  }
  else if(data==205){
    redValue = 255;
    greenValue = 0;
    blueValue = 0;
    setColor2(redValue, greenValue, blueValue);
    return;
  }
  /*blue*/
  else if(data==301){
    redValue = 255;
    greenValue = 255;
    blueValue = 0;
    setColor2(redValue, greenValue, blueValue);
    return;
  }else if(data==302){
    redValue -= 63.75;
    greenValue  = 255;
    blueValue = 0;
    setColor2(redValue, greenValue, blueValue);
    return;
  }
  else if(data==303){
    redValue -= 127.5;
    greenValue  = 255;
    blueValue = 0;
    setColor2(redValue, greenValue, blueValue);
    return;
  }
  else if(data==304){
    redValue -= 191.25;
    greenValue = 255 ;
    blueValue = 0;
    setColor2(redValue, greenValue, blueValue);
    return;
  }
  else if(data==305){
    redValue = 0;
    greenValue = 255;
    blueValue = 0;
    setColor2(redValue, greenValue, blueValue);
    return;
  }
}
/**/
void getRGBFade(int data){
  if(data==410){
    // red
    fadingRGB_red(1,253,255,255);
  }
  else if(data==420){
    // red
    fadingRGB_red(1,253,191.5,255);
  }
  else if(data==430){
    // red
    fadingRGB_red(1,253,127,255);
  }
  else if(data==440){
    // red
    fadingRGB_red(1,253,63.5,255);
  }
  else if(data==450){
    // red
    fadingRGB_red(1,253,0,255);
  }
  else if(data==510){
    //green
    fadingRGB_green(1,253,255,255);
  }
  else if(data==520){
    //green
    fadingRGB_green(1,253,255,19.5);
  }
  else if(data==530){
    //green
    fadingRGB_green(1,253,255,127);
  }
  else if(data==540){
    //green
    fadingRGB_green(1,253,255,63.5);
  }
  else if(data==550){
    //green
    fadingRGB_green(1,253,255,0);
  }
  else if(data==610){
    //blue
    fadingRGB_blue(1,253,255,255);
  }
  else if(data==620){
    //blue
    fadingRGB_blue(1,253,191.5,255);
  }
  else if(data==630){
    //blue
    fadingRGB_blue(1,253,127,255);
  }
  else if(data==640){
    //blue
    fadingRGB_blue(1,253,63.5,255);
  }
  else if(data==650){
    //blue
    fadingRGB_blue(1,253,0,255);
  }
}
