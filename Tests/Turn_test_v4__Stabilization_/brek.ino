void brek(int pin){
  analogWrite(pin, 220);
  delay(500);
  analogWrite(pin, 0);
}
