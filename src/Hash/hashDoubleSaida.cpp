#ifndef HASH_DOUBLE_SAIDA_HPP
#define HASH_DOUBLE_SAIDA_HPP

#include <iostream>
#include <iomanip>
#include "hashDouble.hpp"

using namespace std;
using namespace HashDoubleClass;

void HashDouble::saidaDoubleHash(vector<long int>& tabela_hash, long int quantidade_de_registros) {
    cout << "######################################################" << endl;
    cout << "################### Hashing Duplo ####################" << endl;
    cout << "######################################################" << endl;
    cout << "######################################################" << endl;
    cout << "################ Tabela de registros #################" << endl;
    cout << "######################################################" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "| " << left << setw(10) << "Registro" << " | " << setw(25) << "Valor" << " |" << endl;
    cout << "------------------------------------------------------" << endl;

    for (long int i = 0; i < quantidade_de_registros; i++) {
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