#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  9    //Pin 9 para el reset del RC522

// para arduino uno/nano
//#define SS_PIN  10   //Pin 10 para el SS (SDA) del RC522

//para arduino mega
#define SS_PIN  53   //Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); ///Creamos el objeto para el RC522

#define Buzzer 12
#define Relay 11


void setup() {
  Serial.begin(9600); //Iniciamos La comunicacion serial
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, 0);
  SPI.begin();        //Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos el MFRC522
  Serial.println("Control de acceso por RFID");
}

byte ActualUID[4]; //almacenará el código del Tag leído
byte Usuario1[4]= {0x47, 0x51, 0xC8, 0x7A} ; //código del usuario 1
byte Usuario2[4]= {0x04, 0x74, 0xBA, 0x04} ; //código del usuario 2
//byte Usuario2[4]= {0x04, 0x74, 0xBA, 0x04} ; //código del usuario 2
void loop() {
  // Revisamos si hay nuevas tarjetas  presentes
  if ( mfrc522.PICC_IsNewCardPresent()) 
        {  
      //Seleccionamos una tarjeta
            if ( mfrc522.PICC_ReadCardSerial()) 
            {
                  // Enviamos serialemente su UID
                  Serial.print(F("Card UID:"));
                  for (byte i = 0; i < mfrc522.uid.size; i++) {
                          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                          Serial.print(mfrc522.uid.uidByte[i], HEX);   
                          ActualUID[i]=mfrc522.uid.uidByte[i];          
                  } 
                  Serial.println();                
                  //comparamos los UID para determinar si es uno de nuestros usuarios  
                  if(compareArray(ActualUID,Usuario1) || compareArray(ActualUID,Usuario2)){
                    Serial.print("Acceso autorizado con ");
                    if (compareArray(ActualUID,Usuario2)) Serial.println("tarjeta SUMO");
                    else Serial.println("llavero");
                    digitalWrite(Relay,1);
                    noTone(Buzzer);
                    tone(Buzzer,840,1000);
                    delay(1000);
                    noTone(Buzzer);
                  }
                  else{
                    Serial.println("Acceso denegado...");
                    digitalWrite(Relay,0);
                    noTone(Buzzer);
                    tone(Buzzer,1840,1000);
                    delay(1000);
                    noTone(Buzzer);
                  }
                  
                  // Terminamos la lectura de la tarjeta tarjeta  actual
                  mfrc522.PICC_HaltA();
          
            }
      
  }
  
}

//Función para comparar dos vectores
 boolean compareArray(byte array1[],byte array2[])
{
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}
