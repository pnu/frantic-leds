#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

#define NUM_LEDS 391

#define BRIGHTNESS 100

#define START 131

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  colorWipe(strip.Color(0, 0, 255), 0);
  colorWipe(strip.Color(0, 0, 0, 255), 0);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  uint16_t n = strip.numPixels();
  for(uint16_t i=0; i<n; i++) {
    strip.setPixelColor((n-i+START) % n, c);
    strip.show();
//    delay(wait);
  }
}

