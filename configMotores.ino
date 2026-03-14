void andar(char sentido, int velocidade) {
  switch(sentido) {
    case 'F':
      analogWrite(motorDireitaFrente, velocidade);
      analogWrite(motorDireitaTras, 0);
      analogWrite(motorEsquerdaFrente, velocidade);
      analogWrite(motorEsquerdaTras, 0);
      break;

    case 'R':
      analogWrite(motorDireitaFrente, 0);
      analogWrite(motorDireitaTras, velocidade);
      analogWrite(motorEsquerdaFrente, 0);
      analogWrite(motorEsquerdaTras, velocidade);
      break;

    default:
      analogWrite(motorDireitaFrente, 0);
      analogWrite(motorDireitaTras, 0);
      analogWrite(motorEsquerdaFrente, 0);
      analogWrite(motorEsquerdaTras, 0);;
      break;
  }
}

void curvaEixo(char sentido, int velocidade) {
  switch(sentido) {
    case 'D':
      analogWrite(motorDireitaFrente, 0);
      analogWrite(motorDireitaTras, velocidade);
      analogWrite(motorEsquerdaFrente, velocidade);
      analogWrite(motorEsquerdaTras, 0);
      break;

    case 'E':
      analogWrite(motorDireitaFrente, velocidade);
      analogWrite(motorDireitaTras, 0);
      analogWrite(motorEsquerdaFrente, 0);
      analogWrite(motorEsquerdaTras, velocidade);
      break;
  }
}

void curvaNoventa(char sentido, int velDir, int velEsq) {
  if (sentido == 'D') {
    analogWrite(motorDireitaFrente, 0);
    analogWrite(motorDireitaTras, velDir);
    analogWrite(motorEsquerdaFrente, velEsq);
    analogWrite(motorEsquerdaTras, 0);
  } else if (sentido == 'E') {
    analogWrite(motorDireitaFrente, velDir);
    analogWrite(motorDireitaTras, 0);
    analogWrite(motorEsquerdaFrente, 0);
    analogWrite(motorEsquerdaTras, velEsq);
  }
  delay(300);
}