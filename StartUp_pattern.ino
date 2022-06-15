//This is my first Ardruino project so the code might be a bit messy.
//I mainly used these video's to write the code: 
//Part 1: https://youtu.be/4Ut4UK7612M 
//Part 2: https://youtu.be/FQpXStjJ4Vc
//Part 3: https://youtu.be/Ukq0tH2Tnkc

#include <FastLED.h>

#define NUM_LEDS  56 //How many leds the strip has
#define LED_PIN   3  //To wich pin the led strip is connected
#define TYPELED   WS2812B //The type of led strip 

CRGB leds[NUM_LEDS]; 
uint8_t paletteIndex = 0;

DEFINE_GRADIENT_PALETTE( heatmap_gp ) { //Watch Part 3 
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
      leds[i] = CRGB::Purple;                          //The base colour of the loading bar (Can be changed in any colour see https://github.com/FastLED/FastLED/wiki/Pixel-reference for a list of colours)
      FastLED.show();
      delay(30);
    }
    delay(100);
    for (int x = 0; x < NUM_LEDS / 2; x++) {  
      for(int i = 0; i < NUM_LEDS/2 - x; i++){
        leds[i] = CRGB::Cyan;                          //The colour of the moving led (Can be changed in any colour see https://github.com/FastLED/FastLED/wiki/Pixel-reference for a list of colours)
        FastLED.show(); 
        delay (15);    
        leds[i] = CRGB::Purple;                        //The base colour of the loading bar (Can be changed in any colour see https://github.com/FastLED/FastLED/wiki/Pixel-reference for a list of colours)
        leds[((NUM_LEDS / 2) - 2) - x] = CRGB::Cyan;   //The colour of the loading bar (Can be changed in any v see https://github.com/FastLED/FastLED/wiki/Pixel-reference for a list of colours)       
        leds[((NUM_LEDS / 2) - 1) - x] = CRGB::Cyan;   //The colour of the loading bar (Can be changed in any colour see https://github.com/FastLED/FastLED/wiki/Pixel-reference for a list of colours)
      }   
   }
    for(int i = NUM_LEDS / 2; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Cyan;                           //The colour of the top strip (Can be changed in any colour see https://github.com/FastLED/FastLED/wiki/Pixel-reference for a list of colours)
      FastLED.show();
      delay(30);
    }
   delay(700); 
  }
      


void loop(){ //0:12 in the video
  fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, myPal, 255, LINEARBLEND);
   EVERY_N_MILLISECONDS(10){
    paletteIndex++; 
   }
  FastLED.show(); 
}
