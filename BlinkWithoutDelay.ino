/*
 * Blink without Delay
 * by Ashley Woon
 */

#include <analogWrite.h>
 // RGB LED pins
 const int redLED = 12;
 const int greenLED = 27;
 const int blueLED = 33;

//fade
 const int LDR = A0;  
 const int POT = A1;  
 int LDRval = 0;
 int POTval= 0; 
 int redBrightness = 0;
 int greenBrightness = 0;
 int blueBrightness = 0;
 
 //timer
 unsigned long previousMillis = 0;
 unsigned long currentMillis;
 
 //intervals
 int delayTime = 1000;
 int whiteTime = 400;
 int purpleTime = 350;
 int yellowTime = 200;
 
void setup() {
  Serial.begin(9600);

  pinMode(POT, INPUT);
  pinMode(LDR, INPUT);
    
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  redBrightness = map(POTval, 0, 4095, 0, 255);
  greenBrightness = map(POTval, 0, 4095, 0, 255);
  blueBrightness = map(POTval, 0, 4095, 0, 255);
  currentMillis = millis();
  
  if(currentMillis - previousMillis >= delayTime)
  {
      previousMillis = currentMillis;
      analogWrite(redLED, redBrightness);
      analogWrite(greenLED, greenBrightness);
      analogWrite(blueLED, blueBrightness);
      
  }
}
