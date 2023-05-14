#ifndef HASH_SONDAGEM_LINEAR_SAIDA_CPP
#define HASH_SONDAGEM_LINEAR_SAIDA_CPP

#include <iostream>
#include <iomanip>
#include "sondagem_linear.hpp"

using namespace std;
using namespace sondagem_linear_hash_class;

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