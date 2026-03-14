String casos() {
  int valorSensorExtEsq = analogRead(sensorExtEsq) <= valorPreto ? 1 : 0;
  int valorSensorEsq = analogRead(sensorEsq) <= valorPreto ? 1 : 0;
  int valorSensorMeio = analogRead(sensorMeio) <= valorPreto ? 1 : 0;
  int valorSensorDir = analogRead(sensorDir) <= valorPreto ? 1 : 0;
  int valorSensorExtDir = analogRead(sensorExtDir) <= valorPreto ? 1 : 0;

  String caso = String(valorSensorExtEsq) + String(valorSensorEsq) + String(valorSensorMeio) + String(valorSensorDir) + String(valorSensorExtDir);
  return caso;
}

void segueLinha() {
  String casoIdentificado = casos();

  if (casoIdentificado == "00000") {
    andar("F", velocidadeConstante);
  } else if (casoIdentificado == "00001" || casoIdentificado == "00010" || casoIdentificado == "00011" || casoIdentificado == "00111") {
    curvaEixo("D", velocidadeCurvas);
  } else if (casoIdentificado == "10000" || casoIdentificado == "01000" || casoIdentificado == "11000" || casoIdentificado == "11100") {
    curvaEixo("E", velocidadeCurvas);
  } else if (casoIdentificado == "11111") {
    detectaCor();
  } else {
    andar("F", velocidadeConstante);
  }
}