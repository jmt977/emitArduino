const int Luz=9,Ventilador=8;
void setup() {
  pinMode(Luz, OUTPUT);
  pinMode(Ventilador, OUTPUT);
  digitalWrite(Luz,HIGH);
  digitalWrite(Ventilador,HIGH);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() == 0); // si llego un caracter por linea serie
  char val = Serial.read(); // lee el caracter en una variable
  switch (val) {
    case 'L':
      digitalWrite(Luz,LOW);
      Serial.println("L - Luz encendida");
      break;
    case 'l':
      digitalWrite(Luz,HIGH);
      Serial.println("l - Luz apagada");
      break;
    case 'V':
      digitalWrite(Ventilador,LOW);
      Serial.println("V - Ventilador encendido");
      break;
    case 'v':
      digitalWrite(Ventilador,HIGH);
      Serial.println("v - Ventilador apagado");
      break;
    }
}
