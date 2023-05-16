#ifndef HASH_ENCADEAMENTO_EXPLICITO_SAIDA_CPP
#define HASH_ENCADEAMENTO_EXPLICITO_SAIDA_CPP

#include <iostream>
#include <iomanip>
#include "encadeamento_explicito.hpp"

using namespace std;
using namespace hash_encadeamento_explicito_class;

/**
 * Função para exibir a saída do encadeamento explícito com alocação estática.
 *
 * A função recebe um ponteiro para um array de nós (arquivo) e o tamanho da tabela hash.
 * 
 * Parâmetros:
 *   - arquivo: ponteiro para o array de nós que representa a tabela hash.
 *   - tamanho_arquivo: tamanho do arquivo/tabela hash.
 *
 * A função imprime na saída padrão a tabela de registros do encadeamento explícito com alocação estática.
 * A tabela é formatada com colunas para o índice do registro, o valor armazenado no nó e o ponteiro para o próximo nó.
 * Caso um registro não esteja ocupado, os campos de valor e ponteiro serão exibidos como "-" para indicar vazio.
 * Caso o ponteiro para o próximo nó seja menor ou igual a zero, será exibido "-" para indicar que não há próximo nó.
 *
 * A formatação da tabela inclui uma linha de cabeçalho, separadores de coluna e linhas para cada registro.
 * Após exibir a tabela, são apresentadas linhas de separação e uma mensagem de finalização.
 */
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
