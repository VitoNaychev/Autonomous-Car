float calcDist(int sens, int trig){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);  
  int dur = pulseIn(sens, HIGH);
  float len = dur*0.034029/2;
  return len;
}

