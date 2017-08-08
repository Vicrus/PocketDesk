#include <Arduino.h>
#include <stdlib.h>
#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <SPFD5408_TouchScreen.h>
// *** SPFD5408 change -- End
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin


#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

int x = 0;
int y = 0;

void drawPoint(int x, int y, int thinkes, uint16_t color){
    for(int i = 0; i < thinkes; i++){
      for(int j = 0; j < thinkes; j++){
        tft.drawPixel(x + i,y + j, color);
      }
    }
}
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(9600);

  tft.reset();
  tft.begin(0x9341); // SDFP5408
  tft.setRotation(0); // Need for the Mega, please changed for your choice or rotation initial
  for(uint8_t rotation=0; rotation<4; rotation++) {
    tft.setRotation(rotation);
    tft.fillScreen(BLACK);
    //tft.drawPixel(x, y, WHITE);
  }

}
void loop() {

  if(Serial.available()){
    uint16_t color;
    int thinkes = 1;
    String stream = Serial.readStringUntil('\n');
    sscanf(stream.c_str(), "%d %d %d %x", &x, &y, &thinkes,  &color);
    //tft.drawPixel(x, y, color);
    tft.drawCircle(x, y, thinkes,color);
    tft.fillCircle(x, y, thinkes, color);
  }
}
