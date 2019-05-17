1. Cite as vantagens e desvantagens da comunicação serial:

(a) Assíncrona (UART).
```
- Possui um "Start bit", indicando o começo da transmissão (um bit em nível baixo)
- Bits de transmissão enviados em serial
- Pode escolher entre LSB ou MSB
- Possui um "Stop bit", indicando o fim da transmissão (um bit ou dois bits em nível alto)
- Não há sinal de clock, a temporização dos bits deve ser breviamente conhecida pelo transmissor e pelo receptor.
- Pode-se enviar 7 ou 8 bits de informação.
- Pode-se acrescentar o envio de endereço, no caso de múltiplos transmissores e receptores. (TX e RX)
```

(b) SPI.
```
- Síncrono
- Clock enviado junto com os dados
- Precisa de 3 fios: clock, transmissão, recepção e clock
- Permite comunicação full duplex
- Permite mais de um escravo (identificado através de um quarto fio)
- Usa MISO e MOSI

```

2. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, e que a comunicação entre os dois é UART. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?
``` 
Não precisa de avisos porque o próprio MSP já envia os bits de início e término de antes e depois do envio da informação. Além disso, esse formato é assíncrono, ou seja, não atua com base em um intervalo de tempo estabelecido.  
```

3. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, que a comunicação entre os dois seja SPI, e que o MSP430 seja o escravo. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?
```
Deve aguardar, principalmente por que ele é sincrono, o que faz com que ele tenha que esperar o sinal de clock para transmitir a informação.
``` 

4. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via UART, como executar a comunicação com o segundo dispositivo?
```
Enviando, juntamente os dados, o endereço do escravo. 
```
5. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via SPI, como executar a comunicação com o segundo dispositivo?
```Acrescentando um 4º fio na conexão, que irá transmitir a identificação do escravo.```
