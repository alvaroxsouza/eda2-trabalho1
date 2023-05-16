#ifndef HASH_PERFEITO_CPP
#define HASH_PERFEITO_CPP

#include "hash_perfeito.hpp"

using namespace hash_perfeito_class;

/**
 * Função para inserir chaves na tabela de hashing perfeito.
 *
 * A função recebe referências para os vetores do nível um (nivel_um) e do nível dois (nivel_dois),
 * um vetor de chaves a serem inseridas (chaves), o tamanho da tabela hash (tamanho_arquivo),
 * os parâmetros a e b para a função de hash, além de referências para as variáveis total_chaves_inseridas_perfeito
 * e quantidade_acessos_total_perfeito para contabilização de informações.
 *
 * Parâmetros:
 *   - nivel_um: referência para o vetor de vetores do nível um.
 *   - nivel_dois: referência para o vetor de vetores do nível dois.
 *   - chaves: vetor de chaves a serem inseridas.
 *   - tamanho_arquivo: tamanho da tabela hash.
 *   - a: parâmetro a da função de hash.
 *   - b: parâmetro b da função de hash.
 *   - total_chaves_inseridas_perfeito: referência para a variável de contagem total de chaves inseridas.
 *   - quantidade_acessos_total_perfeito: referência para a variável de contagem total de acessos.
 *
 * A função realiza a inserção das chaves na tabela de hashing perfeito.
 * Primeiramente, itera sobre as chaves a serem inseridas e calcula o índice h no nível um para cada uma delas.
 * Em seguida, redimensiona o vetor do registro principal correspondente no nível um e adiciona a chave.
 * A contagem de acessos é incrementada em cada inserção.
 *
 * Após a inserção no nível um, itera sobre os registros principais do nível um e verifica a quantidade de chaves em cada um.
 * Caso haja apenas uma chave, calcula o índice h no nível dois e insere a chave diretamente no vetor correspondente.
 * Novamente, a contagem de acessos é incrementada.
 *
 * Para registros principais com mais de uma chave, redimensiona o vetor correspondente no nível dois para acomodar o número de chaves ao quadrado.
 * Itera sobre as chaves do registro principal, calcula o índice h no nível dois e verifica se a posição está vazia.
 * Se estiver vazia, insere a chave nessa posição e incrementa a contagem de acessos.
 * Caso contrário, realiza uma busca linear por uma posição vazia no vetor até encontrar um espaço disponível para inserção da chave.
 * A contagem de acessos é incrementada em cada iteração do loop de busca.
 *
 * Ao final da função, as chaves são devidamente inseridas nos níveis um e dois da tabela de hashing perfeito,
 * e as contagens de chaves inseridas e acessos são atualizadas.
 */
void hash_perfeito::insere_perfeito_hash(vector<vector<long int>>& nivel_um,
                vector<vector<long int>>& nivel_dois,
                vector<long int>& chaves,
                long int tamanho_arquivo,
                int a, int b,
                long int& total_chaves_inseridas_perfeito,
                long int& quantidade_acessos_total_perfeito) {

    for (unsigned long int i = 0; i < chaves.size(); i++) {
        long int h = ((a * chaves[i] + b) % 101) % tamanho_arquivo;
        nivel_um[h].resize(nivel_um[h].size() + 1, chaves[i]);
        quantidade_acessos_total_perfeito++;
        total_chaves_inseridas_perfeito++;
    }

    for (long int i = 0; i < tamanho_arquivo; i++) {
        long int n = nivel_um[i].size();
        if (n == 1) {
            long int h = ((a * nivel_um[i][0] + b) % 101) % tamanho_arquivo;
            nivel_dois[h].resize(1, nivel_um[i][0]);
            quantidade_acessos_total_perfeito++;
        } else if (n > 1) {
            nivel_dois[i].resize(n * n);
            for (long int j = 0; j < n; j++) {
                long int h = ((a * nivel_um[i][j] + b) % 101) % (n * n);
                if (nivel_dois[i][h] == 0) {
                    nivel_dois[i][h] = nivel_um[i][j];
                    quantidade_acessos_total_perfeito++;
                } else {
                    long int k = h;
                    do {
                        k = (k + 1) % (n * n);
                        quantidade_acessos_total_perfeito++;
                    } while (nivel_dois[i][k] != 0); 
                    nivel_dois[i][k] = nivel_um[i][j];
                }
            }
        }
    }
}

#endif