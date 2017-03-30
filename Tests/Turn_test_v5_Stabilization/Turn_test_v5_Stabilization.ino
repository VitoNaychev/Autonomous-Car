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

void setup() {
  // put your setup code here, to run once:
  pinMode(frTrig, OUTPUT);
  pinMode(rtTrig, OUTPUT);
  pinMode(lfTrig, OUTPUT);
  pinMode(fr, OUTPUT);
  pinMode(bk, OUTPUT);
  pinMode(lf, OUTPUT);
  pinMode(rt, OUTPUT);
  pinMode(frSen, INPUT);
  pinMode(lfSen, INPUT);
  pinMode(rtSen, INPUT);
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float front = calcDist(frSen, frTrig);
  float left;
  float right;
  if(front < 70){
    analogWrite(fr, 0);
    while(front > 30){
    front = calcDist(frSen, frTrig);
    }
    brek(bk);
    delay(1000);
    float left = calcDist(lfSen, lfTrig);
    float right = calcDist(rtSen, rtTrig);
    if(left < 0){
     left = 10000;
    }
    if(right < 0){
      right = 10000;
    }
    Serial.print(left);
    Serial.println(right);
    if(left - right > 30 ){
      analogWrite(bk, 170);
      delay(775);
      analogWrite(bk, 0);
      delay(1000);
      analogWrite(fr, 150);
      analogWrite(lf, 255);
      delay(2300);
      analogWrite(lf, 0);
      analogWrite(fr, 0);
     
    }else if(right - left > 30){
      analogWrite(bk, 170);
      delay(775);
      analogWrite(bk, 0);
      delay(1000);
      analogWrite(fr, 150);
      analogWrite(rt, 255);
      delay(2300);
      analogWrite(rt, 0);
      analogWrite(fr, 0);
     
      
    }
  } else {
    analogWrite(fr, 120);
    if(left - right < -2 ){
      analogWrite(rt, 250);
      delay(100);
      analogWrite(rt, 0);
    }
    if(left - right > 2){
      analogWrite(lf, 250);
      delay(100);
      analogWrite(lf, 0);
    }
    delay(500);
  }
}
