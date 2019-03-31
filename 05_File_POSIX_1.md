1. Considerando a biblioteca-padrão da linguagem C, responda:

**(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

fopen - FILE *fopen (char *nome_do_arquivo, char
*modo)

fclose - int fclose (FILE *ponteiro_para_arquivo)


**(b) Quais são as funções (e seus protótipos) para escrever em arquivos?

fputs - char *fputs (char *str,FILE *fp);

fwrite - unsigned fwrite (void *buffer,int numero_de_bytes,int
count,FILE *fp);

int fprintf ( FILE * stream, const char * format, ... );


**(c) Quais são as funções (e seus protótipos) para ler arquivos?

unsigned fread (void *buffer, int numero_de_bytes, int
count, FILE *fp); 

int fscanf ( FILE * stream, const char * format, ... );

char *fgets (char *str, int tamanho,FILE *fp); 


**(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

int fseek ( FILE * stream, long int offset, int origin ); 

void rewind ( FILE * stream );

**(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?

stdio.h, string.h e stdlib.h

**2. O que é a norma POSIX?

**3. Considerando a norma POSIX, responda:

**(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

**(b) Quais são as funções (e seus protótipos) para escrever em arquivos?

**(c) Quais são as funções (e seus protótipos) para ler arquivos?

**(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

**(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?
