#ifndef HASH_PERFEITO_SAIDA_CPP
#define HASH_PERFEITO_SAIDA_CPP

#include <iostream>
#include <iomanip>
#include "hash_perfeito.hpp"

using namespace std;
using namespace hash_perfeito_class;

/**
 * Função para imprimir o nível um da tabela de registros do hashing perfeito.
 *
 * A função recebe uma referência para um vetor de vetores (nivel_um) e o tamanho da tabela hash.
 * 
 * Parâmetros:
 *   - nivel_um: referência para o vetor de vetores do nível um.
 *   - tamanho_arquivo: tamanho da tabela hash.
 *
 * A função imprime na saída padrão o nível um da tabela de registros do hashing perfeito.
 * O nível um contém os registros principais, cada um associado a um conjunto de chaves.
 * Cada registro principal é exibido, seguido das suas chaves entre colchetes.
 * A formatação inclui cabeçalho, separadores de coluna e linha para cada registro.
 *
 * A função verifica se há chaves associadas a cada registro principal antes de imprimir.
 * Caso não haja chaves, um hífen é exibido para indicar a ausência.
 */
void imprime_nivel_um(vector<vector<long int>>& nivel_um, long int tamanho_arquivo) {
    cout << "###########################################################" << endl;
    cout << "################### Nível um - principal ##################" << endl;
    cout << "###########################################################" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "| Registro |                 Chaves                        " << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (long int i = 0; i < tamanho_arquivo; i++) {
        cout << "|   " << setw(5) << i << "  | ";
        if (nivel_um[i].empty()) {
            cout << "-" << endl;
        } else {
            for (unsigned long int j = 0; j < nivel_um[i].size(); j++) {
                cout << setw(5) << nivel_um[i][j] << "";
            }
            cout << setw(35 - nivel_um[i].size() * 5) << " " << endl;
        }
    }
    cout << "-----------------------------------------------------------" << endl;
}

/**
 * Função para imprimir o nível dois da tabela de registros do hashing perfeito.
 *
 * A função recebe duas referências para vetores de vetores (nivel_um e nivel_dois) e o tamanho da tabela hash.
 * 
 * Parâmetros:
 *   - nivel_um: referência para o vetor de vetores do nível um.
 *   - nivel_dois: referência para o vetor de vetores do nível dois.
 *   - tamanho_arquivo: tamanho da tabela hash.
 *
 * A função imprime na saída padrão o nível dois da tabela de registros do hashing perfeito.
 * O nível dois contém os índices secundários associados aos índices principais do nível um.
 * Cada índice principal é exibido como um registro, seguido pelos seus índices secundários e seus respectivos valores.
 * A formatação inclui cabeçalho, separadores de coluna e linhas para cada índice secundário.
 *
 * A função também verifica se há registros no nível dois antes de imprimir.
 * Caso não haja registros, uma mensagem informando a ausência de registros é exibida.
 */
void imprime_nivel_dois(
    vector<vector<long int>>& nivel_um,
    vector<vector<long int>>& nivel_dois,
    long int tamanho_arquivo) {
    
    bool encontrou_registro = false;
    
    cout << "###########################################################" << endl;
    cout << "################# Nível Dois - secundário #################" << endl;
    cout << "###########################################################" << endl;
    for (long int i = 0; i < tamanho_arquivo; i++) {
        if (!nivel_um[i].empty()) {
            encontrou_registro = true;
            cout << "Registro " << setw(2) << i << ": " << endl;
            cout << "---------------------------------" << endl;
            cout << "| Indice|         Valor         |" << endl;
            cout << "---------------------------------" << endl;
            for (unsigned long int j = 0; j < nivel_dois[i].size(); j++) {
                cout << "| " << setw(5) << j << " | ";
                if (nivel_dois[i][j] == 0) {
                    cout << setw(21) << "-";
                } else {
                    cout << setw(21) << nivel_dois[i][j];
                }
                cout << " |" << endl;
            }
            cout << "---------------------------------" << endl;
        }
    }
    if (!encontrou_registro) {
        cout << "Não há registros na tabela." << endl;
    }
}

/**
 * Função para exibir a saída do hashing perfeito.
 *
 * A função recebe duas referências para vetores de vetores (nivel_um e nivel_dois) e o tamanho da tabela hash.
 * 
 * Parâmetros:
 *   - nivel_um: referência para o vetor de vetores do nível um.
 *   - nivel_dois: referência para o vetor de vetores do nível dois.
 *   - tamanho_arquivo: tamanho da tabela hash.
 *
 * A função imprime na saída padrão a tabela de registros do hashing perfeito.
 * A tabela é dividida em dois níveis: nível um e nível dois.
 * Primeiro, é impresso o nível um, que contém os índices principais da tabela hash.
 * Em seguida, é impresso o nível dois, que contém os índices secundários associados aos índices principais.
 * Cada nível é formatado com colunas para o índice do registro e os valores dos índices correspondentes.
 *
 * A formatação da tabela inclui linhas de cabeçalho, separadores e linhas para cada registro.
 * Após exibir a tabela, são apresentadas linhas de separação e uma mensagem de finalização.
 */
void hash_perfeito::saida_perfeito_hash(
    vector<vector<long int>>& nivel_um,
    vector<vector<long int>>& nivel_dois,
    long int tamanho_arquivo) {
    cout << "###########################################################" << endl;
    cout << "#################### Hashing Perfeito #####################" << endl;
    cout << "###########################################################" << endl;
    cout << "###########################################################" << endl;
    cout << "################## Tabela de registros ####################" << endl;
    cout << "###########################################################" << endl;

    imprime_nivel_um(nivel_um, tamanho_arquivo);
    imprime_nivel_dois(nivel_um, nivel_dois, tamanho_arquivo);

    cout << "###########################################################" << endl;
    cout << "###########################################################" << endl;
    cout << endl << endl;
}

#endif