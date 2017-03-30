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
  pinMode(rtTrig, OUTPUT);
  pinMode(lfTrig, OUTPUT);
  pinMode(fr, OUTPUT);
  pinMode(bk, OUTPUT);
  pinMode(lf, OUTPUT);
  pinMode(rt, OUTPUT);
  pinMode(lfSen, INPUT);
  pinMode(rtSen, INPUT);

  delay(1000);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(fr, 130);
  float left = calcDist(lfSen, lfTrig);
  float right = calcDist(rtSen, rtTrig);
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
  delay(200);
}
