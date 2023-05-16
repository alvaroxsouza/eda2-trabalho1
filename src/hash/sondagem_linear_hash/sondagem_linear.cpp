#ifndef HASH_SONDAGEM_LINEAR_CPP
#define HASH_SONDAGEM_LINEAR_CPP

#include <iostream>
#include "sondagem_linear.hpp"

using namespace std;
using namespace sondagem_linear_hash_class;

/**
 * Função para inserir uma chave na tabela de registros do hashing por sondagem linear.
 *
 * A função recebe uma referência para o vetor tabela_hash que representa a tabela de registros,
 * a chave a ser inserida, o tamanho_arquivo que indica o tamanho da tabela,
 * e as variáveis total_chaves_inseridas_sondagem e quantidade_acessos_total_sondagem_linear que
 * são atualizadas durante o processo de inserção.
 *
 * Parâmetros:
 *   - tabela_hash: referência para o vetor que representa a tabela de registros.
 *   - chave: chave a ser inserida na tabela.
 *   - tamanho_arquivo: tamanho da tabela de registros.
 *   - total_chaves_inseridas_sondagem: variável contadora do total de chaves inseridas.
 *   - quantidade_acessos_total_sondagem_linear: variável contadora da quantidade de acessos realizados.
 *
 * A função insere a chave na tabela de registros utilizando a estratégia de sondagem linear.
 * Verifica se ainda há espaço disponível na tabela (total_chaves_inseridas_sondagem < tamanho_arquivo).
 * Se a chave for igual a 0, a função retorna sem fazer nenhuma inserção.
 * Calcula a posição inicial (h1) utilizando a função de hash h1.
 * Se a posição inicial estiver vazia (tabela_hash[h1] == -1), insere a chave nessa posição.
 * Caso contrário, realiza a sondagem linear incrementando o índice (i) e recalculando a nova posição
 * até encontrar uma posição vazia na tabela (tabela_hash[nova_posicao] == -1).
 * Insere a chave na posição encontrada.
 *
 * Ao final da função, as variáveis total_chaves_inseridas_sondagem e quantidade_acessos_total_sondagem_linear
 * são atualizadas de acordo com as operações realizadas.
 */
void sondagem_linear_hash::insere_sondagem_linear(
    vector<long int>& tabela_hash,
    long int chave,
    long int tamanho_arquivo,
    long int& total_chaves_inseridas_sondagem,
    long int& quantidade_acessos_total_sondagem_linear) {

    if(total_chaves_inseridas_sondagem < tamanho_arquivo) {
        if(chave == 0) return;

        long int h1 = hash_funcao::funcao_hash_h1(chave, tamanho_arquivo);

        if (tabela_hash[h1] == -1) {
            tabela_hash[h1] = chave;
            total_chaves_inseridas_sondagem++;
            quantidade_acessos_total_sondagem_linear++;
        } else {
            long int i = 1;
            long int nova_posicao = (h1 + i) % tamanho_arquivo;
            quantidade_acessos_total_sondagem_linear++;
            while(tabela_hash[nova_posicao] != -1) {
                i++;
                nova_posicao = (h1 + i) % tamanho_arquivo;
                quantidade_acessos_total_sondagem_linear++;

            }
            tabela_hash[nova_posicao] = chave;
            total_chaves_inseridas_sondagem++;
            quantidade_acessos_total_sondagem_linear++;
        }
    } else {
        return;
    }
}

#endif
