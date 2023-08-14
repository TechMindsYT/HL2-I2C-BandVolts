#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;
String inputString = "";      // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  Wire.begin();
  dac.begin(0x60);
  inputString.reserve(200);
}

void loop() {
  if (stringComplete) {
    inputString.trim();
    processrx(inputString);
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
   
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void processrx (String band) {

  if (band == "160M;") {
    dac.setVoltage(190, false);
  }

  if (band == "80M;") {
    dac.setVoltage(385, false);
  }

   if (band == "40M;") {
    dac.setVoltage(700, false);
  }

 if (band == "20M;") {
     dac.setVoltage(1100, false);
  }

   if (band == "15M;") {
    dac.setVoltage(1500, false);
  }

   if (band == "10M;") {
  dac.setVoltage(1800, false);
  }
}




