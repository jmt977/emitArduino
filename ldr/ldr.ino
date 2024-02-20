int photocellPin = 0; // LDR and 10K pulldown registor are connected to A0
int photocellReading; // Variable to read the analog value

void setup(void) {
 // Initialize Serial Monitor
 Serial.begin(9600); 
}
 
void loop(void) {
 photocellReading = analogRead(photocellPin);

if (photocellReading <= 200) {
 Serial.println("DARK : Analog Value = " + String(photocellReading)); 
 }
 else if (photocellReading > 200 && photocellReading <= 500) {
 Serial.println("DIM LIGHT : Analog Value = " + String(photocellReading)); 
 } 
 else if (photocellReading > 500 && photocellReading <= 800) {
 Serial.println("BRIGHT LIGHT : Analog Value = " + String(photocellReading)); 
 } 
 else if (photocellReading > 800) {
 Serial.println("FULL DAY LIGHT : Analog Value = " + String(photocellReading)); 
 } 
 
 delay(100);
}
