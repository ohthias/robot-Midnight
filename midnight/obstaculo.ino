float lerDistancia() {
  float leitura = sensorDistancia.getDistance();
  distanciaFiltrada = 0.7*distanciaFiltrada+0.3*leitura;
  return distanciaFiltrada;
}

void desvioObstaculo() {
  andar("R", 80);
  delay(500);
  curvaNoventa("D", velocidadeCurvas, velocidadeCurvasRe);
  andar("F", velocidadeConstante);
  delay(2200);
  curvaNoventa("E", velocidadeCurvas, velocidadeCurvasRe);
  andar("F", velocidadeConstante);
  delay(6000);
  curvaNoventa("E", velocidadeCurvas, velocidadeCurvasRe);
  andar("F", velocidadeConstante);
  delay(2300);
  curvaNoventa("D", velocidadeCurvas, velocidadeCurvasRe);
}