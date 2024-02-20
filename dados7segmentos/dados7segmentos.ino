// Array multidimensional para mostrar los números
byte  numero[10][8] =
{
  { 1, 1, 1, 1, 1, 1, 0, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1, 0 }, // 2
  { 1, 1, 1, 1, 0, 0, 1, 0 }, // 3
  { 0, 1, 1, 0, 0, 1, 1, 0 }, // 4
  { 1, 0, 1, 1, 0, 1, 1, 0 }, // 5
  { 1, 0, 1, 1, 1, 1, 1, 0 }, // 6
  { 1, 1, 1, 0, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1, 0 }, // 8
  { 1, 1, 1, 0, 0, 1, 1, 0 } // 9
};

void setup() {
  // Iniciamos el monitor serie
  Serial.begin(9600);

  // Ponemos los pines de los segmentos en modo OUTPUT (salida)
  for (int i = 2; i < 9; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {

    //Genera un numero aleatorio entre 1 y 6
    int randomNumber = random(0, 9);

    // Ponemos los pines en estado correcto para mostrar el número randomNumber
    for (int e = 0; e < 8; e++){
      digitalWrite(e + 2, numero[randomNumber][e]);
    }

    delay(500);
}
