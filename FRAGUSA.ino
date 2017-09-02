
//This sketch should display an american flag drawn by me. :)


#include <FastLED.h>
#include<SPI.h>


#include <LEDMatrix.h>

// Change the next 6 defines to match your matrix type and size

#define LED_PIN        7
#define COLOR_ORDER    GRB
#define CHIPSET        WS2811

#define MATRIX_WIDTH   32  // Set this negative if physical led 0 is opposite to where you want logical 0
#define MATRIX_HEIGHT  8  // Set this negative if physical led 0 is opposite to where you want logical 0
#define MATRIX_TYPE    VERTICAL_ZIGZAG_MATRIX  // See top of LEDMatrix.h for matrix wiring types

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;



void setup()
{
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());
  FastLED.clear(true);
  delay(500);
  FastLED.clear(true);
  Serial.begin(9600);
  FastLED.setBrightness(1); 

}


void loop()
{
  int16_t sx, sy, x, y;
  uint8_t h;

  FastLED.clear();

  //Draw Stripes

for (int i=0; i < MATRIX_WIDTH; i ++){

leds(i,0) = CRGB::Red;
leds(i,1) = CRGB::White;
leds(i,2) = CRGB::Red;
leds(i,3) = CRGB::White;
leds(i,4) = CRGB::Red;
leds(i,5) = CRGB::White;
leds(i,6) = CRGB::Red;
leds(i,7) = CRGB::White;

//Draws a blue box

for (int j = 31; j > 20; j--){
  leds(j,7) = CRGB::Blue;
  leds(j,6) = CRGB::Blue;
  leds(j,5) = CRGB::Blue;
  leds(j,4) = CRGB::Blue;
  leds(j,3) = CRGB::Blue;
  
}
FastLED.show();
}

FastLED.setBrightness(1); 
FastLED.show();
delay(2000);


//Moves Flag off Screen

//for(int h = 0; h < MATRIX_WIDTH; h++){
//  leds.ShiftLeft();
//  delay(10);
//  FastLED.show();
//   
//}

uint8_t angle = 0;
  for (int f = 0; f <500; f++){
  uint8_t h = sin8(angle); //H is an angle
  leds.ShiftLeft(); //Shift Every pixel (right)
  for (int16_t y=leds.Height()-1; y>=0; --y) 
  {
    leds(leds.Width()-1, y) = CHSV(h, 255, 255);
    h += 32;
  }
  angle += 4;
  FastLED.show();
  delay(20);
}


  
}

