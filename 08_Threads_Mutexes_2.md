1. Crie um programa em C que cria uma thread, e faça com que o programa principal envie os valores 1, 2, 3, 4, 5, 6, 7, 8, 9 e 10 para a thread, com intervalos de 1 segundo entre cada envio. Depois de o programa principal enviar o número 10, ele aguarda 1 segundo e termina a execução. A thread escreve na tela cada valor recebido, e quando ela receber o valor 10, ela termina a execução.
```C
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct char_print_parms
	{
	int count; 
	};

void* char_print (void* parameters) {
	struct char_print_parms* p = (struct char_print_parms*) parameters;
	int i;
	for (i = 1; i <= 10; i++)
	{
		p->count = i;
		printf("%d\n", p->count);
		sleep(1);
	}
	return NULL;
}
int main ()
{
	pthread_t thread1_id;
	struct char_print_parms thread1_args;
	printf("Pressione CTRL+C para finalizar o programa.\n");
	pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
	pthread_join (thread1_id, NULL);
	return 0;
}
```

2. Crie um programa em C que preenche o vetor `long int v[50000]` completamente com valores aleatórios (use a função `random()`), e que procura o valor máximo do vetor por dois métodos:

(a) Pela busca completa no vetor `v[]`;
```C
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct char_print_parms
	{
	long int v[50000]; 
	long int max;
	};

void* char_print (void* parameters) {
	struct char_print_parms* p = (struct char_print_parms*) parameters;
	int i;
	printf("Vetor v inteiro:\n");
	for(i=0; i<=(50000-1); i++)
	{
		p->v[i] = random();
		printf("  %ld  ", p->v[i]);
	}
	p->max = p->v[0];
	for (i = 0; i <= (50000-1); i++)
	{
		if(p->v[i]>p->max)
			p->max = p->v[i];
	}
	printf("Valor máximo:%ld\n", p->max);
	return NULL;
}
int main ()
{
	pthread_t thread1_id;
	struct char_print_parms thread1_args;
	pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
	pthread_join (thread1_id, NULL);
	return 0;
}
```

(b) Separando o vetor em 4 partes, e usando 4 threads para cada uma encontrar o máximo de cada parte. Ao final das threads, o programa principal compara o resultado das quatro threads para definir o máximo do vetor.

```C
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 12500

struct char_print_parms
	{
	long int v[MAX];  
	long int max;
	};
/*
struct char_print_parms_2
	{
	long int v_2[12500]; 
	long int max_2;
	};
struct char_print_parms_3
	{
	long int v_3[12500]; 
	long int max_3;
	};
struct char_print_parms_4
	{
	long int v_4[12500]; 
	long int max_4;
	};
*/
struct max_parms
	{	
	long int max[4];
	long int ultimate_max;
	};
	
	int count=0;

void* char_print (void* parameters) {
	struct char_print_parms* p = (struct char_print_parms*) parameters;
	int i;
	count++;
	printf("\n\n\n\n--------------------------Vetor V (parte %d)--------------------------\n\n\n\n", count);
	for(i=0; i<=(MAX-1); i++)
	{
		p->v[i] = random();
		printf("  %ld  ", p->v[i]);
	}
	p->max = p->v[0];
	for (i = 0; i <= (MAX-1); i++)
	{
		if(p->v[i]>p->max)
			p->max = p->v[i];
	}
	printf("Valor máximo (parte %d):%ld\n", count, p->max);
	return NULL;
}

int main ()
{
	int i=0;
	pthread_t thread1_id;
	pthread_t thread2_id;
	pthread_t thread3_id;
	pthread_t thread4_id;

	struct char_print_parms thread1_args;
	struct char_print_parms thread2_args;
	struct char_print_parms thread3_args;
	struct char_print_parms thread4_args;
	struct max_parms thread5_args;

	pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
	pthread_join (thread1_id, NULL);

	pthread_create (&thread2_id, NULL, &char_print, &thread2_args);
	pthread_join (thread2_id, NULL);

	pthread_create (&thread3_id, NULL, &char_print, &thread3_args);
	pthread_join (thread3_id, NULL);
	
	pthread_create (&thread4_id, NULL, &char_print, &thread4_args);
	pthread_join (thread4_id, NULL);

	thread5_args.max[0] = thread1_args.max;
	thread5_args.max[1] = thread2_args.max;
	thread5_args.max[2] = thread3_args.max;
	thread5_args.max[3] = thread4_args.max;

	thread5_args.ultimate_max = thread5_args.max[0];

	for (i = 0; i < 4; i++)
	{
		if(thread5_args.max[i]>thread5_args.ultimate_max)
			thread5_args.ultimate_max = thread5_args.max[i];
	}
	printf("\n\n\n-------------------------- Valor máximo final: %ld--------------------------", thread5_args.ultimate_max);
	
	
	return 0;

}
```

Ao final do programa principal, compare os resultados obtidos pelos dois métodos.

