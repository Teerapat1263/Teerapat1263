#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define a A0
#define b A1
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void setup() {
display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c
display.clearDisplay(); // clears the screen and buffer
display.drawPixel(127, 63, WHITE);
pinMode(A0,INPUT);
pinMode(1,INPUT);
display.setTextSize(4);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println("SW1");
display.println("SW2");
display.fillCircle(100, 15, 10, WHITE);
display.fillCircle(100, 45, 10, WHITE);
display.display();
}

void loop() {
  display.fillCircle(100, 15, 10, WHITE);
display.fillCircle(100, 45, 10, WHITE);
  if(digitalRead(a)==1){
    display.fillCircle(100, 15, 8, BLACK);
  }
  if(digitalRead(b)==1){
    display.fillCircle(100, 45, 8, BLACK);
  }
  
  display.display();
  }
