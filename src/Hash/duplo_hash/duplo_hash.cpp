#ifndef HASH_DUPLO_CPP
#define HASH_DUPLO_CPP

#include "duplo_hash.hpp"
#include <iostream>

using namespace hash_duplo_class;

// Função de hash 1 (h1 = Chave mod Número de registros)
long int hashDouble1(long int chave, long int tamanho_arquivo) {
    return chave % tamanho_arquivo;
}

/*Função de hash 2 (h2 = 1, se a chave for menor que o número de registros e h2 = chão da divisão entre Chave e número de registros
nos demais casos)*/
long int hashDouble2(long int chave, long int tamanho_arquivo) {
    if(chave < tamanho_arquivo){ 
        chave = 1;
    }
    if (chave >= tamanho_arquivo){
        chave = floor (chave / tamanho_arquivo);
    }
    return chave;
}

// Função de criação da tabela hash
vector<long int> criar_tabela_hash_double(long int tamanho_arquivo) {
    long int posicao_vazia = -1;
    vector<long int> tabela_hash(tamanho_arquivo, posicao_vazia);
    return tabela_hash;
}

// Função para inserção das chaves usando hashing duplo
void hash_duplo::insere_duplo_hash(
    vector<long int>& tabela_hash,
    long int chave,
    long int tamanho_arquivo,
    long int& total_chaves_inseridas_duplo,
    long int& quantidade_acessos_total_duplo) {

    if(chave == 0) return; //se chave for 0, saia do loop

    long int h1 = hashDouble1(chave, tamanho_arquivo); // chamada para calcular o h1
    long int h2 = hashDouble2(chave, tamanho_arquivo); // chamada para calcular o h2

    if (tabela_hash[h1] == -1) { // caso em que, usando h1, a posição calculada está disponível
        tabela_hash[h1] = chave; // chave inserida 
        total_chaves_inseridas_duplo++; // incrementa o total de chaves inseridas
        quantidade_acessos_total_duplo++; // incrementa o total de acessos
    } else { // caso em que, usando h1, a posição calculada está ocupada
        long int i = 1;
        long int nova_posicao = (h1 + i*h2) % tamanho_arquivo; // calcula a nova posição usando o h2 
        quantidade_acessos_total_duplo++; // incrementa o total de acessos

        while(tabela_hash[nova_posicao] != -1) { /* o programa continua até que encontre uma posição que esteja disponível, 
                                            atualizando a posição e o número de acessos que vão sendo feitos*/
            i++;
            nova_posicao = (h1 + i*h2) % tamanho_arquivo; // calcula a nova posição usando o h2
            quantidade_acessos_total_duplo++; // incrementa o total de acessos
        }
        tabela_hash[nova_posicao] = chave; // chave inserida
        total_chaves_inseridas_duplo++; // incrementa o total de chaves inseridas
        quantidade_acessos_total_duplo++; // incrementa o total de acessos
    }
}

#endif
