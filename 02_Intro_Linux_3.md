### Para todas as questões, escreva os scripts e as chamadas correspondentes no terminal.

### 1. Crie um arquivo com nome teste1.txt, e escreva nele o texto "Número do arquivo = 1". Repita o procedimento para os arquivos teste2.txt, teste3.txt, ..., teste100.txt, escrevendo o texto correspondente para cada um deles ("Número do arquivo = 2", "Número do arquivo = 3", ..., "Número do arquivo = 100").
```bash
#!/bin/bash
for i in {1..100}
do
echo "Numero do arquivo = $i" > test$i.txt
done
```

### 2. Faça um script chamado cals.sh que apresente o calendário de vários meses indicados pelo usuário, usando o seguinte formato:
```bash
./cals.sh MES1 ANO1 MES2 ANO2 MES3 ANO3
```
Não limite o script a 3 meses. Ele deve funcionar para vários casos, como por exemplo:
```bash
./cals.sh 1 2020
./cals.sh 1 2019 2 2020 3 2021 1 2010
```
```bash
#!/bin/bash
 
echo "Numero de argumentos: $#"
 
count=0
n=0
for ARG in $*; do
	count=`expr $count + 1`
	if [ $n -eq 0 ]; then
		mes=$(($ARG)) 
		n=1
	elif [ $n -eq 1 ]; then	
		ano=$(($ARG)) 
		n=0
		cal $mes $ano
	fi
done
```

Utilizando a lógica do script anterior, descubra em que dia da semana caiu o seu aniversário nos últimos dez anos.

```bash
#!/bin/bash
 
echo "Numero de argumentos: $#"
 
count=0
n=0
echo "Data: 19 de Junho"
for ano in {2009..2019} 
do
	echo "Ano: $ano" 
	date -d 06/19/$ano +%A
done
```

### 3. Crie um arquivo sites.txt com o seguinte conteúdo:

https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Aulas/01_Linux%20b%C3%A1sico.pdf
https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Aulas/01_Linux%20b%C3%A1sico_Shell_Script.pdf
https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Aulas/01_Sistemas%20Embarcados%20-%20Aula%201%20-%20Introdu%C3%A7%C3%A3o.pdf
Estes são links para slides de 3 aulas desta dsciplina, um para cada linha do arquivo sites.txt. Faça um script que faz o download de stes slides automaticamente, a partir do arquivo sites.txt. (DICA: use o comando wget.)

```bash
#!/bin/bash

while read linha
do

	wget $linha

done < sites.txt

```

### 4. Faça um script chamado up.sh que sobe N níveis na pasta onde você estiver, usando $1 como parâmetro de entrada. Por exemplo, se você estiver em /home/aluno/Documents e executar ./up.sh 2, você automaticamente vai para a pasta /home.
`right`
```bash
#!/bin/bash

i=0
max=$1
while [ $i -lt $max ]
do
	cd ..
	pwd
	i=$((i+1))
done
```
