#ifndef HASH_ENCADEAMENTO_EXPLICITO_SAIDA_CPP
#define HASH_ENCADEAMENTO_EXPLICITO_SAIDA_CPP

#include <iostream>
#include <iomanip>
#include "hashEncadeamentoExplicito.hpp"

using namespace std;
using namespace HashEncadeamentoExplicitoClass;

void HashEncadeamentoExplicito::saidaEncadeamentoExplicitoHash(Node* arquivo,
    long int tamanhoDoArquivo) {
    cout << "######################################################################" << endl;
    cout << "#################### Encadeamento explícito com ######################" << endl;
    cout << "######################## Alocação estática ###########################" << endl;
    cout << "######################################################################" << endl;
    cout << "######################## Tabela de registros #########################" << endl;
    cout << "######################################################################" << endl;

    cout << "| " << left << setw(10) << "Reg" << " | " << setw(25) << "Valor" << " | " << setw(25) << "Ponteiro" << " |" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    for(long int i = 0; i < tamanhoDoArquivo; i++) {
        cout << "| " << left << setw(10) << i << " | ";
        if (!arquivo[i].isEstaOcupado()) {
            cout << left << setw(25) << "-" << " | " << setw(25) << "-" << endl;
        }
        else {
            if(arquivo[i].getProximoNode() <= 0) {
                cout << left << setw(25) << arquivo[i].getValorDoNode() << " | " << setw(25) << "Ponteiro Próx: " << "-" << endl;
            } else {
                cout << left << setw(25) << arquivo[i].getValorDoNode() << " | " << setw(25) << "Ponteiro Próx: " << arquivo[i].getProximoNode() << endl;
            }
        }
    }

    cout << "----------------------------------------------------------------------" << endl;
    cout << "######################################################################" << endl;
    cout << "######################################################################" << endl;

    cout << endl << endl;
}

#endif
