1. Crie uma função em C que recebe um ano como argumento de entrada (usando as variáveis `argc` e `*argv[]`), e escreve em quais dias da semana os seguintes feriados caíram ou cairão: Ano Novo, Dia do Trabalhador e Natal. Por exemplo, considerando que o código compilado recebeu o nome de 'feriados':

```
$ ./feriados 2018
$    Ano Novo: segunda-feira
$    Dia do Trabalhador: terca-feira
$    Natal: terca-feira
```
```C
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char* argv[])
{
	char chamada[50];
	
	fprintf(stderr, "\nAno Novo: ");
	sprintf(chamada, "date -d 01/01/%s +\"%%A\"", argv[1]);
	system(chamada);
	fprintf(stderr, "\nDia do trabalhador: ");
	sprintf(chamada, "date -d 05/01/%s +\"%%A\"", argv[1]);
	system(chamada);
	fprintf(stderr, "\nNatal: ");
	sprintf(chamada, "date -d 12/25/%s +\"%%A\"", argv[1]);
	system(chamada);

return 1;
}
```
2. Crie uma função em C que paralelize o cálculo da média de um vetor excluindo o valor máximo do vetor, usando 4 threads. Use o seguinte protótipo:

```C
double media_sem_maximo_paralelo(int a[], int N);
```

Por exemplo, para o vetor

```C
int a[] = {1,2,3,501,4,5};
```

a média sem o máximo é igual a `(1+2+3+4+5)/5 = 3`. Já a média é igual a `(1+2+3+501+4+5)/6 = 86`.

```C
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>


int a[] = {1,2,3,501,4,5}, N = 6; 
double sum = 0, max, real_avrg=0, min_avrg;



void* max_value(void* dummy_ptr)
{
	int count=0;
	max = a[0];
	for(count=0;count<=(N-1);count++)
	{
		if(a[count] >= max)
			max = a[count];		
	}		
	return NULL;
}

void* sum_value(void* dummy_ptr)
{
	int count=0;

	for(count=0;count<=(N-1);count++)
	{
		sum = sum + (a[count]);		
	}		
	return NULL;
}

void* calc_real_avrg(void* dummy_ptr)
{
	real_avrg = sum/N;
	printf("real_avrg(função): %lf\n", real_avrg);
	return NULL;
}

void* calc_min_avrg(void* dummy_ptr)
{
	min_avrg = (sum - max)/(N-1);
	printf("min_avrg(função): %lf\n", min_avrg);
	return NULL;
}



double media_sem_maximo_paralelo()
{
	pthread_t thread1_id, thread2_id, thread3_id, thread4_id;
	
	pthread_create (&thread1_id, NULL, &max_value, NULL);
	pthread_create (&thread2_id, NULL, &sum_value, NULL);
	pthread_join(thread2_id, NULL);
	pthread_create (&thread3_id, NULL, &calc_real_avrg, NULL);
	pthread_join(thread1_id, NULL);
	pthread_create (&thread4_id, NULL, &calc_min_avrg, NULL);
	pthread_join(thread3_id, NULL);
	pthread_join(thread4_id, NULL);	
	return min_avrg;
}


int main(int argc, const char* argv[])
{

	double media, media_min;

	media_min = media_sem_maximo_paralelo(a, N);
	printf("Pela main, média sem máximo = %lf\n", media_min);

return 1;
}
```



3. Considerando o código abaixo, responda:

```C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

struct processo
{
	int pid, fd[2];
};
void fim()
{
	fprintf(stderr, "Processo %d terminado\n", getpid());
	exit(0);
}
int main()
{
	struct processo p[3];
	int i;
	signal(SIGINT, fim);
	for(i=0; i<3; i++)
	{
		pipe(p[i].fd);
		p[i].pid = fork();
		if(p[i].pid == 0)
			while(1);
	}
	while(1);
	return 0;
}
```

(a) Quantos processos-filho são criados ao total? Justifique sua resposta.
`3 processos-filho, porque o while gera um loop infinito dentro da condição pid==0, ou seja, todos os processos filhos, assim que criados, ficam presos no loop, enquanto o processo pai continua o loop for.`

(b) Quantos pipes são criados ao total, considerando todos os processos? Justifique sua resposta.
`3, um em cada loop for.
`
(c) Quantos pipes cada processo-filho compartilha com o processo-pai? Justifique sua resposta.
`A cada loop FOR é criado um novo pipe, ou seja, o 1º compartilha 1, o 2º compartilha 2 e o 3º compartilha 3 pipes diferentes.`

(d) Quantos processos enxergarão o sinal `SIGINT`? Justifique sua resposta.
`TODOS os processos criados. Isso se deve ao fato de o sinal ter sido criado antes do fork, fazendo com que os demais processos "nascessem" já com o sinal definido.`

4. Considerando o código abaixo, responda:

```C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main()
{
	int f2s[2], s2f[2];
	char request='V', cur_val=1;
	srand(time(NULL)); // Inicializa gerador de valores aleatorios
	pipe(f2s);
	pipe(s2f);
	if(fork() == 0)
	{
		while(cur_val!=0)
		{
			write(s2f[1], &request, sizeof(char));
			read(f2s[0], &cur_val, sizeof(char));
			printf("Valor recebido = %d\n", cur_val);
		}
		request='F';
		write(s2f[1], &request, sizeof(char));
	}
	else
	{
		while(request=='V')
		{
			read(s2f[0], &request, sizeof(char));
			if(request=='V')
			{
				cur_val = rand()%0xF;
				write(f2s[1], &cur_val, sizeof(char));
			}
		}
	}
	return 0;
}
```

(a) Quais são os papéis dos processos pai e filho neste código?

`O pai gera um valor aleatório para cur_val enquanto a variável request == 'V'. O filho verifica se em algum momento a variável cur_val se tornou zero. Caso sim, request recebe 'F', que será enviado para o pai e finalizará a execução do programa.`

`Juntos, verificam a ocorrência de zero em uma variável recebendo valores aleatórios e finalizam quando o encontram.`

(b) Neste código, os processos pai e filho estão seguindo o modelo cliente-servidor? Justifique sua resposta.
`Sim. A comunicação entre os processos e o fato de o processo-filho aguardar uma resposta específica do processo-pai para realizar uma determinada ação gera esse tipo de modelo.`


(c) Por que este código utiliza dois pipes, ao invés de um?
`Para que não haja necessidade de sobrescrever o sinal enviado/recebido do pai/filho para o filho/pai, fazendo-os ficar realizando seus testes simultaneamente/paralelamente e sem interrupções.`


(d) Ao final da execução destes processos, qual é a última linha escrita no terminal?
`O valor recebido pela variável cur_val antes da mesma se tornar zero.`
