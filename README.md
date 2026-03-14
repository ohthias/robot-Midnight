# 🌙 Robot Midnight

Projeto de robô autônomo seguidor de linha, com detecção de cores e obstáculos, desenvolvido como base para participação na OBR (Olimpíada Brasileira de Robótica) na modalidade Resgate

## Funcionalidades
- Seguimento de linha com sensores refletivos
- Identificação de cores para tomada de decisão
- Detecção e desvio de obstáculos
- Controle de velocidade e direção dos motores

## Estrutura do Projeto
```
robot-Midnight/
  │
  ├── midnight.ino            # Arquivo principal do robô
  ├── configMotores.ino       # Configuração e controle dos motores
  ├── configSensorCor.ino     # Configuração do sensor de cor
  ├── identificarCor.ino      # Algoritmo de classificação de cores
  ├── segueLinha.ino          # Lógica de line follower
  ├── obstaculo.ino           # Detecção e desvio de obstáculos
  ├── libs/                   # Bibliotecas utilizadas
  └── README.md
```
