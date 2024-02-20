void setup(){
  Serial.begin(9600);
}

void loop(){
  int Lectura = analogRead(A0) ;
  Serial.println( Lectura);
}
