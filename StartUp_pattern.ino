// This was my first arduino project so the code will be crap
// see https://github.com/FastLED/FastLED/wiki/Pixel-reference for a list of colours
#include <FastLED.h>

#define NUM_LEDS  56
#define LED_PIN   3 
#define TYPELED   WS2812B // led strip type 

CRGB leds[NUM_LEDS]; 
uint8_t paletteIndex = 0;

DEFINE_GRADIENT_PALETTE( heatmap_gp ) {
    0,   1,  8, 87,
   71,  23,195,130,
  122, 186,248,233,
  168,  23,195,130,
  255,   1,  8, 87};
  
CRGBPalette16 myPal = heatmap_gp;

void setup() {
  FastLED.addLeds<TYPELED, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(255);

   for(int i = 0; i < NUM_LEDS/2; i++){ 
      leds[i] = CRGB::Purple;                          // base colour of the loading bar
      FastLED.show();
      delay(30);
    }
    delay(100);
    for (int x = 0; x < NUM_LEDS / 2; x++) {  
      for(int i = 0; i < NUM_LEDS/2 - x; i++){
        leds[i] = CRGB::Cyan;                          // colour of the moving led
        FastLED.show(); 
        delay (15);    
        leds[i] = CRGB::Purple;                        // base colour of the loading bar
        leds[((NUM_LEDS / 2) - 2) - x] = CRGB::Cyan;   // colour of the loading bar  
        leds[((NUM_LEDS / 2) - 1) - x] = CRGB::Cyan;   // colour of the loading bar
      }   
   }
    for(int i = NUM_LEDS / 2; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Cyan;                           // colour of the top strip
      FastLED.show();
      delay(30);
    }
   delay(700); 
  }
      


void loop(){
  fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, myPal, 255, LINEARBLEND);
   EVERY_N_MILLISECONDS(10){
    paletteIndex++; 
   }
  FastLED.show(); 
}
