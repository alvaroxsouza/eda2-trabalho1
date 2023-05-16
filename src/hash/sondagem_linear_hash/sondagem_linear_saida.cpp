#ifndef HASH_SONDAGEM_LINEAR_SAIDA_CPP
#define HASH_SONDAGEM_LINEAR_SAIDA_CPP

#include <iostream>
#include <iomanip>
#include "sondagem_linear.hpp"

using namespace std;
using namespace sondagem_linear_hash_class;

/**
 * Função para exibir a tabela de registros do hashing por sondagem linear.
 *
 * A função recebe uma referência para o vetor tabela_hash que representa a tabela de registros,
 * e o tamanho_arquivo que indica o tamanho da tabela.
 *
 * Parâmetros:
 *   - tabela_hash: referência para o vetor que representa a tabela de registros.
 *   - tamanho_arquivo: tamanho da tabela de registros.
 *
 * A função exibe a tabela de registros do hashing por sondagem linear.
 * Itera sobre cada posição da tabela_hash e imprime o registro presente em cada posição.
 * Se o registro for -1, imprime um traço ("-") indicando que a posição está vazia.
 * Caso contrário, imprime o valor do registro.
 *
 * Ao final da função, a tabela de registros é exibida no formato adequado.
 */
void sondagem_linear_hash::saida_sondagem_linear(vector<long int>& tabela_hash,
    long int tamanho_arquivo) {
    cout << "######################################################" << endl;
    cout << "################## Sondagem Linear ###################" << endl;
    cout << "######################################################" << endl;
    cout << "######################################################" << endl;
    cout << "################ Tabela de registros #################" << endl;
    cout << "######################################################" << endl;

    cout << "------------------------------------------------------" << endl;
    cout << "| " << left << setw(10) << "Registro" << " | " << setw(15) << "Valor" << " |" << endl;
    cout << "------------------------------------------------------" << endl;

    for(long int i = 0; i < tamanho_arquivo; i++) {
        cout << "| " << left << setw(10) << i << " | ";
        if (tabela_hash[i] == -1) {
            cout << left << setw(15) << "-" << " |" << endl;
        }
        else {
            cout << left << setw(15) << tabela_hash[i] << " |" << endl;
        }
    }
    cout << "------------------------------------------------------" << endl;
    cout << "######################################################" << endl;
    cout << "######################################################" << endl;
    cout << endl << endl;
}

#endif