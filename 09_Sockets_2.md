1. Crie dois programas em C para criar um cliente e um servidor. Faça com que o cliente envie os valores 1, 2, 3, 4, 5, 6, 7, 8, 9 e 10 para o servidor, com intervalos de 1 segundo entre cada envio. Depois de o cliente enviar o número 10, ele aguarda 1 segundo e termina a execução. O servidor escreve na tela cada valor recebido, e quando ele receber o valor 10, ele termina a execução.
`Feito`
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main (int argc, char* const argv[])
{
	char *socket_name;
	char *mensagem;

	int socket_id;
	struct sockaddr name;
	int length;

	if (argc < 3)
	{
		puts("   Este programa cria um cliente que se comunica");
		puts("   a um servidor local no caminho especificado");
		puts("   pelo usuario. Para permitir que o cliente comunique-se");
		puts("   com este servidor, o servidor deve ser");
		puts("   executado inicialmente com um caminho definido,");
		puts("   e o cliente devera ser executado em outra");
		puts("   janela ou em outra aba do terminal, utilizando");
		puts("   o mesmo caminho. O servidor escreve na tela");
		puts("   todo texto enviado pelo cliente. Se o cliente");
		puts("   transmitir o texto \"sair\", o servidor se");
		puts("   encerra. Se o usuario pressionar CTRL-C para");
		puts("   o servidor, ele tambem se encerra.");
		puts("   Modo de Uso:");
		printf("      %s <caminho_do_socket> <mensagem>\n", argv[0]);
		printf("   Exemplo: %s /tmp/socket1 \"Ola socket\"\n", argv[0]);
		exit(1);
	}
	socket_name = argv[1];
	mensagem = 0;

	// Abrindo o socket local
	socket_id = socket(PF_LOCAL, SOCK_STREAM,0);
	
	//Conectando o socket ao servidor no endereco local "socket_name"
	name.sa_family = AF_LOCAL;
	strcpy(name.sa_data, socket_name);
	connect(socket_id, &name, sizeof(name));
	
	for(mensagem=1;mensagem<=10;mensagem++)
	{
		// Mandando mensagem ao servidor
		length = 1;
		write(socket_id, &length, sizeof(int));
		write(socket_id, mensagem, length);
		sleep(1000);
	}
	// Fechando o socket local
	close(socket_id);
	return 0;
}
```

2. Crie dois programas em C para criar um cliente e um servidor. Execute a seguinte conversa entre cliente e servidor:

```
CLIENTE: Pai, qual é a verdadeira essência da sabedoria?
SERVIDOR: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.
CLIENTE: Mas até uma criança de três anos sabe disso!
SERVIDOR: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...
```

Neste exercício, o cliente deve escrever no terminal as mensagens enviadas e recebidas.
