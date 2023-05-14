#ifndef HASH_FUNCAO_CPP
#define HASH_FUNCAO_CPP

#include "funcao_hash.hpp"

using namespace hash_funcao_class;

long int hash_funcao::funcao_hash_h1(
    long int valor_node,
    long int tamanho_arquivo) {
    return valor_node % tamanho_arquivo;
}

long int hash_funcao::funcao_hash_h2(
    long int chave,
    long int tamanho_arquivo) {
        
    if(chave < tamanho_arquivo){ 
        chave = 1;
    }
    if (chave >= tamanho_arquivo){
        chave = floor (chave / tamanho_arquivo);
    }
    return chave;
}

#endif