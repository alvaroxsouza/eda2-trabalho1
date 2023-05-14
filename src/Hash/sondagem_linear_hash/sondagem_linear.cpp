#ifndef HASH_SONDAGEM_LINEAR_CPP
#define HASH_SONDAGEM_LINEAR_CPP

#include <iostream>
#include "sondagem_linear.hpp"

using namespace std;
using namespace sondagem_linear_hash_class;

// Função de hash 1 (h1 = Chave mod Número de registros)
// int hash_linear_probing1(int chave, int tamanho_arquivo) {
//     return chave % tamanho_arquivo;
// }

// Função para inserção das chaves usando hashing com encadeamento linear
void sondagem_linear_hash::insere_sondagem_linear(
    vector<long int>& tabela_hash,
    long int chave,
    long int tamanho_arquivo,
    long int& total_chaves_inseridas_sondagem,
    long int& quantidade_acessos_total_sondagem_linear) {

    if(total_chaves_inseridas_sondagem < tamanho_arquivo) {
        if(chave == 0) return; //se chave for 0, saia do loop

        long int h1 = hash_funcao::funcao_hash_h1(chave, tamanho_arquivo); // chamada para calcular o h1

        if (tabela_hash[h1] == -1) { // caso em que, usando h1, a posição calculada está disponível
            tabela_hash[h1] = chave; // chave inserida 
            total_chaves_inseridas_sondagem++; // incrementa o total de chaves inseridas
            quantidade_acessos_total_sondagem_linear++; // incrementa o total de acessos
        } else { // caso em que, usando h1, a posição calculada está ocupada
            long int i = 1;
            long int nova_posicao = (h1 + i) % tamanho_arquivo;
            quantidade_acessos_total_sondagem_linear++; // incrementa o total de acessos
            while(tabela_hash[nova_posicao] != -1) { /* o programa continua até que encontre uma posição que esteja disponível, 
                                                atualizando a posição e o número de acessos que vão sendo feitos*/
                i++;
                nova_posicao = (h1 + i) % tamanho_arquivo;
                quantidade_acessos_total_sondagem_linear++; // incrementa o total de acessos

            }
            tabela_hash[nova_posicao] = chave; // chave inserida
            total_chaves_inseridas_sondagem++; // incrementa o total de chaves inseridas
            quantidade_acessos_total_sondagem_linear++; // incrementa o total de acessos
        }
    } else {
        return;
    }
}

#endif
