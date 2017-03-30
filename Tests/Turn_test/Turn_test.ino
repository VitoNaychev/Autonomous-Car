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

void brek(int pin);

void setup() {
  // put your setup code here, to run once:
  pinMode(frTrig, OUTPUT);
  
  pinMode(fr, OUTPUT);
  pinMode(bk, OUTPUT);
  pinMode(lf, OUTPUT);
  pinMode(rt, OUTPUT);
  pinMode(frSen, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  
  float frDist = calcDist(frSen, frTrig);
  
  if(frDist < 40){
    analogWrite(fr, 0);
    brek(bk);
    delay(2000);
    analogWrite(bk, 170);
    delay(780);
    analogWrite(bk, 0);
    delay(1000);
    analogWrite(fr, 150);
    digitalWrite(lf, HIGH);
    delay(2200);
    digitalWrite(lf, LOW);
    analogWrite(fr, 0);
    brek(bk);    
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
void brek(int pin){
  analogWrite(pin, 250);
  delay(290);
  analogWrite(pin, 0);
}

