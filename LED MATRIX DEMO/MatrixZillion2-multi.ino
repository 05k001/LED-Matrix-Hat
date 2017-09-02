#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include "Spitmap.h"

#ifndef PSTR
#define PSTR // Make Arduino Due happy
#endif

#define PIN 7

#ifdef ESP8266
#define PIN RX
#endif

// Max is 255, 32 is a conservative value to not overload
// a USB power supply (500mA) for 12x12 pixels.
#define BRIGHTNESS 25

// Define matrix width and height.
#define mw 32
#define mh 8

Adafruit_NeoMatrix *matrix = new Adafruit_NeoMatrix(mw, mh, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

  #define LED_BLACK    0

#define LED_RED_VERYLOW   (3 <<  11)
#define LED_RED_LOW     (7 <<  11)
#define LED_RED_MEDIUM    (15 << 11)
#define LED_RED_HIGH    (31 << 11)

#define LED_GREEN_VERYLOW (1 <<  5)   
#define LED_GREEN_LOW     (15 << 5)  
#define LED_GREEN_MEDIUM  (31 << 5)  
#define LED_GREEN_HIGH    (63 << 5)  

#define LED_BLUE_VERYLOW  3
#define LED_BLUE_LOW    7
#define LED_BLUE_MEDIUM   15
#define LED_BLUE_HIGH     31

#define LED_ORANGE_VERYLOW  (LED_RED_VERYLOW + LED_GREEN_VERYLOW)
#define LED_ORANGE_LOW    (LED_RED_LOW     + LED_GREEN_LOW)
#define LED_ORANGE_MEDIUM (LED_RED_MEDIUM  + LED_GREEN_MEDIUM)
#define LED_ORANGE_HIGH   (LED_RED_HIGH    + LED_GREEN_HIGH)

#define LED_PURPLE_VERYLOW  (LED_RED_VERYLOW + LED_BLUE_VERYLOW)
#define LED_PURPLE_LOW    (LED_RED_LOW     + LED_BLUE_LOW)
#define LED_PURPLE_MEDIUM (LED_RED_MEDIUM  + LED_BLUE_MEDIUM)
#define LED_PURPLE_HIGH   (LED_RED_HIGH    + LED_BLUE_HIGH)

#define LED_CYAN_VERYLOW  (LED_GREEN_VERYLOW + LED_BLUE_VERYLOW)
#define LED_CYAN_LOW    (LED_GREEN_LOW     + LED_BLUE_LOW)
#define LED_CYAN_MEDIUM   (LED_GREEN_MEDIUM  + LED_BLUE_MEDIUM)
#define LED_CYAN_HIGH   (LED_GREEN_HIGH    + LED_BLUE_HIGH)

#define LED_WHITE_VERYLOW (LED_RED_VERYLOW + LED_GREEN_VERYLOW + LED_BLUE_VERYLOW)
#define LED_WHITE_LOW   (LED_RED_LOW     + LED_GREEN_LOW     + LED_BLUE_LOW)
#define LED_WHITE_MEDIUM  (LED_RED_MEDIUM  + LED_GREEN_MEDIUM  + LED_BLUE_MEDIUM)
#define LED_WHITE_HIGH    (LED_RED_HIGH    + LED_GREEN_HIGH    + LED_BLUE_HIGH)

static const uint16_t PROGMEM

    RGB_bmp[][64] = {
      // 00: blue, blue/red, red, red/green, green, green/blue, blue, white
      {  0x100, 0x200, 0x300, 0x400, 0x600, 0x800, 0xA00, 0xF00, 
  0x101, 0x202, 0x303, 0x404, 0x606, 0x808, 0xA0A, 0xF0F, 
        0x001, 0x002, 0x003, 0x004, 0x006, 0x008, 0x00A, 0x00F, 
  0x011, 0x022, 0x033, 0x044, 0x066, 0x088, 0x0AA, 0x0FF, 
  0x010, 0x020, 0x030, 0x040, 0x060, 0x080, 0x0A0, 0x0F0, 
  0x110, 0x220, 0x330, 0x440, 0x660, 0x880, 0xAA0, 0xFF0, 
  0x100, 0x200, 0x300, 0x400, 0x600, 0x800, 0xA00, 0xF00, 
  0x111, 0x222, 0x333, 0x444, 0x666, 0x888, 0xAAA, 0xFFF, },};

  void fixdrawRGBBitmap(int16_t x, int16_t y, const uint16_t *bitmap, int16_t w, int16_t h) {
    uint16_t RGB_bmp_fixed[w * h];
    for (uint16_t pixel=0; pixel<w*h; pixel++) {
  uint8_t r,g,b;
  uint16_t color = pgm_read_word(bitmap + pixel);

  //Serial.print(color, HEX);
  r = (color & 0xF00) >> 8;
  g = (color & 0x0F0) >> 4;
  b = color & 0x00F;
  //Serial.print(" ");
  //Serial.print(b);
  //Serial.print("/");
  //Serial.print(g);
  //Serial.print("/");
  //Serial.print(r);
  //Serial.print(" -> ");
  // expand from 4/4/4 bits per color to 5/6/5
  r = map(b, 0, 15, 0, 31);
  g = map(g, 0, 15, 0, 63);
  b = map(r, 0, 15, 0, 31);
  //Serial.print(r);
  //Serial.print("/");
  //Serial.print(g);
  //Serial.print("/");
  //Serial.print(b);
  RGB_bmp_fixed[pixel] = (r << 11) + (g << 5) + b;
  //Serial.print(" -> ");
  //Serial.println(RGB_bmp_fixed[pixel], HEX);
    }
    matrix->drawRGBBitmap(x, y, RGB_bmp_fixed, w, h);
}

void display_scrollText() {
    matrix->clear();
    matrix->setTextWrap(false);  // we don't wrap text so it scrolls nicely
    matrix->setTextSize(1);
    matrix->setRotation(0);
    for (int8_t x=7; x>=-125; x--) {
  matrix->clear();
  matrix->setCursor(x,0);
  matrix->setTextColor(LED_GREEN_HIGH);
  matrix->print("EVERGREEN STATE COLLEGE");
  matrix->show();
       delay(80);
    }
    }

    void lol(){
      matrix ->clear();
          matrix->setTextWrap(false);  // we don't wrap text so it scrolls nicely
    matrix->setTextSize(1);
    matrix->setRotation(0);
    for (int8_t x=7; x>=-55; x--) {
  matrix->clear();
  matrix->setCursor(x,0);
  matrix->setTextColor(LED_GREEN_HIGH);
  matrix->print("WELCOME TO");
  matrix->show();
       delay(80);
    }
    }

// Scroll within big bitmap so that all if it becomes visible or bounce a small one.
// If the bitmap is bigger in one dimension and smaller in the other one, it will
// be both panned and bounced in the appropriate dimensions.
void display_panOrBounceBitmap (uint8_t bitmapSize,  uint16_t gsauce) {
    // keep integer math, deal with values 16 times too big
    // start by showing upper left of big bitmap or centering if the display is big
    int16_t xf = max(0, (mw-bitmapSize)/2) << 4;
    int16_t yf = max(0, (mh-bitmapSize)/2) << 4;
    // scroll speed in 1/16th
    int16_t xfc = 6;
    int16_t yfc = 3;
    // scroll down and right by moving upper left corner off screen 
    // more up and left (which means negative numbers)
    int16_t xfdir = -1;
    int16_t yfdir = -1;

    for (uint16_t i=1; i<1000; i++) {
  bool updDir = false;

  // Get actual x/y by dividing by 16.
  int16_t x = xf >> 4;
  int16_t y = yf >> 4;



  

  matrix->clear();
  // bounce 8x8 tri color smiley face around the screen
  if (bitmapSize == 8) fixdrawRGBBitmap(x, y, RGB_bmp[10], 8, 8);
  // pan 24x24 pixmap
  if (bitmapSize == 24) matrix->drawRGBBitmap(x, y, (const uint16_t *) gsauce, bitmapSize, bitmapSize);
  matrix->show();
   
  // Only pan if the display size is smaller than the pixmap
  // but not if the difference is too small or it'll look bad.
  if (bitmapSize-mw>2) {
      if (mw>9) xf += xfc*xfdir;
      if (xf >= 0)                      { xfdir = -1; updDir = true ; };
      // we don't go negative past right corner, go back positive
      if (xf <= ((mw-bitmapSize) << 4)) { xfdir = 1;  updDir = true ; };
  }
  if (bitmapSize-mh>2) {
      yf += yfc*yfdir;
      // we shouldn't display past left corner, reverse direction.
      if (yf >= 0)                      { yfdir = -1; updDir = true ; };
      if (yf <= ((mh-bitmapSize) << 4)) { yfdir = 1;  updDir = true ; };
  }
  // only bounce a pixmap if it's smaller than the display size
  if (mw>bitmapSize) {
      xf += xfc*xfdir;
      // Deal with bouncing off the 'walls'
      if (xf >= (mw-bitmapSize) << 4) { xfdir = -1; updDir = true ; };
      if (xf <= 0)           { xfdir =  1; updDir = true ; };
  }
  if (mh>bitmapSize) {
      yf += yfc*yfdir;
      if (yf >= (mh-bitmapSize) << 4) { yfdir = -1; updDir = true ; };
      if (yf <= 0)           { yfdir =  1; updDir = true ; };
  }
  
  if (updDir) {
      // Add -1, 0 or 1 but bind result to 1 to 1.
      // Let's take 3 is a minimum speed, otherwise it's too slow.
      xfc = constrain(xfc + random(-1, 2), 3, 16);
      yfc = constrain(xfc + random(-1, 2), 3, 16);
  }
  delay(10);
    }
}

void loop(){
      display_scrollText();
      delay(3000);

          // pan a big pixmap
    display_panOrBounceBitmap(24,(const uint16_t *) bitmap25);
    lol();
    delay(2000);
}

void setup() {
    Serial.begin(9600);
    matrix->begin();
    matrix->setTextWrap(false);
    matrix->setBrightness(BRIGHTNESS);
    // Test full bright of all LEDs. If brightness is too high
    // for your current limit (i.e. USB), decrease it.
    matrix->fillScreen(LED_WHITE_HIGH);
    while (true){
      
lol();
      display_scrollText();
      display_panOrBounceBitmap(24, (const uint16_t *) bitmap28);

     
      
      //fixdrawRGBBitmap(0,0,256,24,24);
      //for (int i = 0; i < 65534; i++){

//      //Read values (6 char Hex split into 3)
//      uint8_t red = 0x53;
//      uint8_t green = 0xE8;
//      uint8_t blue = 0xF9;
//      
//      //Bit shifts Hex values to 16 bit colors
//      uint16_t r = ((red>>3) & 0x1F)<<11;
//      uint16_t g = ((green>>2)& 0x3F)<<5;
//      uint16_t b = ((blue>>3)& 0x1F);
//
//      //
//      uint16_t hexo2 = (r|g|b);
//      unsigned short hexo = (red<<11)|(green<<5)|blue;
//      matrix->fillRect(0, 0, 32, 8, 63488);
      //Serial.println(hexo2);
      //matrix->fillRect(0, 0, 32, 8, 0xFAC0):
      
      matrix->show();
   // }
    }
    matrix->show();
    delay(1000);
    matrix->clear();
}

