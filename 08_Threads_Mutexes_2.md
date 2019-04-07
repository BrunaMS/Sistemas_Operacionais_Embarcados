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

Ao final do programa principal, compare os resultados obtidos pelos dois métodos.

3. Repita o exercício anterior, mas calcule a média do vetor ao invés do valor máximo.

4. Repita o exercício anterior, mas calcule a variância do vetor ao invés da média.

# Questões extra somente para estudo

5. Crie um programa em C que preenche matrizes `long int A[60][60]` e `long int B[60][60]` completamente com valores aleatórios (use a função `random()`), e que calcula a soma das duas matrizes por dois métodos:

(a) De forma sequencial;

(b) De forma paralela.

Ao final do programa principal, compare os resultados obtidos pelos dois métodos.

6. Repita o exercício anterior, mas calcule o produto matricial A*B.

7. Repita o exercício anterior, mas calcule o produto da matriz `long int A[60][60]` por um escalar `long int x`.
