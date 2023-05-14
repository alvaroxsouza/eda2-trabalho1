#ifndef HASH_ENCADEAMENTO_EXPLICITO_SAIDA_CPP
#define HASH_ENCADEAMENTO_EXPLICITO_SAIDA_CPP

#include <iostream>
#include <iomanip>
#include "encadeamento_explicito.hpp"

using namespace std;
using namespace hash_encadeamento_explicito_class;

void hash_encadeamento_explicito::saida_encadeamento_explicito(node* arquivo,
    long int tamanho_arquivo) {
    cout << "######################################################################" << endl;
    cout << "#################### Encadeamento explícito com ######################" << endl;
    cout << "######################## Alocação estática ###########################" << endl;
    cout << "######################################################################" << endl;
    cout << "######################## Tabela de registros #########################" << endl;
    cout << "######################################################################" << endl;

    cout << "| " << left << setw(10) << "Reg" << " | " << setw(25) << "Valor" << " | " << setw(25) << "Ponteiro" << " |" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    for(long int i = 0; i < tamanho_arquivo; i++) {
        cout << "| " << left << setw(10) << i << " | ";
        if (!arquivo[i].is_esta_ocupado()) {
            cout << left << setw(25) << "-" << " | " << setw(25) << "-" << endl;
        }
        else {
            if(arquivo[i].get_proximo_node() <= 0) {
                cout << left << setw(25) << arquivo[i].get_valor_node() << " | " << setw(25) << "Ponteiro Próx: " << "-" << endl;
            } else {
                cout << left << setw(25) << arquivo[i].get_valor_node() << " | " << setw(25) << "Ponteiro Próx: " << arquivo[i].get_proximo_node() << endl;
            }
        }
    }

    cout << "----------------------------------------------------------------------" << endl;
    cout << "######################################################################" << endl;
    cout << "######################################################################" << endl;

    cout << endl << endl;
}

#endif
