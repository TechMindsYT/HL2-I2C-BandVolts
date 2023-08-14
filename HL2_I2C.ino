//***************************************************************************************
//*                          
//*                                                                                     *
//*        Based on HL2-PA70 by Cesc Gudayol (EA3IGT) Version 3.0.1 from 01/04/2021     *
//*                    More info: https://github.com/ea3igt/HL2-PA70                    *
//*                                                                                     *             *
//*                                                                                     * 
//***************************************************************************************
//*           THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND            *
//***************************************************************************************

#include <Wire.h>                     //For I2C control
#include <EEPROM.h>                   //To store values from PA70-Controller
#include <util/delay.h>               //Library to delay inside one Interrupt

void setup() {
  Serial.begin(9600);
  
  // I2C Slave Setup
  Wire.begin(0x20);                               // join i2c bus with address to listen
  Wire.onReceive(receiveEvent);                   // register event
  delay(200);

}

// Main loop program
void loop() 
{
 

void receiveEvent(int howMany) {      //Triggered when receive I2C information from HL2
  byte c[10];
  int i= 0;
  while (0 < Wire.available()) {      // loop through all but the last
    c[i] = Wire.read();               // receive byte as a character
    i++;
  }

  byte myC=c[1] & B00111111;          //Get 6 least significative bits

  decodeBand(myC);                    //Decode Band

}

void decodeBand(byte c)
{ 
  switch (c) {
    case 0x1:     //160m
      Serial.println("160M;"); 
      break;
    case 0x2:     //80m
      Serial.println("80M;"); 
      break;
    case 0x4:     //40m
      Serial.println("40M;"); 
      break;
    case 0x8:     //30m & 20m
      Serial.println("20M;"); 
      break;
    case 0x10:     //17m & 15m
      Serial.println("15M;"); 
      break;
    case 0x20:     //12m & 10m
      Serial.println("10M;"); 
      break;                
  }

}




