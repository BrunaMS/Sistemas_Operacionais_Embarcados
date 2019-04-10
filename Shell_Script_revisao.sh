#!/bin/bash
# Compila todos os arquivos da pasta que terminam com .c
for arq in *.c
do
  gcc $arq -o $arq.out -lpthread
done
