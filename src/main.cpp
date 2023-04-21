#include <iostream>
#include "Node/node.hpp"

using namespace std;
using namespace NodeClass;

int entradaTamanhoDaTabela() {
    int tamanhoDaTabela = 0;
    cin >> tamanhoDaTabela;
    return tamanhoDaTabela;
}

int entradaDosValoresDosNosDaEstrutura() {
    int valorDoNo;
    cin >> valorDoNo;
    return valorDoNo;
}

Node* inicializaArquivo(int tamanhoDaTabela) {
    Node* arquivo = new Node[tamanhoDaTabela];
    for(int i = 0; i < tamanhoDaTabela; i++) {
        int valorDoNo = entradaDosValoresDosNosDaEstrutura();
        Node* node = new Node();
        node->setValorDoNode(valorDoNo);
        arquivo[i] = *node;
        // delete node;
    }
    return arquivo;
}

int main() {
    // for(int i = 0; i < 100; i++) {
    //     int posicaoAtual = i % (11);

    //     cout << i << " " << posicaoAtual << endl;
    // }

    int tamanhoDaTabela = entradaTamanhoDaTabela();

    Node *arquivo = inicializaArquivo(tamanhoDaTabela);
    
    for(int i = 0; i < tamanhoDaTabela; i++) {
        cout << arquivo[i].getValorDoNode() << endl;
    }
}