1. Especifique algumas portas importantes pré-definidas para o protocolo TCP/IP.

2. Com relação a endereços IP, responda:

(a) Qual é a diferença entre endereços IP externos e locais?

IPs externos se referem a uma identificação em termos globais, porém dinâmicos. Ou seja, um IP externo é único, porém pode variar.

IPs local são utilizados para identificar o dispositivo em uma rede interna e local. Esse IP pode ser fixo ou gerenciado pelo roteador, evitando o risco de conflitos (mais de um dispositivo com o mesmo IP).


(b) Como endereços IP externos são definidos? Quem os define?

IPs externos são fornecidos pelo aparelho que conecta a rede local à internet (modems e roteadores), chamados Gateway padrão.


(c) Como endereços IP locais são definidos? Quem os define?

IPs locais são definidos pelo roteador ao qual se está conectado e pode ser encontrado por endereço IPv4.


(d) O que é o DNS? Para que ele serve?

Domain Name Structure. Ele traduz as URLs em endereços
IP de sites.

3. Com relação à pilha de protocolos TCP/IP, responda:

(a) O que são suas camadas? Para que servem?

São divisões lógicas, de acordo com a tarefa que parte realiza. Cada camada descreve o envio de datagramas mais detalhadamente. 

(b) Quais são as camadas existentes? Para que servem?

- Aplicação - Comunicação entre processos.

- Transporte - Comunicação entre dispositivos.

- Internet (rede) - Comunicação entre diferentes servidores/ redes.

- Link (enlace) - Roteador. Conexão entre o ambiente local e o externo.


(c) Quais camadas são utilizadas pela biblioteca de sockets?

Internet.


(d) As portas usadas por servidores na função bind() se referem a qual camada?

Aplicação - Um servidor usa o procedimento bind para prover um número de porta de protocolo em que o servidor esperará por contato.


(e) Os endereços usados por clientes na função connect() se referem a qual camada?

Aplicação - cria uma conexão entre dois sockets.


4. Qual é a diferença entre os métodos `GET` e `POST` no protocolo HTTP?

Quando utilizamos o GET, os parâmetros são passados no cabeçalho da requisição. 

O POST envia os parâmetros no corpo da requisição HTTP. Escondendo eles da URI.
