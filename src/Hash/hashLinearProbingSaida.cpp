#ifndef HASH_LINEAR_PROBING_SAIDA_CPP
#define HASH_LINEAR_PROBING_SAIDA_CPP

#include <iostream>
#include "hashLinearProbing.hpp"

using namespace std;
using namespace HashLinearProbingClass;

void HashLinearProbing::saidaLinearProbingHash(vector<long int>& tabela_hash,
    long int quantidade_de_registros) {
    cout << endl;
    cout << "################## Linear Probing ################### " << endl;
    cout << "################ Tabela de registros ################ " << endl;
    for(long int i = 0; i < quantidade_de_registros; i++) {
        if (tabela_hash[i] == -1) {
            cout << "Registro " << i << ": Registro Vazio" << endl;
        }
        else {
            cout << "Registro " << i << ": " << tabela_hash[i] << endl;
        }
    }
    cout << "####################################################" << endl;
}

#endif