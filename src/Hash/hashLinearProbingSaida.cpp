#ifndef HASH_LINEAR_PROBING_SAIDA_CPP
#define HASH_LINEAR_PROBING_SAIDA_CPP

#include <iostream>
#include <iomanip>
#include "hashLinearProbing.hpp"

using namespace std;
using namespace HashLinearProbingClass;

void HashLinearProbing::saidaLinearProbingHash(vector<long int>& tabela_hash,
    long int quantidade_de_registros) {
    cout << "######################################################" << endl;
    cout << "################## Sondagem Linear ###################" << endl;
    cout << "######################################################" << endl;
    cout << "######################################################" << endl;
    cout << "################ Tabela de registros #################" << endl;
    cout << "######################################################" << endl;

    cout << "------------------------------------------------------" << endl;
    cout << "| " << left << setw(10) << "Registro" << " | " << setw(15) << "Valor" << " |" << endl;
    cout << "------------------------------------------------------" << endl;

    for(long int i = 0; i < quantidade_de_registros; i++) {
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