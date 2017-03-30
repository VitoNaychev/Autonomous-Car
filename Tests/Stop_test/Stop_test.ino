#include"autonomous.h"

int fr = 3;
int bk = 5;
int lf = 6;
int rt = 7;
int frSen = 8;
int bkSen = 9;
int frTrig = 12;
int bkTrig = 13;
int pstLen = 0;



void setup() {
  // put your setup code here, to run once:
  pinMode(frTrig, OUTPUT);
  pinMode(bkTrig, OUTPUT);
  pinMode(fr, OUTPUT);
  pinMode(bk, OUTPUT);
  pinMode(lf, OUTPUT);
  pinMode(rt, OUTPUT);
  pinMode(frSen, INPUT);
  pinMode(bkSen, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  
  float frDist = calcDist(frSen, frTrig);
//  if(frDist < 0){
//    frDist = 10000;
//  }
//  delay(200);
//  //frDist 20 -> 0, 255 -> 255
//  int frSp = map(frDist, 20, 255, 0, 255);
//  frSp = constrain(frSp, 0, 255);
//  //Prints
//  Serial.print("Dist: ");
//  Serial.print(frDist);
//  Serial.print(" Anal: ");
//  Serial.println(frSp);
//  //End prints
  
  if(frDist < 30){
    analogWrite(fr, 0);
    analogWrite(bk, 250);
    delay(290);
    analogWrite(bk, 0);
    delay(2000);
    analogWrite(bk, 200);
    delay(1000);
    analogWrite(bk, 0);
    delay(1000);
  }else{
    analogWrite(fr, 150);
  }
  
//  if(frDist < 80){
//   digitalWrite(fr, LOW);
//   digitalWrite(bk, HIGH);
//   delay(500);
//   digitalWrite(bk, LOW);
//   while(calcDist(frSen, frTrig) < 40);
//   delay(5000);
//  }else{
//    digitalWrite(fr, HIGH);
//    Serial.println("THERE!");
//  }
}


