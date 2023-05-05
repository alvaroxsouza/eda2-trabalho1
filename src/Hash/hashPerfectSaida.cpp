#ifndef HASH_PERFECT_SAIDA_CPP
#define HASH_PERFECT_SAIDA_CPP

#include <iostream>
#include <iomanip>
#include "hashPerfect.hpp"

using namespace std;
using namespace HashPerfectClass;

void imprimeNivelUm(vector<vector<long int>>& nivel_um, long int quantidade_de_registros) {
    cout << "###########################################################" << endl;
    cout << "################### Nível um - principal ##################" << endl;
    cout << "###########################################################" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "| Registro |                 Chaves                        " << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (long int i = 0; i < quantidade_de_registros; i++) {
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

void imprimeNivelDois(
    vector<vector<long int>>& nivel_um,
    vector<vector<long int>>& nivel_dois,
    long int quantidade_de_registros) {
    
    bool encontrou_registro = false;
    
    cout << "###########################################################" << endl;
    cout << "################# Nível Dois - secundário #################" << endl;
    cout << "###########################################################" << endl;
    for (long int i = 0; i < quantidade_de_registros; i++) {
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

void HashPerfect::saidaPefectHash(
    vector<vector<long int>>& nivel_um,
    vector<vector<long int>>& nivel_dois,
    long int quantidade_de_registros) {
    cout << "###########################################################" << endl;
    cout << "#################### Hashing Perfeito #####################" << endl;
    cout << "###########################################################" << endl;
    cout << "###########################################################" << endl;
    cout << "################## Tabela de registros ####################" << endl;
    cout << "###########################################################" << endl;

    imprimeNivelUm(nivel_um, quantidade_de_registros);
    imprimeNivelDois(nivel_um, nivel_dois, quantidade_de_registros);

    cout << "###########################################################" << endl;
    cout << "###########################################################" << endl;
    cout << endl << endl;
}

#endif