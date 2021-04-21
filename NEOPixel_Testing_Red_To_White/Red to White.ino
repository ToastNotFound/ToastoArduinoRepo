#include <Adafruit_NeoPixel.h> //Import the Adafruit Library to use the LEDS, can be found online or in the 'board docs' folder in my github repository.
#ifdef __AVR__
  #include <avr/power.h> //Power to the LEDS.
#endif

#define Button 2  
#define PIN1 12 //LED 1.
#define PIN2 13 //LED 2.
#define LED_COUNT 2 //Tells the board that we will be using the 2 LEDs on the board ONLY.
Adafruit_NeoPixel pixel_1(LED_COUNT, PIN1, NEO_RGB + NEO_KHZ800); //Configures the first LED within Adafruit.
Adafruit_NeoPixel pixel_2(LED_COUNT, PIN2, NEO_RGB + NEO_KHZ800); //Configures the second LED within Adafruit.
void setup() {

#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  pinMode(2,INPUT_PULLUP); //Tells the board to treat pin 2 as a switch.
  Serial.begin(9600); //Starts the serial for debug, optional.
  pixel_1.begin(); //Initialises the first LED, this will blank and turn off the LED ready for the instructions in the loop() section.
  pixel_2.begin(); //Initialises the second LED, this will blank and turn off the LED ready for the instructions in the loop() section.
}

void loop() {

  if(digitalRead(Button)==LOW){
    pixel_1.setPixelColor(0, pixel_1.Color(255, 255, 255)); //White RGB Value
    pixel_2.setPixelColor(0, pixel_2.Color(255, 255, 255)); //White RGB Value
    pixel_1.show(); //Displays the colour previously defined
    pixel_2.show(); //Displays the colour previously defined
    delay(1);
    Serial.print("1111");
  } else if (digitalRead(Button)==HIGH){
    pixel_1.setPixelColor(0, pixel_1.Color(0, 55, 0)); //Red RGB Value
    pixel_2.setPixelColor(0, pixel_2.Color(0, 55, 0)); //Red RGB Value
    pixel_1.show(); //Displays the colour previously defined
    pixel_2.show(); //Displays the colour previously defined
    delay(1);
    Serial.print("2222");
  }
}
