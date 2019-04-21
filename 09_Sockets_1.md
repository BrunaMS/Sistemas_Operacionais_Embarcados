1. Com relação ao modelo cliente-servidor, responda:

(a) Quais são as características básicas deste modelo?

- Possibilita a comunicação através de rede de computadores.

- Um processo pode utilizar socket para se comunicar com outro processo utilizando um modelo cliente/servidor tanto através da rede quanto internamente em uma mesma máquina.

- Cada socket tem diversos parâmetros e opções.


(b) Quais são as características básicas do servidor?

- Aguarda passivamente

- Responde aos clientes

- Socket passivo


(c) Quais são as características básicas do cliente?

- Inicia a comunicação

- Deve saber o endereço e a porta do servidor

- Socket ativo


2.  Com relação ao protocolo de comunicação da internet, responda:

(a) O que são protocolos de comunicação?

É uma forma de identificação do meio que será usado para que o socket invie e receba mensagens (IPPROTO_TCP, IPPROTO_UDP ou 0 para protocolo padrão).

Define o local onde os parâmetros são passados.


**Ex.:** TCP/IP, IPV4 (Família PF_INET), Comunicação local e Endereço de arquivos (Família PF_UNIX/PF_LOCAL) ou protocolos da Digital Equipment Corporation (Família PF_DECnet).


(b) Quais são as características básicas de protocolos de comunicação?

- Um servidor que usa um protocolo de transporte orientado à conexão exige passos adicionais antes de poder receber mensagens.

- Um servidor que usa um protocolo de transporte sem conexão está pronto para aceitar mensagens.

- Cada protocolo possui um endereço específico e uma família à qual pertence.


3. Com relação ao protocolo TCP, responda:

(a) O que são portas no protocolo TCP?

O ponto específico que será usado para realizar a comunicação entre os servidores.

(b) Para que servem estas portas?

- Para permitir que um servidor opere em um host com múltiplas
interfaces;

- Para identificar por onde os arquivos serão enviados e recebidos dentro de um servidor.
