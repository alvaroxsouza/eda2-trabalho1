#ifndef HASH_PERFECT_SAIDA_CPP
#define HASH_PERFECT_SAIDA_CPP

#include <iostream>
#include "hashPerfect.hpp"

using namespace std;
using namespace HashPerfectClass;

void HashPerfect::saidaPefectHash(
    vector<vector<long int>>& nivel_um,
    vector<vector<long int>>& nivel_dois,
    long int quantidade_de_registros) {
    cout << "################## Hashing Perfeito ################### " << endl;
    cout << "################ Tabela de registros ################## " << endl;
    cout << "Nivel um - principal:" << endl;
    for (long int i = 0; i < quantidade_de_registros; i++) {
        cout << "registro " << i << ": ";
        if (nivel_um[i].empty()) {
            cout << "registro vazio" << endl;
        } else {
            // cout << "Tamanho do registro: " << i << nivel_um[i].size() << endl;
            for (unsigned long int j = 0; j < nivel_um[i].size(); j++) {
                // cout << "Entrou aqui" << endl;
                cout << nivel_um[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    for (long int i = 0; i < quantidade_de_registros; i++) {   
        if (nivel_um[i].size() != 0) {
            cout << "Nivel Dois - secundario:" << endl;
            cout << "registro " << i << ":" << endl;
            for (unsigned long int j = 0; j < nivel_dois[i].size(); j++) {
                if (nivel_dois[i].size() != 0){
                    if (nivel_dois[i][j] == 0) {
                        cout << j << ": registro vazio" << endl;
                    } 
                    else {
                        cout << j << ": " << nivel_dois[i][j] << endl;
                    }
                }                
            }
            cout << endl;
        }

    }
    cout << "####################################################" << endl;
}

#endif