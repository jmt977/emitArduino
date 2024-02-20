const int Do=261,Re=293,Mi=329,Fa=349,Sol=392,La=440,Si=493,buzzer=12;
int duracion = 1000,retardo = 1000;
void setup() {
   pinMode(buzzer, OUTPUT);
}
void loop() {
   tone(buzzer, Do, duracion);
   delay(retardo);
   tone(buzzer, Re, duracion);
   delay(retardo);
    tone(buzzer, Mi, duracion);
   delay(retardo);
   tone(buzzer, Fa, duracion);
   delay(retardo);
   tone(buzzer, Sol, duracion);
   delay(retardo);
   tone(buzzer, La, duracion);
   delay(retardo);
    tone(buzzer, Si, duracion);
   delay(retardo);
}
