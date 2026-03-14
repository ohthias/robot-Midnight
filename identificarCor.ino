String identificarCor(float hue, float sat, float val) {
    // PRETO (linha)
    if (val < 0.08) {
        return "PRETO";
    }
    // PRATA (reflexiva ou fosca)
    if (sat < 0.12 && val > 0.65) {
        return "PRATA";
    }
    // BRANCO
    if (sat < 0.18 && val > 0.35) {
        return "BRANCO";
    }
    // VERMELHO (circular)
    if (hue > 345 || hue < 12) {
        return "VERMELHO";
    }
    // VERDE ESCURO (OBR comum)
    if (hue >= 85 && hue < 115) {
        return "VERDE_ESCURO";
    }
    // VERDE NORMAL
    if (hue >= 115 && hue < 145) {
        return "VERDE";
    }
    // VERDE CLARO / FITA DESBOTADA
    if (hue >= 145 && hue < 170) {
        return "VERDE_CLARO";
    }
    // fallback
    return "DESCONHECIDO";
}

void detectaCor() {
  uint16_t r, g, b, c;
  String corDetectadaEsquerda, corDetectadaDireita;

  // Leitura do Sensor no Canal 0
  canalSensor(0);
  sensorCorEsquerda.getRawData(&r, &g, &b, &c);
  rgbToHSB(r, g, b);
  float val = c/65535.0;
  corDetectadaEsquerda = identificarCor(hue, saturation, val);

  Serial.print("Sensor Canal 0 - HUE: ");
  Serial.print(hue);
  Serial.print(" - Cor: ");
  Serial.println(corDetectadaEsquerda);

  // Leitura do Sensor no Canal 1
  canalSensor(1);
  sensorCorDireita.getRawData(&r, &g, &b, &c);
  rgbToHSB(r, g, b);
  val = c/65535.0;
  corDetectadaDireita = identificarCor(hue, saturation, val);

  Serial.print("Sensor Canal 1 - HUE: ");
  Serial.print(hue);
  Serial.print(" - Cor: ");
  Serial.println(corDetectadaDireita);

  if(corDetectadaEsquerda == "VERDE" && corDetectadaDireita == "VERDE") {
    curvaEixo("D", velocidadeCurvas);
    delay(3000);
  } else if(corDetectadaEsquerda == "VERDE_ESCURO" && corDetectadaDireita != "VERDE_ESCURO"){
    curvaNoventa("E", velocidadeCurvas, velocidadeCurvasRe);
  } else if(corDetectadaEsquerda != "VERDE_ESCURO" && corDetectadaDireita == "VERDE_ESCURO"){
    curvaNoventa("D", velocidadeCurvas, velocidadeCurvasRe);
  } else if(corDetectadaEsquerda == "VERDE" && corDetectadaDireita != "VERDE"){
    curvaNoventa("E", velocidadeCurvas, velocidadeCurvasRe);
  } else if(corDetectadaEsquerda != "VERDE" && corDetectadaDireita == "VERDE"){
    curvaNoventa("D", velocidadeCurvas, velocidadeCurvasRe);
  } else if(corDetectadaEsquerda == "VERDE_CLARO" && corDetectadaDireita != "VERDE_CLARO"){
    curvaNoventa("E", velocidadeCurvas, velocidadeCurvasRe);
  } else if(corDetectadaEsquerda != "VERDE_CLARO" && corDetectadaDireita == "VERDE_CLARO"){
    curvaNoventa("D", velocidadeCurvas, velocidadeCurvasRe);
  } else if(corDetectadaEsquerda == "VERMELHO" && corDetectadaDireita == "VERMELHO") {
    andar("", 0);
  } else if(corDetectadaEsquerda == "PRATA" && corDetectadaDireita == "PRATA") {
    // Resgate
  } else {
    andar("F", 100);
    delay(500);
  }
  delay(1000);
}