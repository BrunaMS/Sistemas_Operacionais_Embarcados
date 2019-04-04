1. Crie um código em C para gerar três processos-filho usando o `fork()`.

```C
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
	int i=0;
	pid_t child_pid[3];
	printf("ID do processo-pai: %d\n", (int) getpid());

	sleep(1);
	child_pid[0] = fork();
	if (child_pid[0] == 0)
	{
		printf("Texto escrito pelo processo-filho %d (ID=%d) *\n", i, (int) getpid());
	}
	else
	{
		sleep(1);
		printf("Texto escrito pelo processo-pai (ID=%d) *\n", (int) getpid());
	}

	sleep(1);
	child_pid[1] = fork();
	if (child_pid[1] == 0)
	{
		printf("Texto escrito pelo processo-filho %d (ID=%d) *\n", i, (int) getpid());
	}
	else
	{
		sleep(1);
		printf("Texto escrito pelo processo-pai (ID=%d) *\n", (int) getpid());
	}

	sleep(1);
	child_pid[2] = fork();
	if (child_pid[2] == 0)
	{
		printf("Texto escrito pelo processo-filho %d (ID=%d) *\n", i, (int) getpid());
	}
	else
	{
		sleep(1);
		printf("Texto escrito pelo processo-pai (ID=%d) *\n", (int) getpid());
	}

	return 0;
}
```

2. Crie um código em C que recebe o nome de diversos comandos pelos argumentos de entrada (`argc` e `*argv[]`), e executa cada um sequencialmente usando `system()`. Por exemplo, considerando que o código criado recebeu o nome de 'serial_system', e que ele foi executado na pasta '/Sistemas_Embarcados/Code/06_Processos', que contem diversos arquivos:

```bash
$ ./serial_system pwd echo ls echo cal
$ ~/Sistemas_Embarcados/Code/06_Processos
$
$ Ex1.c    Ex2b.c   Ex4.c   Ex6.c
$ Ex2a.c   Ex3.c    Ex5.c   serial_system
$
$     Março 2017
$ Do Se Te Qu Qu Se Sá
$           1  2  3  4
$  5  6  7  8  9 10 11
$ 12 13 14 15 16 17 18
$ 19 20 21 22 23 24 25
$ 26 27 28 29 30 31
```

```C
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, const char *argv[])
{
	int i=1;
	while(i<argc)
	{
		system(argv[i]);
		i++;
	}
	return 0;
}
```

3. Crie um código em C que recebe o nome de diversos comandos pelos argumentos de entrada (`argc` e `*argv[]`), e executa cada um usando `fork()` e `exec()`.
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i=0;
	char* lista_de_argumentos[argc-1];
	pid_t child_pid = fork();

	
		if (child_pid == 0)
		{
			printf("if");
			execvp(argv[0], argv);
			printf("Erro de execução no comando exec.\n");     
			printf("\n");
		}


	return 0;
}

```
4. Crie um código em C que gera três processos-filho usando o `fork()`, e que cada processo-filho chama a seguinte função uma vez:

```C
int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}
```
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual);

int main()
{
	int i=0;
	pid_t child_pid;
	for(i=0;i<3;i++)
	{
		child_pid = fork();
		if(child_pid == 0 && v_global== 0)
			Incrementa_Variavel_Global(child_pid);
	}
	return 0;
}

void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}
```
(Repare que a função `Incrementa_Variavel_Global()` recebe como entrada o ID do processo que a chamou.) Responda: a variável global `v_global` foi compartilhada por todos os processos-filho, ou cada processo enxergou um valor diferente para esta variável? `Cada processo enxerga um valor diferente.`

5. Repita a questão anterior, mas desta vez faça com que o processo-pai também chame a função `Incrementa_Variavel_Global()`. Responda: a variável global `v_global` foi compartilhada por todos os processos-filho e o processo-pai, ou cada processo enxergou um valor diferente para esta variável? `Cada processo enxerga um valor diferente.`

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual);

int main()
{
	int i=0;
	pid_t child_pid;
	Incrementa_Variavel_Global((int) getpid ());
	for(i=0;i<3;i++)
	{
		child_pid = fork();
		if(child_pid == 0 && v_global== 1)
			Incrementa_Variavel_Global((int) getpid ());
	}
	return 0;
}

void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}
```