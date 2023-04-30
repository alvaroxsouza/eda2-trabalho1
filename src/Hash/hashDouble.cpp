#ifndef HASH_DOUBLE_CPP
#define HASH_DOUBLE_CPP

#include "hashDouble.hpp"

using namespace HashDoubleClass;

// Função de hash 1 (h1 = Chave mod Número de registros)
int hashDouble1(int chave, int quantidade_de_registros) {
    return chave % quantidade_de_registros;
}

/*Função de hash 2 (h2 = 1, se a chave for menor que o número de registros e h2 = chão da divisão entre Chave e número de registros
nos demais casos)*/
int hashDouble2(int chave, int quantidade_de_registros) {
    if(chave < quantidade_de_registros){ 
        chave = 1;
    }
    if (chave >= quantidade_de_registros){
        chave = floor (chave / quantidade_de_registros);
    }
    return chave;
}

// Função de criação da tabela hash
vector<int> criar_tabela_hash_double(int quantidade_de_registros) {
    int posicao_vazia = -1;
    vector<int> tabela_hash(quantidade_de_registros, posicao_vazia);
    return tabela_hash;
}

// Função para inserção das chaves usando hashing duplo
void HashDouble::insertDoubleHash(vector<int>& tabela_hash, int chave, int quantidade_de_registros,
            int& total_chaves_inseridas, int& total_acessos) {
    // while(total_chaves_inseridas < quantidade_de_registros) { // se o total de chaves alcançar o número de registros disponíveis encerra o loop

        if(chave == 0) return; //se chave for 0, saia do loop

        int h1 = hashDouble1(chave, quantidade_de_registros); // chamada para calcular o h1
        int h2 = hashDouble2(chave, quantidade_de_registros); // chamada para calcular o h2

        if (tabela_hash[h1] == -1) { // caso em que, usando h1, a posição calculada está disponível
            tabela_hash[h1] = chave; // chave inserida 
            total_chaves_inseridas++; // incrementa o total de chaves inseridas
            total_acessos++; // incrementa o total de acessos
        } else { // caso em que, usando h1, a posição calculada está ocupada
            int i = 1;
            int nova_posicao = (h1 + i*h2) % quantidade_de_registros; // calcula a nova posição usando o h2 
            total_acessos++; // incrementa o total de acessos

            while(tabela_hash[nova_posicao] != -1) { /* o programa continua até que encontre uma posição que esteja disponível, 
                                                atualizando a posição e o número de acessos que vão sendo feitos*/
                i++;
                nova_posicao = (h1 + i*h2) % quantidade_de_registros; // calcula a nova posição usando o h2
                total_acessos++; // incrementa o total de acessos
            }
            tabela_hash[nova_posicao] = chave; // chave inserida
            total_chaves_inseridas++; // incrementa o total de chaves inseridas
            total_acessos++; // incrementa o total de acessos
        }
    // }
}

#endif
