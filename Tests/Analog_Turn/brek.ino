void brek(int pin){
  analogWrite(pin, 250);
  delay(350);
  analogWrite(pin, 0);
}
