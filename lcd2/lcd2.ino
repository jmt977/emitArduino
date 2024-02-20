#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x27 y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,16,2);  //
byte cara[8] = {
B00000,
B10001,
B00000,
B00000,
B10001,
B01110,
B00000};

byte E[8] = {
  B11111,
  B11111,
  B00000,
  B11011,
  B11011,
  B00000,
  B11111,
  B11111};  

byte T[8] = {
  B11111,
  B00100,
  B10100,
  B10100,
  B10100,
  B10100,
  B10100,
  B10100};
void setup() {
  // Inicializar el LCD
  lcd.begin();
  
  //Encender la luz de fondo.
  lcd.backlight();
  
  //creamos los nuevos caracteres
  lcd.createChar (0,E);
  lcd.createChar (1,T);
  lcd.createChar (2,cara);
  // mostramos en la primera linea
  lcd.setCursor(0, 0); 
  lcd.write (byte (0));
  lcd.write (byte (1));
  lcd.print(" Escuela IT");
  lcd.print(" ");
  lcd.write (byte (0));
  lcd.write (byte (1));
  
  // mostramos en la segunda linea
  lcd.setCursor(0, 1);  
  lcd.write (byte (2));  
  lcd.setCursor(2, 1);  
  lcd.print("Tandil  2024");
  lcd.setCursor(15, 1);  
  lcd.write (byte (2));   
}

void loop () {}
