#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUM_LEDS 8
#define BRIGHTNESS 255

int redPre = random(0, 255);
int greenPre = random(0, 255);
int bluePre = random(0, 255);

Adafruit_NeoPixel ring = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  ring.begin();
  ring.setBrightness(BRIGHTNESS); // 밝기 조절
  colorWipe(ring.Color(0, 0, 0, 0), 100);
  ring.show();
  delay(1000);
}

void loop() {
    ring.begin();
    
    int redNow = random(0, 255); // 빨간색
    int blueNow = random(0, 255); // 파란색
    int greenNow = random(0, 255); // 초록색
  
    while((redNow == redPre) || (greenNow == greenPre) || (blueNow == bluePre)) {
      if(redNow == redPre) {
        redNow = random(0, 255);
      }
      if(greenNow == greenPre) {
        greenNow = random(0, 255);
      }
      if(blueNow == bluePre) {
        blueNow = random(0, 255);
      }
    }
    
    if(blueNow == redNow == greenNow == 0) {
      while((blueNow == 0) && (redNow == 0) && (greenNow == 0)) {
        redNow = random(0, 255);
        greenNow = random(0, 255);
        blueNow = random(0, 255);
      }
    }

    redPre = redNow;
    greenPre = greenNow;
    bluePre = blueNow;
    
    colorWipe(ring.Color(redNow, greenNow, blueNow, 50), 100);
    // 모든 픽셀이 같은 색을 출력한다.
    // 2번째 인자는 다른 픽셀이 켜지기 까지의 지연 시간이다.
    
    ring.show();
    delay(1000);
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i = 0;i < ring.numPixels(); i++) {
    ring.setPixelColor(i, c); // 픽셀의 색을 정해준다.
    ring.show();
    delay(wait); // 내가 설정한 만큼의 시간만큼 지연시킨다.
  }
}
