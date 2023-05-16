#ifndef HASH_DUPLO_SAIDA_HPP
#define HASH_DUPLO_SAIDA_HPP

#include <iostream>
#include <iomanip>
#include "duplo_hash.hpp"

using namespace std;
using namespace hash_duplo_class;


/* 
* Função de saída para o Duplo Hash, fazendo com que a saída fique organizada
* em forma de tabela.
*/
void hash_duplo::saida_duplo_hash(vector<long int>& tabela_hash, long int tamanho_arquivo) {
    cout << "######################################################" << endl;
    cout << "################### Hashing Duplo ####################" << endl;
    cout << "######################################################" << endl;
    cout << "######################################################" << endl;
    cout << "################ Tabela de registros #################" << endl;
    cout << "######################################################" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "| " << left << setw(10) << "Registro" << " | " << setw(25) << "Valor" << " |" << endl;
    cout << "------------------------------------------------------" << endl;

    for (long int i = 0; i < tamanho_arquivo; i++) {
        cout << "| " << left << setw(10) << i << " | ";
        if (tabela_hash[i] == -1) {
            cout << left << setw(25) << "-" << " |" << endl;
        }
        else {
            cout << left << setw(25) << tabela_hash[i] << " |" << endl;
        }
    }
    cout << "------------------------------------------------------" << endl;
    cout << "######################################################" << endl;
    cout << "######################################################" << endl;
    cout << endl << endl;
}

#endif