#include<SPI.h>
uint8_t counter=1;
uint8_t map_7_seg[10] = {
  0x3F,
  0x06,
  0x5B,
  0x4F,
  0x66,
  0x6D,
  0x7D,
  0x07,
  0x7F,
  0x6F
};
void setup() {
  // put your setup code here,to run once:
  SPI.begin();
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));
  pinMode(SS,OUTPUT);
  
  }
  void loop() {
    // put your main code here, to run repeatedly:
    SPI.transfer(map_7_seg[counter]);
    digitalWrite(SS,HIGH);
    digitalWrite(SS,LOW);
    counter++;
    
    delay(1000);
    }
