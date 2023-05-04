#ifndef HASH_PERFECT_CPP
#define HASH_PERFECT_CPP

#include "hashPerfect.hpp"

using namespace HashPerfectClass;

//Função para criação da tabela do nível 1
// vector<vector<long int>> criar_tabela_nivel_um(long int quantidade_de_registros) {
//     vector<vector<long int>> tabela_nivel_um(quantidade_de_registros);
//     return tabela_nivel_um;
// }

// //Função para criação da tabela do nível 2
// vector<vector<long int>> criar_tabela_nivel_dois(long int quantidade_de_registros) {
//     vector<vector<long int>> tabela_nivel_dois(quantidade_de_registros);
//     return tabela_nivel_dois;
// }

// Função para gerar as variáveis a e b, de forma aleatória. Estas irão compôr a função de hash
// void gerar_variaveis_aleatorias(int &a, int &b) {
//     srand(time(NULL));
//     a = rand() % 101;
//     b = rand() % 101;
// }

void HashPerfect::insertPerfectHash(vector<vector<long int>>& nivel_um,
                vector<vector<long int>>& nivel_dois,
                vector<long int>& chaves,
                long int quantidade_de_registros,
                int a, int b,
                long int& total_acessos,
                long int& total_chaves_inseridas) {
    
    // vector<int> chaves; // Um vetor de chaves, auxiliar, é usado para armazenar as chaves, passadas na entrada, que serão inseridas nos registros

    // while (chave != 0) { // armazendo as chaves fornecidas na entrada em um vetor auxiliar
    //     chaves.push_back(chave);
    //     cin >> chave;
    // }

    // a função de hash é dada por: h = ((a * chave + b) mod 101) mod quantidade de registros. 101 é o maior primo, definido previamente.

    // Inserção na tabela principal
    for (unsigned long int i = 0; i < chaves.size(); i++) {
        // tem um erro aqui que acredito ser na hora que está fazendo o resize do vetor, acrditando que está fazendo o redimensionamento de maneira errada
        long int h = ((a * chaves[i] + b) % 101) % quantidade_de_registros; // cálculo do hash
        nivel_um[h].resize(nivel_um[h].size() + 1, chaves[i]); // insere a chave no nível um
        total_acessos++; // incrementa o total de acessos
        total_chaves_inseridas++; // incrementa o total de chaves inseridas
    }

    /*Inserção nas tabelas secundárias - quando em uma dada posição na tabela principal há apenas uma chave , essa posição 
    na tabela secundária tem tamanho igual a um referente a única chave a ser inserida. Por outro lado, quando em uma dada
    posição na tabela principal há mais de uma chave, essa posição na tabela secundária tem tamanho igual ao número de chaves
    nessa posição elevado ao quadrado*/
    for (long int i = 0; i < quantidade_de_registros; i++) {
        long int n = nivel_um[i].size();
        if (n == 1) {
            long int h = ((a * nivel_um[i][0] + b) % 101) % quantidade_de_registros;
            nivel_dois[h].resize(1, nivel_um[i][0]);
            total_acessos++; // incrementa o total de acessos
        } else if (n > 1) {
            nivel_dois[i].resize(n * n);
            for (long int j = 0; j < n; j++) {
                long int h = ((a * nivel_um[i][j] + b) % 101) % (n * n);
                if (nivel_dois[i][h] == 0) {
                    nivel_dois[i][h] = nivel_um[i][j];
                    total_acessos++; // incrementa o total de acessos
                } else {
                    long int k = h; // variável k, variável auxiliar que recebe o valor de hash
                    do {
                        k = (k + 1) % (n * n); // atualiza o valor de hash até que aja posição buscada disponível
                        total_acessos++; // incrementa o total de acessos
                    } while (nivel_dois[i][k] != 0); 
                    nivel_dois[i][k] = nivel_um[i][j]; /*insere a chave no nível dois (não incrementa o total de chaves inseridas pois já foi incrementada
                                                         na primeira passada, no nível um)*/
                }
            }
        }
    }
}

#endif