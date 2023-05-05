#ifndef HASH_ENCADEAMENTO_EXPLICITO_SAIDA_CPP
#define HASH_ENCADEAMENTO_EXPLICITO_SAIDA_CPP

#include <iostream>
#include "hashEncadeamentoExplicito.hpp"

using namespace std;
using namespace HashEncadeamentoExplicitoClass;

void HashEncadeamentoExplicito::saidaEncadeamentoExplicitoHash(Node* arquivo,
    long int tamanhoDoArquivo) {
    cout << "################### Encadeamento explícito com #################### " << endl;
    cout << "####################### Alocação estática ######################### " << endl;
    cout << "####################### Tabela de registros ####################### " << endl;
    for(long int i = 0; i < tamanhoDoArquivo; i++) {
        if (!arquivo[i].isEstaOcupado()) {
            cout << "Registro " << i << ": Registro Vazio" << endl;
        }
        else {
            cout << "Registro " << i << ": " << arquivo[i].getValorDoNode() <<  " "
                << "Ponteiro para o próximo: " << arquivo[i].getProximoNode() << endl;
        }
    }
    cout << "###################################################################" << endl;
}

#endif
