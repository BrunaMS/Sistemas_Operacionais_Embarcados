1. Como se utiliza o comando `ps` para:

(a) Mostrar todos os processos rodando na máquina?

`ps -aux`

(b) Mostrar os processos de um usuário?

` ps -u usuário`

(c) Ordenar todos os processos de acordo com o uso da CPU?

 `ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%cpu | head`

(d) Mostrar a quanto tempo cada processo está rodando?

`ps -eo pid,ppid,cmd,%mem,%cpu,time --sort=-time | head`

2. De onde vem o nome `fork()`?

`De "bifurcação" em inglês, o que indica algo que divide o código em dois caminhos diferentes`

3. Quais são as vantagens e desvantagens em utilizar:

(a) `system()`? 

`- Permite executar um comando dentro de um programa, criando um sub-processo (processo filho);`

`- Retorna em sua saída o status do comando no shell;`

`- Depende muito do sistema.`

(b) `fork()` e `exec()`?

`- A função fork() cria uma cópia do processo atual e em seguida a função exec() substitui o conteúdo do novo processo por um novo programa;`

`- Tanto o processo pai quanto o filho continuam a executar normalmente.`

`- A função exec() substitui o programa em execução de um processo por outro programa;`

`- O processo cessa imediatamente a execução do programa corrente e passa a executar um novo programa do início.`

4. É possível utilizar o `exec()` sem executar o `fork()` antes? `Não.`

5. Quais são as características básicas das seguintes funções:

(a) `execp()`? `Aceita que o nome ou procura do programa esteja no current path`

(b) `execv()`? `Aceita que a lista de argumentos do novo programa seja nula.`

(c) `exece()`? `Aceita um argumento adicional.`

(d) `execvp()`? `Fornece uma lista de ponteiros para strings terminadas com caracteres nulos que representam a lista de argumentos disponível para o novo programa.`

(e) `execve()`? `Executa o programa apontado por meio do nome do arquivo`

(f) `execle()`? `Permite especificar o ambiente do programa executado por meio do argumento envp.`
