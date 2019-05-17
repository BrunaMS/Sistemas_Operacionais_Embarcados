1. Com relação às conexões GPIO do modelo de Raspberry Pi que você usará no projeto, responda:

(a) Quais pinos podem ser utilizados como entradas e saídas digitais comuns?
```
Até o dado momento, apenas o pino GPIO 1, que será usado como PWM.

Os demais serão utilizados com conversores A/D e D/A e conexão I2C.
```
(b) Quais pinos possuem resistores de pull-up e pull-down?
```
Nenhum, até o momente.
```

(c) Quais formas de comunicação serial são suportados pelos pinos GPIO?
```
Bit-banging, SPI, I2C e assíncrona.
```

2. Apresente outras 3 bibliotecas de acesso I/O em C para o Raspberry Pi.
```
unistd.h, wiringPi, stdio.h
```
