#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <SharpIR.h>

// Expansor de portas de conexão
#define PCA9548A_ADDR 0x70

// Sensores TCS34725
Adafruit_TCS34725 sensorCorEsquerda = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
Adafruit_TCS34725 sensorCorDireita = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
float hue, saturation, brightness;

// Sensores segue-linha
#define sensorExtEsq A1
#define sensorEsq A2
#define sensorMeio A3
#define sensorExtDir A4
#define sensorDir A5

// Motores
const int motorDireitaFrente = 2;
const int motorDireitaTras = 3;
const int motorEsquerdaFrente = 4;
const int motorEsquerdaTras = 5;

// Velocidade dos motores
const int velocidadeConstante = 240;
int velocidadeCurvas = 235;
int velocidadeCurvasRe = 220;

// SHARP
SharpIR sensorDistancia(SharpIR::GP2Y0A41SK0F, A0);

// Calibração
int valorPreto = 200;

void setup() {
  pinMode(motorDireitaFrente, OUTPUT);
  pinMode(motorDireitaTras, OUTPUT);
  pinMode(motorEsquerdaFrente, OUTPUT);
  pinMode(motorEsquerdaTras, OUTPUT);

  Serial.begin(9600);
  Wire.begin();
  canalSensor(0);
  if (!sensorCorEsquerda.begin()) {
      Serial.println("Sensor no canal 0 não detectado!");
  } else {
      Serial.println("Sensor no canal 0 pronto!");
  }
  
  canalSensor(1);
  if (!sensorCorDireita.begin()) {
      Serial.println("Sensor no canal 0 não detectado!");
  } else {
      Serial.println("Sensor no canal 0 pronto!");
  }
  
}

void loop() {
  bool obstaculoIdentificado = sensorDistancia.getDistance() <= 10;
  if(!obstaculoIdentificado) {
    segueLinha();
  } else {
    obstaculo();
  }
}