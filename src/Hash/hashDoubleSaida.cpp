#ifndef HASH_DOUBLE_SAIDA_HPP
#define HASH_DOUBLE_SAIDA_HPP

#include <iostream>
#include "hashDouble.hpp"

using namespace std;
using namespace HashDoubleClass;

void HashDouble::saidaDoubleHash(vector<long int>& tabela_hash, long int quantidade_de_registros) {
    cout << endl;
    cout << "################### Double Hash ################### " << endl;
    cout << "############### Tabela de registros ############### " << endl;
    for (long int i = 0; i < quantidade_de_registros; i++) {
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