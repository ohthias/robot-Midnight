/**
  * Robô Midnight - Base para OBR
  * Desenvolvido por: Matheus Gabriel Santos Silva (@ohthias)
  * Data: 2026-03
  * Este código é a base para um robÔ projetado para competições de robótica como a OBR na modalidade de resgate. Ele inclui funcionalidades para seguir linhas, detectar cores e desviar de obstáculos usando sensores TCS34725, TCRT5000 e um sensor de distância Sharp IR.
  */

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
float distanciaFiltrada = 0;

// Calibração
int valorPreto = 200;

// Rotinas
enum rotinas {
  LINHA,
  OBSTACULO,
  RESGATE
};
rotinas estadoAtual = LINHA;

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
      Serial.println("Sensor no canal 1 não detectado!");
  } else {
      Serial.println("Sensor no canal 1 pronto!");
  }
  
}

void loop() {
  lerDistancia();
  switch(estadoAtual) {
    case LINHA:
      if(distanciaFiltrada <= 10) {
        estadoAtual = OBSTACULO;
        break;
      }
      segueLinha();
      break;
    case OBSTACULO:
      desvioObstaculo();
      estadoAtual = LINHA;
      break;
    case RESGATE:
      realizarResgate();
      break;
  }
}