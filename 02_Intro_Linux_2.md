1. Para todas as questões, escreva os comandos correspondentes no terminal.

2. Escreva o texto "Ola mundo cruel!" em um arquivo denominado "Ola_mundo.txt". Apresente o conteúdo deste arquivo no terminal.
```bash
$ echo "Ola mundo cruel" > Ola_mundo.txt
$ cat Ola_mundo.txt 
```
3. Apresente o nome de todos os arquivos e pastas na pasta 'root'.
```bash
$ cd ..
$ cd ..
$ cd root
$ ls root
```
4. Apresente o tipo de todos os arquivos e pastas na pasta 'root'.
```bash
$ cd ..
$ cd ..
$ cd root
$ ls -l root
```
5. Apresente somente as pastas dentro da pasta 'root'.
```bash
$ cd ..
$ cd ..
$ cd root
$ ls -d */
```

6. Descubra em que dia da semana caiu o seu aniversário nos últimos dez anos.

Dia: 19/06

```bash
$ ncal 6 2019 > cal_ten_years_ago
$ ncal 6 2018 >> cal_ten_years_ago
$ ncal 6 2017 >> cal_ten_years_ago
$ ncal 6 2016 >> cal_ten_years_ago
$ ncal 6 2015 >> cal_ten_years_ago
$ ncal 6 2014 >> cal_ten_years_ago
$ ncal 6 2013 >> cal_ten_years_ago
$ ncal 6 2011 >> cal_ten_years_ago
$ ncal 6 2010 >> cal_ten_years_ago
$ ncal 6 2009 >> cal_ten_years_ago

$ grep "19" cal_ten_years_ago
```
OU

```bash
date -d 06/19/2009 +%A
date -d 06/19/2010 +%A
date -d 06/19/2011 +%A
date -d 06/19/2012 +%A
date -d 06/19/2013 +%A
date -d 06/19/2014 +%A
date -d 06/19/2015 +%A
date -d 06/19/2016 +%A
date -d 06/19/2017 +%A
date -d 06/19/2018 +%A
date -d 06/19/2019 +%A
```


Para as questões a seguir, use a pasta no endereço https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Questoes/02_Intro_Linux_arqs.zip

7. Liste somente os arquivos com extensão .txt.

```bash
$ ls *.txt

arquivo.txt   cal_1994.txt  cal_1999.txt  cal_2004.txt	cal_2009.txt  cal_2014.txt  cal_2019.txt
cal_1990.txt  cal_1995.txt  cal_2000.txt  cal_2005.txt	cal_2010.txt  cal_2015.txt  cal_2020.txt
cal_1991.txt  cal_1996.txt  cal_2001.txt  cal_2006.txt	cal_2011.txt  cal_2016.txt  cal.txt
cal_1992.txt  cal_1997.txt  cal_2002.txt  cal_2007.txt	cal_2012.txt  cal_2017.txt  cal_types.txt
cal_1993.txt  cal_1998.txt  cal_2003.txt  cal_2008.txt	cal_2013.txt  cal_2018.txt
```

8. Liste somente os arquivos com extensão .png.
```bash
$ ls *.png

BusinessTux.png  linux_inside.png	       tux-linux-professional_0-100520358-orig.png
linux1.png	 linux-penguin-icon-39742.png  TUX.png
linux2.png	 linux.png		       xanderrun-tux-construction-8454.png
linux3.png	 Tux-in-a-suit.png
```
9. Liste somente os arquivos com extensão .jpg.
```bash
$ ls *.jpg

d36f1a2be6a927ac3e2e1e4eacdedded.jpg  oRva1OGD_400x400.jpg  oRva1OGD.jpg  zz39112bb5.jpg
```

10. Liste somente os arquivos com extensão .gif.
```bash
$ ls *.gif

1086970.gif
```

11. Liste somente os arquivos que contenham o nome 'cal'.
```bash
$ find -iname *cal*

cal_1990.txt  cal_1995.txt  cal_2000.txt  cal_2005.txt	cal_2010.txt  cal_2015.txt  cal_2020.txt
cal_1991.txt  cal_1996.txt  cal_2001.txt  cal_2006.txt	cal_2011.txt  cal_2016.txt  cal.txt
cal_1992.txt  cal_1997.txt  cal_2002.txt  cal_2007.txt	cal_2012.txt  cal_2017.txt  cal_types.txt
cal_1993.txt  cal_1998.txt  cal_2003.txt  cal_2008.txt	cal_2013.txt  cal_2018.txt
cal_1994.txt  cal_1999.txt  cal_2004.txt  cal_2009.txt	cal_2014.txt  cal_2019.txt
```

12. Liste somente os arquivos que contenham o nome 'tux'.

```bash
$ *find -iname *tux*

tux-linux-professional_0-100520358-orig.png  xanderrun-tux-construction-8454.png
```

13. Liste somente os arquivos que comecem com o nome 'tux'.
```bash
$ ls tux*

tux-linux-professional_0-100520358-orig.png
```
