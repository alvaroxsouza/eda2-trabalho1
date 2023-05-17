#ifndef HASH_DUPLO_CPP
#define HASH_DUPLO_CPP

#include "duplo_hash.hpp"
#include <iostream>

using namespace hash_duplo_class;


/** 
 * Função para inserir uma chave usando o método de hashing duplo.
 * 
 * A função recebe uma tabela hash, uma chave, o tamanho do arquivo, 
 * o total de chaves inseridas usando hashing duplo e a quantidade de acessos 
 * totais realizados durante a inserção.
 * 
 * Parâmetros:
 *   - tabela_hash: vetor contendo a tabela hash.
 *   - chave: chave a ser inserida na tabela hash.
 *   - tamanho_arquivo: tamanho do arquivo/tabela hash.
 *   - total_chaves_inseridas_duplo: referência para a variável que guarda o total de chaves inseridas.
 *   - quantidade_acessos_total_duplo: referência para a variável que guarda a quantidade de acessos totais.
 * 
 * A função utiliza duas funções de hash (funcao_hash_h1 e funcao_hash_h2) para calcular as posições iniciais h1 e h2.
 * 
 * Se a posição h1 da tabela hash estiver vazia, a chave é inserida diretamente nessa posição.
 * Caso contrário, a função utiliza o método de sondagem dupla para encontrar uma posição vazia na tabela.
 * A cada iteração, é calculada uma nova posição usando a fórmula (h1 + i*h2) % tamanho_arquivo, onde i é um contador.
 * O processo continua até encontrar uma posição vazia ou até percorrer toda a tabela (controle >= tamanho_arquivo).
 * 
 * Após encontrar uma posição vazia, a chave é inserida nessa posição e as variáveis de contagem são atualizadas.
 * 
 * Observação: A função assume que a tabela_hash está inicializada com -1 em todas as posições vazias.
 */
void hash_duplo::insere_duplo_hash(
    vector<long int>& tabela_hash,
    long int chave,
    long int tamanho_arquivo,
    long int& total_chaves_inseridas_duplo,
    long int& quantidade_acessos_total_duplo) {
    
    if(total_chaves_inseridas_duplo < tamanho_arquivo) {
        if(chave == 0) return;

        long int h1 = hash_funcao::funcao_hash_h1(chave, tamanho_arquivo);
        long int h2 = hash_funcao::funcao_hash_h2(chave, tamanho_arquivo);

        if (tabela_hash[h1] == -1) {
            tabela_hash[h1] = chave;
            total_chaves_inseridas_duplo++;
            quantidade_acessos_total_duplo++;
        } else {
            long int i = 1;
            long int nova_posicao = (h1 + i*h2) % tamanho_arquivo;
            quantidade_acessos_total_duplo++;

            while(tabela_hash[nova_posicao] != -1) {
                i++;
                nova_posicao = (h1 + i*h2) % tamanho_arquivo;
                quantidade_acessos_total_duplo++;
            }
            tabela_hash[nova_posicao] = chave;
            total_chaves_inseridas_duplo++;
            quantidade_acessos_total_duplo++;
        }
    } else {
        return;
    }
}

#endif
