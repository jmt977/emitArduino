#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x27 y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,16,2);  //

void setup() {
  // Inicializar el LCD
  lcd.begin();
  
  //Encender la luz de fondo.
  lcd.backlight();
  
  // Escribimos el Mensaje en el LCD en una posición  central.
  lcd.setCursor(0, 0);
  lcd.print("Escuela de Talentos");
  lcd.setCursor(0, 1);
  lcd.print("Tutorial de desplazamiento  ");
}

void loop() {
  //desplazamos una posición a la izquierda
  lcd.scrollDisplayLeft(); //   lcd.scrollDisplayRight(); 
  delay(500);
}
