/*
Serial input data
led output signal
*/



//#include <Keypad.h>
//#include <string.h>
#include "LedControl.h"
#define ledpin1 A1
void setup() {
  Serial.begin(9600);
  pinMode(ledpin1, OUTPUT);
}
//--------check if serial can input string----------//
String inputstring() {
  String str=Serial.readString();
  //Serial.print(str);
  return str;
}
void test1() {
  String str=Serial.readString();
  Serial.print(str);
  if(str.length()!=0) Serial.println(str.length());
  
}
//---------string to char-------------//
void test2(){
  String str=Serial.readString();
  //Serial.print(str);
  if(str.length()!=0){
    for(int i=0;i<str.length();i++){
      Serial.print(str[i]);
      }
    
    }
}
//----------------------------about led output-----------------------------//
void Longlight(int Time){//light for 0.5sec :0.6sec as an unit
  for(int i=0;i<Time;i++){
    digitalWrite(ledpin1, HIGH);
    delay(500);
    digitalWrite(ledpin1, LOW);
    delay(300);
  }
}
void Shortlight(int Time){// light for 0.3sec :0.4sec as an unit
  for(int i=0;i<Time;i++){
    digitalWrite(ledpin1, HIGH);
    delay(300);
    digitalWrite(ledpin1, LOW);
    delay(300);
  }
}
void Start(){// a signal to arduinoB to start to input data :for every signal ->3sec a unit
  
  digitalWrite(ledpin1, HIGH);
  delay(2000);
  digitalWrite(ledpin1, LOW);
  delay(1000);
}
void Stop(int Time){//to complete a full whole signal :0.1sec as an unit
  for(int i=0;i<Time;i++){
    digitalWrite(ledpin1, LOW);
    delay(300);
  }
}
void led1(){
  Shortlight(1);
  Longlight(4);
  Stop(2);
}
void led2(){
  Shortlight(2);
  Longlight(3);
  Stop(4);
}
void led3(){
  Shortlight(3);
  Longlight(2);
  Stop(6);
}
void led4(){
  Shortlight(4);
  Longlight(1);
  Stop(8);
}
void led5(){
  Shortlight(5);
  //Longlight(4);
  Stop(10);
}
void led6(){
  Longlight(1);
  Shortlight(4);
  Stop(8);
}
void led7(){
  Longlight(2);
  Shortlight(3);
  Stop(6);
}
void led8(){
  Longlight(3);
  Shortlight(2);
  Stop(4);
}
void led9(){
  Longlight(4);
  Shortlight(1);
  Stop(2);
}
void led0(){
  Longlight(5);
  //Shortlight(4);
}
void LEDcontrol_1(int N){
  if(N==0) led0();
  else if(N==1) led1();
  else if(N==2) led2();
  else if(N==3) led3();
  else if(N==4) led4();
  else if(N==5) led5();
  else if(N==6) led6();
  else if(N==7) led7();
  else if(N==8) led8();
  else led9();
}
//-----------^about led output^-------------//
//-------test3:check if serial can input data and output on light------------//
void test3(){
  String str=Serial.readString();
  //Serial.print(str);
  
  if(str.length()!=0){
    Serial.println(str);
    //Start();//45 as an unit
    for(int i=0;i<str.length();i++){
      LEDcontrol_1(str[i]-'0');
    }
  }
}

void loop(){

  test3();

  }
