#include"LedControl.h"
LedControl lc=LedControl(12,10,11,1);//(din, clk, cs, #num)
void setup() {
  // initialize serial communication at 9600 bits per second:
  lc.shutdown(0,false);
  lc.setIntensity(0,5);
  Serial.begin(9600);
}


//------------------identify light or not--------------------//
int trans(int n){
  if(n>200) return 1;
  else return 0;
}
//---------------------collect signal and output on serial---------------------//
int DATALIST[30]={};
int collectstep=0;
int collectedDATA(){
  if(collectstep==30){
    for(int j=0;j<30;j++){
      Serial.println(DATALIST[j]);
    }
    collectstep%=30;
  }
  int DATA = trans(analogRead(A0));
  DATALIST[collectstep]=DATA;
  collectstep++;
  delay(100);
}
//------------------function to distinguish signal------------------------//
int wait=0;
void printnum(int DATALIST[]){
  int N1=0,N2=0,N3=0,N4=0,N5=0,N6=0,N7=0,N8=0,N9=0,N0=0;
  int list1[30]={1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0};
  int list2[30]={1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0};
  int list3[30]={1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0};
  int list4[30]={1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0};
  int list5[30]={1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0};
  int list6[30]={1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0};
  int list7[30]={1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0};
  int list8[30]={1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0};
  int list9[30]={1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,0,0};
  int list0[30]={1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0};
  for(int i=0;i<30;i++){
    if(DATALIST[i]==list2[i]) N1++;
    if(DATALIST[i]==list2[i]) N2++;
    if(DATALIST[i]==list3[i]) N3++;
    if(DATALIST[i]==list4[i]) N4++;
    if(DATALIST[i]==list5[i]) N5++;
    if(DATALIST[i]==list6[i]) N6++;
    if(DATALIST[i]==list7[i]) N7++;
    if(DATALIST[i]==list8[i]) N8++;
    if(DATALIST[i]==list9[i]) N9++;
    if(DATALIST[i]==list0[i]) N0++;
  }
  int id=25,out=0;
  if(wait==0){
    if(N1>=id){ Serial.println("1");N1=N2=N3=N4=N5=N6=N7=N8=N9=N0=0;wait=20;lc.setChar(0, 7, 1, false);}
    if(N2>=id){ Serial.println("2");N1=N2=N3=N4=N5=N6=N7=N8=N9=N0=0;wait=20;lc.setChar(0, 7, 2, false);}
    if(N3>=id){ Serial.println("3");N1=N2=N3=N4=N5=N6=N7=N8=N9=N0=0;wait=20;lc.setChar(0, 7, 3, false);}
    if(N4>=id){ Serial.println("4");N1=N2=N3=N4=N5=N6=N7=N8=N9=N0=0;wait=20;lc.setChar(0, 7, 4, false);}
    if(N5>=id){ Serial.println("5");N1=N2=N3=N4=N5=N6=N7=N8=N9=N0=0;wait=20;lc.setChar(0, 7, 5, false);}
    if(N6>=id){ Serial.println("6");N1=N2=N3=N4=N5=N6=N7=N8=N9=N0=0;wait=20;lc.setChar(0, 7, 6, false);}
    if(N7>=id){ Serial.println("7");N1=N2=N3=N4=N5=N6=N7=N8=N9=N0=0;wait=20;lc.setChar(0, 7, 7, false);}
    if(N8>=id){ Serial.println("8");N1=N2=N3=N4=N5=N6=N7=N8=N9=N0=0;wait=20;lc.setChar(0, 7, 8, false);}
    if(N9>=id){ Serial.println("9");N1=N2=N3=N4=N5=N6=N7=N8=N9=N0=0;wait=20;lc.setChar(0, 7, 9, false);}
    if(N0>=id){ Serial.println("0");N1=N2=N3=N4=N5=N6=N7=N8=N9=N0=0;wait=20;lc.setChar(0, 7, 0, false);}
  }
  wait--;
  if(wait<0) wait=0;
  
}
//------------------------------------------//

void loop() {
  int DATA = trans(analogRead(A0));
  DATALIST[collectstep]=DATA;
  //identify
  for(int i=0;i<30;i++) Serial.print(DATALIST[i]);
  Serial.println(" ");
  printnum(DATALIST);
  collectstep++;
  if(collectstep==30){
    for(int i=0;i<29;i++){
      DATALIST[i]=DATALIST[i+1];
    }
    collectstep--;
  }
  delay(100);
}
