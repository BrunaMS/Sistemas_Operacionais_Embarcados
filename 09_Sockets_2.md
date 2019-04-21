1. Crie dois programas em C para criar um cliente e um servidor. Faça com que o cliente envie os valores 1, 2, 3, 4, 5, 6, 7, 8, 9 e 10 para o servidor, com intervalos de 1 segundo entre cada envio. Depois de o cliente enviar o número 10, ele aguarda 1 segundo e termina a execução. O servidor escreve na tela cada valor recebido, e quando ele receber o valor 10, ele termina a execução.
`Feito`
```C
			// Servidor Local
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/un.h>

char socket_name[]="socket";
int socket_id;
void sigint_handler(int signum);
void print_client_message(int client_socket);
void end_server(void);

int main (int argc, char* const argv[])
{
	struct sockaddr socket_struct;
	int count=1;

	// Definindo o tratamento de SIGINT
	//signal(SIGINT, sigint_handler);
	
	// Abrindo o socket local
	socket_id = socket(PF_LOCAL, SOCK_STREAM, 0);

	// Ligando o socket ao endereco local "socket_name"
	socket_struct.sa_family = AF_LOCAL;
	strcpy(socket_struct.sa_data, socket_name);
	bind(socket_id, &socket_struct, sizeof(socket_struct));
	
	// Tornando o socket passivo (para virar um servidor)
	listen(socket_id, 10);

	while(count<=10)
	{
		struct sockaddr cliente;
		int socket_id_cliente;
		socklen_t cliente_len;
		
		// Aguardando a conexao de um cliente
		socket_id_cliente = accept(socket_id, &cliente, &cliente_len);

		// Obtendo a informacao transmitida pelo cliente
		write(socket_id_cliente, &count, sizeof(int));

		print_client_message(socket_id_cliente);
		count++;
		sleep(1);
		// Fechando a conexao com o cliente
		close(socket_id_cliente);

	}
	return 0;
}

void sigint_handler(int signum)
{
	fprintf(stderr, "\nRecebido o sinal CTRL+C... vamos desligar o servidor!\n");
	end_server();
}

void print_client_message(int client_socket)
{
	int count;	
	//fprintf(stderr, "\nMensagem enviada pelo cliente tem ");
	read(client_socket, &count, sizeof (int));
	printf("Contador = %d\n\n", count);
	if(count==10)
	{
		sleep(1);
		exit(1);
	}	

}

void end_server(void)
{
	// Apagando "socket_name" do sistema
	unlink(socket_name);
	// Fechando o socket local
	close(socket_id);
	exit(0);
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
