Para todas as questões, utilize as funções da norma POSIX (`open()`, `close()`, `write()`, `read()` e `lseek()`). Compile os códigos com o gcc e execute-os via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

```C
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){

int fp;
char string[15];

fp = open("ola_mundo.txt",O_RDWR | O_CREAT);
if(fp==-1)
{
	printf ("Erro na abertura do arquivo.\n");
	exit (1);
}
strcpy(string,"Olá mundo!\n");
lseek(fp, 0, SEEK_SET); 
write(fp, string, (sizeof(string)));
close(fp);
}
```

2. Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Digite a sua idade: 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

```C
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	int fp;
	char nome[50]="", idade[20]="", arq[50] = "";

	printf("Digite seu nome:\n");
	scanf("%s",nome);
	printf("Digite sua idade:\n");
	scanf("%s", idade);
	strcpy(arq, nome);
	strcat(arq, ".txt");
	fp = open(arq,O_RDWR | O_CREAT);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}
	lseek(fp, 0, SEEK_SET); 
	write(fp, "Nome: ", (sizeof("Nome: ")));
	write(fp, nome, (sizeof(nome)));
	write(fp, "\nIdade: ", (sizeof("Idade: ")));
	write(fp, idade, (sizeof(idade)));
	write(fp, " anos\n", (sizeof("anos")));
	close(fp);
}
```

3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

```C
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[])
{

	int fp, i=0;
	char nome[50]="";
	char idade[20]="";
	char file[55]="";


	for(i=1; i<=(argc-2); i++)
	{
		if(i==1)
			strcpy(nome, argv[i]);
		else
		{	
			strcat(nome, " ");
			strcat(nome, argv[i]);
		}
	}
	strcpy(file, nome);
	strcpy(idade, argv[argc-1]);
	strcat(file, ".txt");
	fp = open(file, O_RDWR | O_CREAT);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		printf("file: %s\nnome: %s\n", file, nome);
		exit (-1);
	}
	lseek(fp, 0, SEEK_SET); 
	write(fp, "Nome: ", (sizeof("Nome: ")));
	write(fp, nome, (sizeof(nome)));
	write(fp, "\nIdade: ", (sizeof("Idade: ")));
	write(fp, idade, (sizeof(idade)));
	write(fp, " anos", (sizeof("anos")));
	close(fp);
}
```

4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.


**Main.c:**

```C
#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main()
{
	int tamanho=0;
	char arquivo[50];
	printf("Digite o nome do arquivo que você deseja saber o tamanho (em Bytes):");
	scanf("%s", arquivo);
	tamanho = tam_arq_texto(arquivo);
	printf("O arquivo %s contém %d Bytes\n", arquivo, tamanho);
return 0;
}
```
**bib_arqs.c:**

```C
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int tam_arq_texto(char *nome_arquivo)
{
	int tamanho=0;
	int arquivo;
	
	arquivo = open(nome_arquivo,O_RDONLY);
	if(arquivo==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (-1);
	}
	tamanho = lseek(arquivo, 0, SEEK_END);
	close(arquivo);
	return tamanho;
}
```
**Makefile:**
```C
bib_arqs:  main.o bib_arqs.o
	gcc $(CFLAGS) -o bib_arqs main.o bib_arqs.o
main.o: bib_arqs.c bib_arqs.h
	gcc $(CFLAGS) -c main.c
reciprocal.o: bib_arqs.c bib_arqs.h
	gcc $(CFLAGS) -c bib_arqs.c
clean:
	rm -f *.o bib_arqs
```

**bib_arqs.h:**
```C
int tam_arq_texto(char *nome_arquivo);
```


5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `char* le_arq_texto(char *nome_arquivo);` Repare que o conteúdo do arquivo é armazenado em um vetor interno à função, e o endereço do vetor é retornado ao final. (Se você alocar este vetor dinamicamente, lembre-se de liberar a memória dele quando acabar o seu uso). Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.

**Main.c:**

```C
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

int main()
{
	char arquivo[20];
	char texto[400];
	int arq;



	
	printf("Digite o nome do arquivo de texto que você deseja salvar na string:");
	scanf("%s", arquivo);
	arq = open(arquivo, O_RDONLY);
	  if (arq == -1)  
	  {
		printf("Problemas na abertura do arquivo\n");
	        return 0;
	  }
	lseek(arq, 0, SEEK_SET);
	printf("\n %s", le_arq_texto(arquivo));
	printf("\nFim do arquivo.");
	close(arq);
	return 0;
}
```
**bib_arqs.c:**

```C
char* le_arq_texto(char *nome_arquivo)
{
  int arq, i=0;
  char Linha[100], texto[400];
  char *result;

  printf("Teste");
  arq = open(nome_arquivo, O_RDONLY);
  if (arq == -1)  
  {
     printf("Problemas na abertura do arquivo\n");
     return"";
  }
  lseek(arq, 0, SEEK_SET);
  while (arq!=0)
  {
      read(arq, Linha, lseek(arq, i, SEEK_SET));  
      strcat(texto, Linha);
	i++;
  }
  close(arq);
  return texto;
}
```

6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```

```C
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, const char * argv[])
{
	int fp;
	char c;

	fp = open (argv[1], O_RDONLY);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}
	while(read(fp, &c, 1) != 0)
		printf("%c", c);
	close(fp);
	
	return 0;
}
```

7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```
```C
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[])
{
	int fp, i=0, found=0;
	char c, word[strlen(argv[1])], wf[strlen(argv[1])];

	
	strcpy(word, argv[1]);
	fp = open (argv[2], O_RDONLY);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}
	printf("Word: %s\n", word);
	while(read(fp, &c, 1) != 0)
	{
		if((c==' ' || c=='\n') && (i==strlen(word)))
			found++;
		printf("loop while c: %c\n", c);
		printf("loop while word: %c\n", word[i]);
		printf("loop strlen(word): %ld\n", strlen(word));
		printf("loop while i: %d\n\n", i);
		if(c==' ' || c=='\n')
			i=0;		
		if(word[i]==c)
			i++;

	}
	printf("\nNúmero de ocorrências da palavra %s: %d.\n", word, found);
	close(fp);
	
	return 0;
}
```
