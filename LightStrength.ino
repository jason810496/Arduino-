#include"LedControl.h"
LedControl lc=LedControl(12,10,11,1);//(din, clk, cs, #num)
void setup() {
  // initialize serial communication at 9600 bits per second:
  lc.shutdown(0,false);
  lc.setIntensity(0,5);
  Serial.begin(9600);
}
//------------------test1 input data,output on ledcontrol---------------//
void LightStregth(){
  // reads the input on analog pin A0 (value between 0 and 1023)
  int analogValue = analogRead(A0);
  int num1=analogValue/100;
  int num2=(analogValue%100)/10;
  int num3=analogValue%10;
  char n1=char(num1);
  char n2=char(num2);
  char n3=char(num3);

  Serial.print("Analog reading = ");
  Serial.println(analogValue);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  lc.setChar(0, 7, num1, false);
  lc.setChar(0, 6, num2, false);
  lc.setChar(0, 5, num3, false);
  Serial.println(num1);
  Serial.println(num2);
  Serial.println(num3);

  delay(1000);
  lc.clearDisplay(0);
}
void loop(){
  LightStregth();
}
/*--------------------information from : ----------------------------*\


 Created by ArduinoGetStarted.com

 This example code is in the public domain

 Tutorial page: https://arduinogetstarted.com/tutorials/arduino-light-sensor
 

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // reads the input on analog pin A0 (value between 0 and 1023)
  int analogValue = analogRead(A0);

  Serial.print("Analog reading = ");
  Serial.print(analogValue);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (analogValue < 10) {
    Serial.println(" - Dark");
  } else if (analogValue < 200) {
    Serial.println(" - Dim");
  } else if (analogValue < 500) {
    Serial.println(" - Light");
  } else if (analogValue < 800) {
    Serial.println(" - Bright");
  } else {
    Serial.println(" - Very bright");
  }

  delay(500);
}
*/
