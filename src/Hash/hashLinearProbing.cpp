#ifndef HASH_LINEAR_PROBING_CPP
#define HASH_LINEAR_PROBING_CPP

#include "hashLinearProbing.hpp"
#include <iostream>

using namespace std;
using namespace HashLinearProbingClass;

// Função de hash 1 (h1 = Chave mod Número de registros)
int hashLinearProbing1(int chave, int quantidade_de_registros) {
    return chave % quantidade_de_registros;
}

// Função para inserção das chaves usando hashing com encadeamento linear
void HashLinearProbing::insertLinearProbingHash(
    vector<long int>& tabela_hash,
    long int chave,
    long int quantidade_de_registros,
    long int& total_chaves_inseridas,
    long int& total_acessos) {
    // while(total_chaves_inseridas < quantidade_de_registros) { // se o total de chaves alcançar o número de registros disponíveis encerra o loop
        
        if(chave == 0) return; //se chave for 0, saia do loop

        long int h1 = hashLinearProbing1(chave, quantidade_de_registros); // chamada para calcular o h1

        if (tabela_hash[h1] == -1) { // caso em que, usando h1, a posição calculada está disponível
            tabela_hash[h1] = chave; // chave inserida 
            total_chaves_inseridas++; // incrementa o total de chaves inseridas
            total_acessos++; // incrementa o total de acessos
        } else { // caso em que, usando h1, a posição calculada está ocupada
            long int i = 1;
            long int nova_posicao = (h1 + i) % quantidade_de_registros;
            total_acessos++; // incrementa o total de acessos

            while(tabela_hash[nova_posicao] != -1) { /* o programa continua até que encontre uma posição que esteja disponível, 
                                                atualizando a posição e o número de acessos que vão sendo feitos*/
                i++;
                nova_posicao = (h1 + i) % quantidade_de_registros;
                total_acessos++; // incrementa o total de acessos

            }

            tabela_hash[nova_posicao] = chave; // chave inserida
            total_chaves_inseridas++; // incrementa o total de chaves inseridas
            total_acessos++; // incrementa o total de acessos
        }
    // }
}

#endif