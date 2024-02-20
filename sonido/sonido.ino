int LED = 13 ; 
int sensor = 6 ;
bool estado = false ;

void setup()
{
  pinMode( LED, OUTPUT) ;
  pinMode( sensor , INPUT_PULLUP) ;
  digitalWrite(LED , LOW) ; // Apagamos el LED al empezar
  Serial.begin(9600);
}

void loop()
{
  bool  valor =  digitalRead(sensor) ; //leemos el estado del sensor
  if ( valor == true ) //Si está activada la salida D0
  {
    estado = ! estado ;                       // cambiamos el estado del LED
    digitalWrite(LED, estado) ;            // escribimos el nuevo valor
    delay (1000);
  }
  int Lectura = analogRead(A0) ;
  Serial.println( Lectura);
}
