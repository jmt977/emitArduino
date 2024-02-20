#include <IRremote.h>
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);


void setup() {                
  // initialize the digital pin as an output.
  pinMode(RECV_PIN, INPUT);  
  pinMode(LED_BUILTIN, OUTPUT);  
  irrecv.enableIRIn(); // Start the receiver
  Serial.begin(9600);
}
void loop() {

  if (irrecv.decode()) {
    translateIR();
    irrecv.resume(); // Receive the next value
  }   
}

// takes action based on IR code received describing Car MP3 IR codes 
 void translateIR(){
  switch(irrecv.decodedIRData.command){
  case 0x45:  
    Serial.println(" CH-            "); 
    break;
  case 0x46:  
    Serial.println(" CH             "); 
    break;
  case 0x47:  
    Serial.println(" CH+            "); 
    break;
  case 0x44:  
    Serial.println(" PREV        "); 
    digitalWrite(LED_BUILTIN,LOW);
    break;
  case 0x40:  
    Serial.println(" NEXT        "); 
    digitalWrite(LED_BUILTIN, HIGH);
    break;
  case 0x43:  
    Serial.println(" PLAY/PAUSE     "); 
    break;
  case 0x7:  
    Serial.println(" VOL-           "); 
    break;
  case 0x15:  
    Serial.println(" VOL+           "); 
    break;
  case 0x9:  
    Serial.println(" EQ             "); 
    break;
  case 0x16:  
    Serial.println(" 0              "); 
    break;
  case 0x19:  
    Serial.println(" FOL-           "); 
    break;
  case 0xD:  
    Serial.println(" FOL+           "); 
    break;
  case 0xC:  
    Serial.println(" 1              "); 
    break;
  case 0x18:  
    Serial.println(" 2              "); 
    break;
  case 0x5E:  
    Serial.println(" 3              "); 
    break;
  case 0x8:  
    Serial.println(" 4              "); 
    break;
  case 0x1C:  
    Serial.println(" 5              "); 
    break;
  case 0x5A:  
    Serial.println(" 6              "); 
    break;
  case 0x42:  
    Serial.println(" 7              "); 
    break;
  case 0x52:  
    Serial.println(" 8              "); 
    break;
  case 0x4A:  
    Serial.println(" 9              "); 
    break;
  default: 
    Serial.print(" unknown button   ");
    Serial.println(irrecv.decodedIRData.command, HEX);
  }
  delay(500);
} 
                  
