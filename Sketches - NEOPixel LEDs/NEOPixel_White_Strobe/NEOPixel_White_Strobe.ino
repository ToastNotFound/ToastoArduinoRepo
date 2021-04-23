#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN1 12
#define PIN2 13
#define LED_COUNT 2
Adafruit_NeoPixel pixel_1(LED_COUNT, PIN1, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel pixel_2(LED_COUNT, PIN2, NEO_RGB + NEO_KHZ800);
void setup() {

#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  pixel_1.begin();
  pixel_2.begin();
}

void loop()
{
    pixel_1.setPixelColor(0, pixel_1.Color(0, 0, 0));
    pixel_2.setPixelColor(0, pixel_2.Color(0, 0, 0));
    pixel_1.show();
    pixel_2.show();
    delay(1000);
    pixel_1.setPixelColor(0, pixel_1.Color(255, 255, 255));
    pixel_2.setPixelColor(0, pixel_2.Color(255, 255, 255));
    pixel_1.show();
    pixel_2.show();
    delay(1000)
}
