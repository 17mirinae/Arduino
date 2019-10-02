#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUM_LEDS 8
#define BRIGHTNESS 255

Adafruit_NeoPixel ring = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);
SoftwareSerial bluetooth(2,3);

void setup() {
  ring.begin();
  ring.setBrightness(BRIGHTNESS);
  ring.show();
  
  bluetooth.begin(9600);
}

int r = 0, g = 0, b = 0;

void loop() {
  if(bluetooth.available() > 2){
    ring.begin();
    
    r = bluetooth.read();
    g = bluetooth.read();
    b = bluetooth.read();
    
    bluetooth.flush();

    ring.setPixelColor(0, ring.Color(r,g,b));
    ring.show();
    delay(300);
    
    ring.setPixelColor(4, ring.Color(r,g,b));
    ring.show();
    delay(300);
    
    ring.setPixelColor(8, ring.Color(r,g,b));
    ring.show();
    delay(300);
  }
}
