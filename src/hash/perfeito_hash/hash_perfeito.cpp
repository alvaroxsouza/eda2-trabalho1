#ifndef HASH_PERFEITO_CPP
#define HASH_PERFEITO_CPP

#include "hash_perfeito.hpp"

using namespace hash_perfeito_class;

void hash_perfeito::insere_perfeito_hash(vector<vector<long int>>& nivel_um,
                vector<vector<long int>>& nivel_dois,
                vector<long int>& chaves,
                long int tamanho_arquivo,
                int a, int b,
                long int& total_chaves_inseridas_perfeito,
                long int& quantidade_acessos_total_perfeito) {

    // a função de hash é dada por: h = ((a * chave + b) mod 101) mod quantidade de registros. 101 é o maior primo, definido previamente.

    // Inserção na tabela principal
    for (unsigned long int i = 0; i < chaves.size(); i++) {
        // tem um erro aqui que acredito ser na hora que está fazendo o resize do vetor, acrditando que está fazendo o redimensionamento de maneira errada
        long int h = ((a * chaves[i] + b) % 101) % tamanho_arquivo; // cálculo do hash
        nivel_um[h].resize(nivel_um[h].size() + 1, chaves[i]); // insere a chave no nível um
        quantidade_acessos_total_perfeito++; // incrementa o total de acessos
        total_chaves_inseridas_perfeito++; // incrementa o total de chaves inseridas
    }

    /*Inserção nas tabelas secundárias - quando em uma dada posição na tabela principal há apenas uma chave , essa posição 
    na tabela secundária tem tamanho igual a um referente a única chave a ser inserida. Por outro lado, quando em uma dada
    posição na tabela principal há mais de uma chave, essa posição na tabela secundária tem tamanho igual ao número de chaves
    nessa posição elevado ao quadrado*/
    for (long int i = 0; i < tamanho_arquivo; i++) {
        long int n = nivel_um[i].size();
        if (n == 1) {
            long int h = ((a * nivel_um[i][0] + b) % 101) % tamanho_arquivo;
            nivel_dois[h].resize(1, nivel_um[i][0]);
            quantidade_acessos_total_perfeito++; // incrementa o total de acessos
        } else if (n > 1) {
            nivel_dois[i].resize(n * n);
            for (long int j = 0; j < n; j++) {
                long int h = ((a * nivel_um[i][j] + b) % 101) % (n * n);
                if (nivel_dois[i][h] == 0) {
                    nivel_dois[i][h] = nivel_um[i][j];
                    quantidade_acessos_total_perfeito++; // incrementa o total de acessos
                } else {
                    long int k = h; // variável k, variável auxiliar que recebe o valor de hash
                    do {
                        k = (k + 1) % (n * n); // atualiza o valor de hash até que aja posição buscada disponível
                        quantidade_acessos_total_perfeito++; // incrementa o total de acessos
                    } while (nivel_dois[i][k] != 0); 
                    nivel_dois[i][k] = nivel_um[i][j]; /*insere a chave no nível dois (não incrementa o total de chaves inseridas pois já foi incrementada
                                                         na primeira passada, no nível um)*/
                }
            }
        }
    }
}

#endif