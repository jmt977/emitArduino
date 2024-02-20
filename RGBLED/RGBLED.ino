const int ledRojo = 3;
const int ledVerde = 5;
const int ledAzul = 6;
int valor=0;
 
void setup() {
  pinMode(ledRojo,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  pinMode(ledAzul,OUTPUT);
}
void loop() {
//Hacer color rojo
  analogWrite(ledRojo,255);
  analogWrite(ledVerde,0);
  analogWrite(ledAzul,0);
  delay(1500);
  switch (ledVerde){
    case 1: valor=44; break;
    case 2: valor =67;break;
    default: valor=9;
  }

  analogWrite(ledRojo,0);
  analogWrite(ledVerde,255);
  analogWrite(ledAzul,0);
  delay(1500);

  analogWrite(ledRojo,0);
  analogWrite(ledVerde,0);
  analogWrite(ledAzul,255);
  delay(1500);

  analogWrite(ledRojo,127);
  analogWrite(ledVerde,127);
  analogWrite(ledAzul,0);
  delay(1500);
}
