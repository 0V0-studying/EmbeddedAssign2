#include <Arduino.h>

// put function declarations here:
int led1=23;
int led2=22;
int panduan1=1;//观察led灯情况
int panduan2=1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
}

void loop() {
  if (Serial.available() > 0)//如果串口有数据
  {
    String myString = Serial.readStringUntil('\n');//读取字符串
    if (myString=="1"){
      if (panduan1==1){
        digitalWrite(led1,HIGH);
        Serial.println("LED1 on");
        panduan1=-1;    
      }
      else {
        digitalWrite(led1,LOW);
        Serial.println("LED1 off");
        panduan1=1; 
      }
    }
    if (myString=="2"){
      if (panduan2==1){
        digitalWrite(led2,HIGH);
        Serial.println("LED2 on");
        panduan2=-1;     
      }
      else {
        digitalWrite(led2,LOW);
        Serial.println("LED2 off");
        panduan2=1; 
      }
    }

  }

}