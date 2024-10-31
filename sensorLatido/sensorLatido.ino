#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MAX30100_PulseOximeter.h>

// Configuración del LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Asegúrate de que 0x27 es la dirección I2C del LCD

// Configuración del sensor de oximetría
#define REPORTING_PERIOD_MS 1000 // Frecuencia de reporte
PulseOximeter pox;
uint32_t tsLastReport = 0;
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

void onBeatDetected() {
  Serial.println("Latido detectado!");
}

void setup() {
  // Inicializar la comunicación en serie
  Serial.begin(9600);

  // Inicializar el LCD
  lcd.begin();
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
  // Inicializar el sensor MAX30100
  if (!pox.begin()) {
    Serial.println("ERROR: No se pudo iniciar el MAX30100");
    while (1);
  } else {
    Serial.println("Sensor MAX30100 iniciado correctamente");
  }
  
  // Configurar la función de callback para detectar latidos
  pox.setOnBeatDetectedCallback(onBeatDetected);

  // Mostrar un mensaje inicial en el LCD
  lcd.setCursor(0, 0);
  lcd.print("Oximetro Iniciado");
}

void loop() {
  // Actualizar los datos del sensor
  pox.update();
  // Reportar datos cada cierto intervalo
  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
    tsLastReport = millis();

    // Obtener SpO2 y frecuencia cardíaca
    float bpm = pox.getHeartRate();
    float spO2 = pox.getSpO2();

    // Mostrar en el puerto serie
    Serial.print("BPM: ");
    Serial.print(bpm);
    Serial.print(" SpO2: ");
    Serial.println(spO2);

    // Mostrar en la pantalla LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write (byte (0));
    lcd.write (byte (1));
    
    lcd.print(" BPM: ");
    lcd.print(bpm);
    lcd.print(" ");
    lcd.write (byte (0));
    lcd.write (byte (1));
    lcd.setCursor(0, 1);
    lcd.print("SpO2: ");
    lcd.print(spO2);
    lcd.print("%");
  }
}
