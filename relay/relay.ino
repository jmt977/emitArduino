void setup() {
  // initialize the digital pin as an output.
  pinMode(7, OUTPUT);
}

void loop() {
  digitalWrite(7, HIGH);   // turn the BULB on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(7, LOW);    // turn the BULB off by making the voltage LOW
  delay(1000);               // wait for a second
}
