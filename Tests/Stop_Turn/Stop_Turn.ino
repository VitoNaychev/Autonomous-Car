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
  pinMode(lfSen, INPUT);
  pinMode(lfTrig, OUTPUT);
  pinMode(rtSen, INPUT);
  pinMode(rtTrig, OUTPUT);
  
  pinMode(fr, OUTPUT);
  pinMode(bk, OUTPUT);
  pinMode(lf, OUTPUT);
  pinMode(rt, OUTPUT);
  
  
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  Serial.print(calcDist(lfSen, lfTrig));
  Serial.print(" <- Left  Right ->");
  Serial.println(calcDist(rtSen, rtTrig));
}
