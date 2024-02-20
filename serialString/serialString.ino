//Cómo leer una cadena de caracteres por el serie
const int Led=13;
void setup(){
   Serial.begin(9600); 
   pinMode(Led, OUTPUT);
}

void loop(){
   if (Serial.available()){
      String data = Serial.readStringUntil('\n');
      if (data=="Hola"){
        digitalWrite(Led, HIGH);
        Serial.println("Comando reconocido");
      }
       else{
        digitalWrite(Led, LOW);
        Serial.println("Comando no reconocido");
      }
   }
}
