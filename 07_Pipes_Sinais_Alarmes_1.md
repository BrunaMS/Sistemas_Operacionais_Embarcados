1. Quantos pipes serão criados após as linhas de código a seguir? Por quê?

(a)
```C
int pid;
int fd[2];
pipe(fd);
pid = fork();
```
`Apenas 1 pipe, devido ao fato de a criação do pipe ter sido realizada antes do do fork, fazendo com que esse pipe não possa ser utilizado pelo mesmo.`

(b)
```C
int pid;
int fd[2];
pid = fork();
pipe(fd);
```

` 2 pipes, que serão dividido em 2 partes: escrita e leitura, que poderão ser realizados por 2 processos diferentes (pai e filho).Isso devido ao fato de o "fork" estar antes do pipe, disponibilizando-o também para o processo-filho realizar.`

2. Apresente mais cinco sinais importantes do ambiente Unix, além do `SIGSEGV`, `SIGUSR1`, `SIGUSR2`, `SIGALRM` e `SIGINT`. Quais são suas características e utilidades?

```
1. SIGFPE: Emitido em caso de erro de cálculo em ponto flutuante, assim como no caso de um número em ponto flutuante em formato ilegal. Indica sempre um erro de programação.
2. SIGHUP: Sinal de corte emitido aos processos associados a um terminal quando este se desconecta.
3. SIGKILL: Sinal de destruição para matar processos. Não pode ser interceptado nem ignorado.
4. SIGSYS: Indica um argumento incorreto de uma chamada de sistema. 
5. SIGPIPE: Escrita sobre um pipe não aberto em leitua.
```

3. Considere o código a seguir:

```C
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("date");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
```

Sabendo que a função `alarm()` tem como entrada a quantidade de segundos para terminar a contagem, quão precisos são os alarmes criados neste código? De onde vem a imprecisão? Este é um método confiável para desenvolver aplicações em tempo real?