void obstaculo() {
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