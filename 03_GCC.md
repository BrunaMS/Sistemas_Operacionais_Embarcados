Para todas as questões, compile-as com o gcc e execute-as via terminal.

**1. Crie um "Olá mundo!" em C.**
```C
#include <stdio.h>
#include <stdlib.h>
int main(void)

{
	printf("Olá mundo!\n");
}
```

**2. Crie um código em C que pergunta ao usuário o seu nome, e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':**
```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Ola Eu
```
```C
#include <stdio.h>

#include <stdlib.h>

int main(void)

{

	char nome[20];

	printf("Como você se chama?\n");

	scanf("%s", nome);

	printf("Olá %s! \n", nome);

}
```
**3. Apresente os comportamentos do código anterior nos seguintes casos:**

**(a) Se o usuário insere mais de um nome.**
```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu Mesmo
```
```bash
Olá Eu! 
```
**(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:**
```bash
$ ./ola_usuario_1
$ Digite o seu nome: "Eu Mesmo"
```
```bash
"Olá Eu!"
```
**(c) Se é usado um pipe. Por exemplo:**
```bash
$ echo Eu | ./ola_usuario_1
```
```bash
Como você se chama?

Olá Eu!
```

**(d) Se é usado um pipe com mais de um nome. Por exemplo:**
```bash
$ echo Eu Mesmo | ./ola_usuario_1
```
```bash
Como você se chama?

Olá Eu!
```

**(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:**
```bash
$ echo "Eu Mesmo" | ./ola_usuario_1
```
```bash
Como você se chama?

Olá Eu!
```

**(f) Se é usado o redirecionamento de arquivo. Por exemplo:**
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_1 < ola.txt
```
```bash
Como você se chama?

Olá Ola! 
```

**4. Crie um código em C que recebe o nome do usuário como um argumento de entrada (usando as variáveis argc e *argv[]), e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':**
```bash
$ ./ola_usuario_2 Eu
$ Ola Eu
```
```C
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	int i=1;
	
	printf("Olá");
	do{
			printf(" %s", argv[i]);
			
			if(i==(argc-1))
				printf("!\n");
 			i++;
	}while(i<=argc-1);
}
```


**5. Apresente os comportamentos do código anterior nos seguintes casos:**

**(a) Se o usuário insere mais de um nome.**
```bash
$ ./ola_usuario_2 Eu Mesmo
```
```bash
$ Olá Eu Mesmo!
```
**(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:**
```bash
$ ./ola_usuario_2 "Eu Mesmo"
```
```bash
$ Olá Eu Mesmo!
```
**(c) Se é usado um pipe. Por exemplo:**
```bash
$ echo Eu | ./ola_usuario_2
```
```bash
Olá (null)
```
**(d) Se é usado um pipe com mais de um nome. Por exemplo:**
```bash
$ echo Eu Mesmo | ./ola_usuario_2
```
```bash
Olá (null)
```
**(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:**
```bash
$ echo Eu Mesmo | ./ola_usuario_2
```
```bash
Olá (null)
```
**(f) Se é usado o redirecionamento de arquivo. Por exemplo:**
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_2 < ola.txt
```
```bash
Olá (null)
```
**6. Crie um código em C que faz o mesmo que o código da questão 4, e em seguida imprime no terminal quantos valores de entrada foram fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_3':**
```bash
$ ./ola_usuario_3 Eu
$ Ola Eu
$ Numero de entradas = 2
```
```C
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	int i=1;
	
	printf("Olá");
	do{
			printf(" %s", argv[i]);
			
			if(i==(argc-1))
				printf("!\n");
 			i++;
	}while(i<=argc-1);
	printf("\nNúmero de entradas: %d \n", argc);
}
```

**7. Crie um código em C que imprime todos os argumentos de entrada fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_argumentos':**
```bash
$ ./ola_argumentos Eu Mesmo e Minha Pessoa
$ Argumentos: Eu Mesmo e Minha Pessoa
```
```C
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	int i=1;
	
	printf("Argumentos: ");	
	do{
			printf("%s ", argv[i]);
			
			if(i==(argc-1))
				printf("\n");
 			i++;
	}while(i<=argc-1);
}
```

**8. Crie uma função que retorna a quantidade de caracteres em uma string, usando o seguinte protótipo: int Num_Caracs(char *string); Salve-a em um arquivo separado chamado 'num_caracs.c'. Salve o protótipo em um arquivo chamado 'num_caracs.h'. Compile 'num_caracs.c' para gerar o objeto 'num_caracs.o'.**

```C
main.c:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "num_caracs.h"

int main (int argc, char **argv)
{
	int i, qntd=0;

	for(i=1;i<(argc);i++)
	{
		qntd+= Num_Caracs(argv[i]);
	}
	
	printf("Número de caracteres: %d\n", qntd);


}
```


num_caracs.h:
```C
int Num_Caracs(char *string);
```


num_caracs.c:
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "num_caracs.h"

int Num_Caracs(char *string)
{
	int size;	
	size = strlen(string);
	return size;
}
```
**9. Re-utilize o objeto criado na questão 8 para criar um código que imprime cada argumento de entrada e a quantidade de caracteres de cada um desses argumentos. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_1':**
```bash
$ ./ola_num_caracs_1 Eu Mesmo
$ Argumento: ./ola_num_caracs_1 / Numero de caracteres: 18
$ Argumento: Eu / Numero de caracteres: 2
$ Argumento: Mesmo / Numero de caracteres: 5
```
**10. Crie um Makefile para a questão anterior.**
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "num_caracs.h"

int main (int argc, char **argv)
{
	int i, qntd=0;

	for(i=0;i<(argc);i++)
	{
		qntd = Num_Caracs(argv[i]);
		printf("Argumento: %s/ ", argv[i]);
		printf("Número de caracteres: %d\n\n", qntd);
	}
}
```

**11. Re-utilize o objeto criado na questão 8 para criar um código que imprime o total de caracteres nos argumentos de entrada. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_2':**
```bash
$ ./ola_num_caracs_2 Eu Mesmo
$ Total de caracteres de entrada: 25
```
**12. Crie um Makefile para a questão anterior.**

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "num_caracs.h"

int main (int argc, char **argv)
{
	int i, qntd=0;

	for(i=0;i<(argc);i++)
	{
		qntd+= Num_Caracs(argv[i]);
		
	}
	printf("Número de caracteres: %d\n", qntd);
}
```