3. Repita o exercício anterior, mas calcule a média do vetor ao invés do valor máximo.
```C
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 12500

struct char_print_parms
	{
	long int v[MAX];  
	long int avg;
	};

struct avg_parms
	{	
	long int avg[4];
	long int ultimate_avg;
	};
	
	int count=0;

void* char_print (void* parameters) {
	struct char_print_parms* p = (struct char_print_parms*) parameters;
	int i;
	count++;
	printf("\n\n\n\n--------------------------Vetor V (parte %d)--------------------------\n\n\n\n", count);
	for(i=0; i<=(MAX-1); i++)
	{
		p->v[i] = random();
		printf("  %ld  ", p->v[i]);
	}
	p->avg = 0;
	for (i = 0; i <= (MAX-1); i++)
	{
		if(p->v[i]>p->avg)
			p->avg = p->avg + p->v[i];
	}
	p->avg = p->avg/MAX;
	printf("Valor médio (parte %d):%ld\n", count, p->avg);
	return NULL;
}

int main ()
{
	int i=0;
	pthread_t thread1_id;
	pthread_t thread2_id;
	pthread_t thread3_id;
	pthread_t thread4_id;

	struct char_print_parms thread1_args;
	struct char_print_parms thread2_args;
	struct char_print_parms thread3_args;
	struct char_print_parms thread4_args;
	struct avg_parms thread5_args;

	pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
	pthread_join (thread1_id, NULL);

	pthread_create (&thread2_id, NULL, &char_print, &thread2_args);
	pthread_join (thread2_id, NULL);

	pthread_create (&thread3_id, NULL, &char_print, &thread3_args);
	pthread_join (thread3_id, NULL);
	
	pthread_create (&thread4_id, NULL, &char_print, &thread4_args);
	pthread_join (thread4_id, NULL);

	thread5_args.avg[0] = thread1_args.avg;
	thread5_args.avg[1] = thread2_args.avg;
	thread5_args.avg[2] = thread3_args.avg;
	thread5_args.avg[3] = thread4_args.avg;

	thread5_args.ultimate_avg = 0;

	for (i = 0; i < 4; i++)
	{
		thread5_args.ultimate_avg = thread5_args.ultimate_avg + thread5_args.avg[i];
	}
	thread5_args.ultimate_avg = thread5_args.ultimate_avg/4;
	printf("\n\n\n-------------------------- Valor médio final: %ld--------------------------", thread5_args.ultimate_avg);
	
	
	return 0;

}
```
4. Repita o exercício anterior, mas calcule a variância do vetor ao invés da média.

```C
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 12500

struct char_print_parms
	{
	long int v[MAX];  
	long int avg;
	long int var;
	};

struct var_parms
	{	
	long int avg[4];
	long int ultimate_avg;
	long int ultimate_var;
	};
	
	int count=0;

void* char_print (void* parameters) {
	struct char_print_parms* p = (struct char_print_parms*) parameters;
	int i;
	count++;
	printf("\n\n\n\n--------------------------Vetor V (parte %d)--------------------------\n\n\n\n", count);
	for(i=0; i<=(MAX-1); i++)
	{
		p->v[i] = random();
//		printf("  %ld  ", p->v[i]);
	}
	p->avg = 0;
	p->var = 0;
	for (i = 0; i <= (MAX-1); i++)
	{
		if(p->v[i]>p->avg)
			p->avg = p->avg + p->v[i];
			p->var = p->var + (p->v[i])^2;
	}
	p->avg = p->avg/MAX;
	p->var = (p->var - MAX*(p->avg)^2)/(MAX-1);
	printf("Variância (parte %d):%ld\n", count, p->avg);
	return NULL;
}

int main ()
{
	int i=0;
	pthread_t thread1_id;
	pthread_t thread2_id;
	pthread_t thread3_id;
	pthread_t thread4_id;

	struct char_print_parms thread1_args;
	struct char_print_parms thread2_args;
	struct char_print_parms thread3_args;
	struct char_print_parms thread4_args;
	struct var_parms thread5_args;

	pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
	pthread_join (thread1_id, NULL);

	pthread_create (&thread2_id, NULL, &char_print, &thread2_args);
	pthread_join (thread2_id, NULL);

	pthread_create (&thread3_id, NULL, &char_print, &thread3_args);
	pthread_join (thread3_id, NULL);
	
	pthread_create (&thread4_id, NULL, &char_print, &thread4_args);
	pthread_join (thread4_id, NULL);

	thread5_args.avg[0] = thread1_args.avg;
	thread5_args.avg[1] = thread2_args.avg;
	thread5_args.avg[2] = thread3_args.avg;
	thread5_args.avg[3] = thread4_args.avg;

	thread5_args.ultimate_avg = 0;
	thread5_args.ultimate_var = 0;
	for (i = 0; i < 4; i++)
	{
		thread5_args.ultimate_avg = thread5_args.ultimate_avg + thread5_args.avg[i];
		thread5_args.ultimate_var = thread5_args.ultimate_var + (thread5_args.avg[i])^2;
	}
	thread5_args.ultimate_avg = thread5_args.ultimate_avg/4;
	
	thread5_args.ultimate_var = thread5_args.ultimate_var - (4*thread5_args.ultimate_avg)^2/3;

	printf("\n\n\n-------------------------- Variância final: %ld--------------------------", thread5_args.ultimate_var);
	
	
	return 0;

}
```

# Questões extra somente para estudo

5. Crie um programa em C que preenche matrizes `long int A[60][60]` e `long int B[60][60]` completamente com valores aleatórios (use a função `random()`), e que calcula a soma das duas matrizes por dois métodos:

(a) De forma sequencial;

(b) De forma paralela.

Ao final do programa principal, compare os resultados obtidos pelos dois métodos.

6. Repita o exercício anterior, mas calcule o produto matricial A*B.

7. Repita o exercício anterior, mas calcule o produto da matriz `long int A[60][60]` por um escalar `long int x`.
