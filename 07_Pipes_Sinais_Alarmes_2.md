1. Crie um programa em C que cria um processo-filho e um pipe de comunicação. Faça com que o processo-pai envie os valores 1, 2, 3, 4, 5, 6, 7, 8, 9 e 10 para o processo-filho, com intervalos de 1 segundo entre cada envio. Depois de o processo-pai enviar o número 10, ele aguarda 1 segundo e termina a execução. O processo-filho escreve na tela cada valor recebido, e quando ele receber o valor 10, ele termina a execução.
```C

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int i=1, nro;
	int pid;	
	int fd[2];	
	
	pipe(fd);
	pid = fork();

	if(pid == 0)
	{	
		for(i=1;i<=10;i++)
		{
			if(read(fd[0], &nro, sizeof(int)) < 0)
				printf("Erro na leitura do pipe\n");
			else	
				printf("%d\n", nro);
		}	
	}

	else
	{
		for(i=1;i<=10;i++)
		{
			if (write(fd[1], &i, sizeof(int)) < 0)
				printf("Erro na escrita do pipe\n");
			sleep(1);
		}
	}
	return 0;
}
```
2. Crie um programa em C que cria um processo-filho e um pipe de comunicação. Utilize o pipe para executar a seguinte conversa entre processos:

```
FILHO: Pai, qual é a verdadeira essência da sabedoria?
PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.
FILHO: Mas até uma criança de três anos sabe disso!
PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...
```
Neste exercício, quem recebe a mensagem via pipe é quem as escreve no terminal.

```C


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int i=1, nro;
	int pid;	
	int fd[2];	
	char msg[100], rcv[100];
	pipe(fd);
	pid = fork();

	if(pid == 0)
	{
		strcpy(msg,"FILHO: Pai, qual é a verdadeira essência da sabedoria?");
		if (write(fd[1], msg, sizeof(msg)) < 0)
			printf("Erro na escrita do pipe\n");
		else
		{
			sleep(5);
			if (read(fd[0], rcv, sizeof(msg)) < 0)
				printf("Erro na escrita do pipe\n");
			else
			{
				printf("%s\n", rcv);
				strcpy(msg,"FILHO: Mas até uma criança de três anos sabe disso!");
				if (write(fd[1], msg, sizeof(msg)) < 0)
					printf("Erro na escrita do pipe\n");
				else
				{
					sleep(1);
					if (read(fd[0], rcv, sizeof(msg)) < 0)
						printf("Erro na escrita do pipe\n");
					else
						printf("%s\n", rcv);
				}
			}
		}

	}

	else
	{
		sleep(5);
		strcpy(msg,"PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.");
		if (write(fd[1], msg, sizeof(msg)) < 0)
			printf("Erro na escrita do pipe\n");
		else
		{
			sleep(5);
			if (read(fd[0], rcv, sizeof(msg)) < 0)
				printf("Erro na escrita do pipe\n");
			else
			{
				printf("%s\n", rcv);
				strcpy(msg,"PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...");
				if (write(fd[1], msg, sizeof(msg)) < 0)
					printf("Erro na escrita do pipe\n");
				else
				{
					sleep(1);
					if (read(fd[0], rcv, sizeof(msg)) < 0)
						printf("Erro na escrita do pipe\n");
					else
						printf("%s\n", rcv);
				}
			}
		}
	}
	return 0;
}
```


3. Crie um programa em C que cria dois processos-filhos e um pipe de comunicação. Utilize o pipe para executar a seguinte conversa entre processos:

```
FILHO1: Quando o vento passa, é a bandeira que se move.
FILHO2: Não, é o vento que se move.
PAI: Os dois se enganam. É a mente dos senhores que se move.
```

Neste exercício, quem recebe a mensagem via pipe é quem as escreve no terminal.
```C

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pid, pid_1;	
	int fd[2];	
	char msg[100], rcv[100];
	pipe(fd);
	pid = fork();

	if(pid == 0)
	{
		strcpy(msg,"FILHO1: Quando o vento passa, é a bandeira que se move.");
		pid_1 = getpid();
		
		if (write(fd[1], msg, sizeof(msg)) < 0)
			printf("Erro na escrita do pipe\n");
		else
		{
			sleep(2);
			if (read(fd[0], rcv, sizeof(msg)) < 0)
				printf("Erro na leitura do pipe\n");
			else
			{
				printf("%s\n", rcv);
				pid = fork();

				if(getpid() != pid_1)
				{
					strcpy(msg,"FILHO2: Não, é o vento que se move.");
					if (write(fd[1], msg, sizeof(msg)) < 0)
						printf("Erro na escrita do pipe\n");
					else
					{
						sleep(2);
						if (read(fd[0], rcv, sizeof(msg)) < 0)
							printf("Erro na leitura do pipe\n");
						else
							printf("%s\n", rcv);
					}
				}
			}
		}

	}

	else
	{
		sleep(5);
		strcpy(msg,"PAI: Os dois se enganam. É a mente dos senhores que se move.");
		if (write(fd[1], msg, sizeof(msg)) < 0)
			printf("Erro na escrita do pipe\n");
		else
		{
			if (read(fd[0], rcv, sizeof(msg)) < 0)
				printf("Erro na leitura do pipe\n");
			else
				printf("%s\n", rcv);

		}
	}
	return 0;
}
```
4. Crie um programa em C que cria um processo-filho e um pipe de comunicação. O processo-filho deverá pedir o nome do usuário, envia-lo para o pai via pipe, e o pai deverá escrever o nome do usuário no terminal.
```C

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int i=1, nro;
	int pid;	
	int fd[2];
	char name[20];	
	
	pipe(fd);
	pid = fork();

	if(pid == 0)
	{	

		printf("Digite seu nome:");
		scanf("%s", name);
		if(write(fd[1], name, 20) < 0)
			printf("Erro na leitura do pipe\n");
	}

	else
	{
		sleep(2);
		if (read(fd[0], name, 20) < 0)
			printf("Erro na escrita do pipe\n");
		else
		{
			printf("O pai diz que seu nome é...:\né...\né...\né...\né...\né...\né...\né...\né...\né...\né...\né...\né...\né...\n:(tãdãdãdããããããããã\nãããããããããããããããããããããããããã\nããããããããããããããããããã\nãããããããããããããããããããã\nãããããããããããããããããããããã\nãããããããããããããããããããããã\nãããããããããããããããããããã\nãããããããããããããããããããã\nãããããããããããããããããããããã...\n(barulhos aleatórios))\n %s!!!!!!!!!!!!\nIsso que é mágica de verdade!\n", name);
		}		
	}
	return 0;
}
```
5. Utilize o sinal de alarme para chamar a cada segundo o comando `ps` ordenando todos os processos de acordo com o uso da CPU. Ou seja, seu código atualizará a lista de processos a cada segundo. Além disso, o código deverá tratar o sinal do CTRL-C, escrevendo "Processo terminado!" na tela antes de terminar a execução do processo.

```C
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	alarm(1);
	system("clear");
	system("ps -eo pid,cmd,%mem,%cpu --sort=-%cpu | head");
	//system("date +%s%3N");
}

void funcao_para_control_c()
{
	printf("\nProcesso Finalizado!\n");
	exit(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	signal(SIGINT, funcao_para_control_c);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
```
