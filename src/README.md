# Trabalho de EDA2

## Compilação do projeto

1. Temos um makefile para a compilação de todos os arquivos de implementação
2. No diretório do programa, digite ```make``` para compilar o programa e criar os arquivos ```.o``` e também criar o binário ```program```.

## O criador de entradas

Temos um programa que cria entradas aleatórias para o programa, passando apenas a entrada do tamanho das tabelas Hash e depois a quantidade de chaves que serão geradas aleatóriamente pelo programa a partir de uma faixa que está entre 80 e 500, mas que pode ser mudada no programa.

## Executar o programa

1. Para executar o programa, temos 3 comandos make que podem ser usados no terminal.
    1. ```run``` que serve apenas para executar o programa passando um arquivo de entrada chamado ```entrada.txt``` e colocando a saída padrão em um arquivo chamado ```saida.txt```.
    2. ```run-especial:``` que serve para executar o programa criador de entradas primeiro e depois executar o programa principal com a entrada gerada pelo programa criador de entradas.
    3. ```create-input``` que serve basicamente para executar o programa criador de entradas para criar entradas com números aleatórios.
