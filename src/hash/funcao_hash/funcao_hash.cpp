#ifndef HASH_FUNCAO_CPP
#define HASH_FUNCAO_CPP

#include "funcao_hash.hpp"

using namespace hash_funcao_class;

/**
 * Função de hash h1.
 *
 * A função recebe um valor de nó e o tamanho da tabela hash e retorna o resultado da operação de módulo entre o valor do nó e o tamanho da tabela.
 * Isso garante que o valor retornado esteja dentro do intervalo válido de índices da tabela hash.
 *
 * Parâmetros:
 *   - valor_node: valor do nó para calcular o hash.
 *   - tamanho_arquivo: tamanho da tabela hash.
 *
 * Retorno:
 *   - O valor de hash calculado usando a função h1.
 */
long int hash_funcao::funcao_hash_h1(
    long int valor_node,
    long int tamanho_arquivo) {
    return valor_node % tamanho_arquivo;
}

/**
 * Função de hash h2.
 *
 * A função recebe uma chave e o tamanho da tabela hash e calcula um valor de hash usando a chave.
 * Se a chave for menor que o tamanho da tabela, o valor de hash será 1.
 * Se a chave for maior ou igual ao tamanho da tabela, o valor de hash será a divisão inteira entre a chave e o tamanho da tabela.
 *
 * Parâmetros:
 *   - chave: chave para calcular o hash.
 *   - tamanho_arquivo: tamanho da tabela hash.
 *
 * Retorno:
 *   - O valor de hash calculado usando a função h2.
 */
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