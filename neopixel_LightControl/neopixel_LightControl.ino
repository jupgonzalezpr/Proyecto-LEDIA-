#include <Adafruit_NeoPixel.h>
#define PIN 6
#define LED_NUM 26
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);
int color_b=50;
float luxes = 111;
void setup()
{
Serial.begin(9600);
leds.begin(); // This initializes the NeoPixel library.
}
void loop()
{
  if(Serial.available())
  {
    String str = Serial.readStringUntil('\n');
    luxes = str.toFloat();
    //DEBUG(data); 
  }
  Serial.print("luxes ");
  Serial.println(luxes);
  controlLuz(luxes);
  
  Serial.print("color ");
  Serial.println(color_b);
  delay(500);  
  leds.clear();
  leds.setPixelColor(8,leds.Color(color_b,color_b,color_b));
  leds.show();
  leds.setPixelColor(9,leds.Color(color_b,color_b,color_b));
  leds.show();
  leds.setPixelColor(17,leds.Color(color_b,color_b,color_b));
  leds.show();
  leds.setPixelColor(24,leds.Color(color_b,color_b,color_b));
  leds.show();
  leds.setPixelColor(25,leds.Color(color_b,color_b,color_b));
  leds.show();
  /*delay(6000);
  leds.setPixelColor(8,leds.Color(100,100,100));
  leds.show();
  //delay(1000);
  leds.setPixelColor(9,leds.Color(100,100,100));
  leds.show();
  leds.setPixelColor(17,leds.Color(100,100,100));
  leds.show();
  leds.setPixelColor(24,leds.Color(100,100,100));
  leds.show();
  //delay(1000);
  leds.setPixelColor(25,leds.Color(100,100,100));
  leds.show();
  delay(6000);*/

  
//led_set(10, 0, 0);//red
//led_set(0, 0, 0);
//led_set(0, 10, 0);//green
//led_set(0, 0, 0);
//led_set(0, 0, 10);//blue
//led_set(0, 0, 0);
}
void led_set(int R, int G, int B)
{ 
for (int i = 8; i < LED_NUM; i++)
{
leds.setPixelColor(i, leds.Color(R, G, B));
leds.show();
delay(50);
}
}

void controlLuz(float luxes)
{ 
  if(luxes < 110){
    color_b=color_b + 5;
    if (color_b > 120){
        color_b=120;
      }
  }
  if(luxes > 120){
    color_b--;    
  }
}
/*
void maximoLuz(int color_b)
{ 
  if(color_b > 120 ){
    color_b=120;
  }
} 
*/
