1. Quais são as vantagens e desvantagens em utilizar:

(a) fork?

	- Cada filho executa sua própria tarefa;
	- Cada filho tem seu espaço de memória protegido;
	- Comunicação feita por mecanismos (ICP);

(b) threads?

	- Uma só aplicação pode rodar várias threads;
	- Todas as threads compartilham o mesmo espaço de memória;
	- A comunicação é mais simples;

2. Quantas threads serão criadas após as linhas de código a seguir? Quantas coexistirão? Por quê?

(a)

```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```


`3 Threads, com as duas threads criadas funcionando paralelamente. Essa característica é definida`


(b)
```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```

`3 Threads, com apenas duas coexistindo (a função principal e outra paralela), devido à existência do comando pthread_join, que faz com que a 2ª thread só seja executada após o término da primeira.`

3. Apresente as características e utilidades das seguintes funções:

(a) `pthread_setcancelstate()`
    
       Define, através do valor colocado no argumento "state", o estado de cancelamento da thread chamada.

(b) `pthread_setcanceltype()`

	Define, através do valor colocado no argumento "type", um tipo para o cancelamento da thread chamada.


(DICA: elas são relacionadas à função pthread_cancel().)
