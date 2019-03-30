Para todas as questões, utilize as funções da biblioteca `stdio.h` de leitura e de escrita em arquivo (`fopen()`, `fclose()`, `fwrite()`, `fread()`, dentre outras). Compile os códigos com o gcc e execute-os via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

```C
#include <stdio.h>

int main(){

FILE *fp;

fp = fopen("ola_mundo.txt","w" );
fputs("Olá mundo!\n",fp);
fclose(fp);
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
#include <string.h>
#include <stdlib.h>


int main(){

FILE *fp;
char nome[50]="", idade[20]="";

fp = fopen("nome_idade.txt","w+" );
printf("Digite seu nome:\n");
scanf("%s",nome);
printf("Digite sua idade:\n");
scanf("%s", idade);
fputs("Nome:",fp);
fputs(nome,fp);
fputs("\nIdade:",fp);
fputs(idade,fp);
fputs(" anos\n",fp);
fclose(fp);
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
#include <string.h>
#include <stdlib.h>


int main(int argc, const char * argv[]){

FILE *fp;
char nome[50]="";
char idade[20]="";
char file[55]="";

strcpy(nome, argv[1]);
strcpy(file, argv[1]);
strcpy(idade, argv[2]);
strcat(file, ".txt");
fp = fopen(file,"w+" );
fputs("Nome:",fp);
fputs(nome,fp);
fputs("\nIdade:",fp);
fputs(idade,fp);
fputs(" anos\n",fp);
fclose(fp);
}
```


4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado '.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

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
#include <string.h>
#include <stdlib.h>


int tam_arq_texto(char *nome_arquivo)
{
	int tamanho=0;
	FILE *arquivo;
	
	arquivo = fopen(nome_arquivo, "r");
	fseek(arquivo, 0, SEEK_END);
	tamanho = ftell(arquivo);
	fclose(arquivo);
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

```C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* le_arq_texto(char *nome_arquivo)
{
  FILE *arq;
  char Linha[100], texto[400];
  char *result;

  
  arq = fopen(nome_arquivo, "rt");
  if (arq == NULL)  
  {
     printf("Problemas na abertura do arquivo\n");
     return"";
  }
  while (!feof(arq))
  {
      result = fgets(Linha, 100, arq);  
      if (result)
	  strcat(texto, Linha);
  }
  fclose(arq);
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
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
  FILE *arq;
  char Linha[100];
  char *result;


  arq = fopen(argv[1], "rt");
  if (arq == NULL)  
  {
     printf("Problemas na abertura do arquivo\n");
     return 0;
  }
  while (!feof(arq))
  {
      result = fgets(Linha, 100, arq);  
      if (result)
	  printf("%s", Linha);
  }
  fclose(arq);
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
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
	  FILE *arq;
	  char word[20];
	  int i=0, found=0, l=0;


	  arq = fopen(argv[2], "rt");
	  if (arq == NULL)  
	  {
	     printf("Problemas na abertura do arquivo\n");
	     return 0;
	  }
	  fseek(arq, 0, SEEK_SET);
	strcpy(word, "");
	while(!feof(arq))
	{
		  if(fgetc(arq)!=32 && (!feof(arq)))
		  {	
			fseek(arq, i, SEEK_SET);
			while(fgetc(arq) != ' ' && (!feof(arq)))
			{
				word[l]=fgetc(arq);
				l++;
			}
			i+= l;
			l=0;
			if(word==argv[1])
			{
				found++;
			}		
			strcpy(word, "");	
			
		  }
 	}
	  fclose(arq);
	  printf("Número de ocorrências da palavra '%s': %d\n", argv[1], found);
	  return 0;
}
```
