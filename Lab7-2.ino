#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ThreeWire.h>  
#include <RtcDS1302.h>
ThreeWire myWire(4,5,2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);
#define a A0
#define b A1
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void printDateTime(const RtcDateTime& dt){
  display.clearDisplay(); // clears the screen and buffer
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(0, 6);
  display.print(dt.Hour(), DEC);
  display.print(':');
  display.print(dt.Minute(), DEC);
  display.print(':');
  display.print(dt.Second(), DEC);
  display.println();
  display.setCursor(0, 30);
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.print(dt.Year(), DEC);
  display.print("/");
  display.print(dt.Month(), DEC);
  display.print("/");
  display.print(dt.Day(),DEC);
  display.display();
}
void setup() {
display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c
display.clearDisplay(); // clears the screen and buffer
display.drawPixel(127, 63, WHITE);
pinMode(0,INPUT);
pinMode(1,INPUT);
Serial.begin(57600);
Rtc.Begin();
RtcDateTime setting_time(2020,2,2,23,31,10);// year, month, dayOfMonth, hour, minute, second
printDateTime(setting_time);//Try to comment This line
Rtc.SetDateTime(setting_time);

display.setTextSize(3);
display.setTextColor(WHITE);
display.setCursor(0,0);

display.display();


}

void loop() {
  
  RtcDateTime now = Rtc.GetDateTime();
  printDateTime(now);
  
display.display();
  }
