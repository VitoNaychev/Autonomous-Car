#include"autonomous.h"

int fr = 3;
int bk = 5;
int lf = 6;
int rt = 9;

int frSen = 7;
int lfSen = 8;
int rtSen = 10;

int frTrig = 11;
int lfTrig = 12;
int rtTrig = 13;

void sensorTest();
void motorTest();

void setup() {
  // put your setup code here, to run once:
  pinMode(frTrig, OUTPUT);
  pinMode(lfTrig, OUTPUT);
  pinMode(rtTrig, OUTPUT);
  pinMode(fr, OUTPUT);
  pinMode(bk, OUTPUT);
  pinMode(lf, OUTPUT);
  pinMode(rt, OUTPUT);
  pinMode(frSen, INPUT);
  pinMode(lfSen, INPUT);
  pinMode(rtSen, INPUT);
  
  Serial.begin(9600);  
}

void loop() {
  sensorTest();
    
}

float exception(float dist, int sens, int trig){
  while(1){
    if(dist < calcDist(sens, trig) + 1 || dist > calcDist(sens, trig) - 1){    
      if(dist < calcDist(sens, trig) + 1 || dist > calcDist(sens, trig) - 1){
        if(dist < calcDist(sens, trig) + 1 || dist > calcDist(sens, trig) - 1){
          return dist;
        } 
      }
    }
    if(dist < 0){
      return 1000;
    }
  }
}

void sensorTest(){
    delay(1000);
    float frDist = calcDist(frSen, frTrig);
    float lfDist = calcDist(lfSen, lfTrig);
    float rtDist = calcDist(rtSen, rtTrig);
    Serial.print("Front: ");
    Serial.print(calcDist(frSen, frTrig));
    Serial.print(" Left: ");
      Serial.print(calcDist(lfSen, lfTrig));
    Serial.print(" Right: ");
    Serial.println(calcDist(rtSen, rtTrig));  

}

void motorTest(){ 
  analogWrite(fr, 150);
  delay(1000);
  analogWrite(fr, 0);
  delay(500); 
  
  analogWrite(bk, 150);
  delay(1000);
  analogWrite(bk, 0);
  delay(500);
  
  analogWrite(lf, 255);
  delay(1000);
  analogWrite(lf, 0);
  delay(500);
  
  analogWrite(rt, 255);
  delay(1000);
  analogWrite(rt, 0);
  delay(500);
}


