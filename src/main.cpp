#include <iostream>
#include "Node/node.hpp"
#include "Hash/hashEncadeamentoExplicito.hpp"

using namespace std;
using namespace NodeClass;
using namespace HashEncadeamentoExplicitoClass;

int entradaTamanhoDaTabela() {
    int tamanhoDaTabela = 0;
    cin >> tamanhoDaTabela;
    return tamanhoDaTabela;
}

int entradaDosValoresDosNosDaEstrutura() {
    int valorDoNode;
    cin >> valorDoNode;
    return valorDoNode;
}

Node* inicializaArquivo(int tamanhoDaTabela) {
    Node* arquivo = new Node[tamanhoDaTabela];
    for(int i = 0; i < tamanhoDaTabela; i++) {
        Node* node = new Node();
        arquivo[i] = *node;

        // for(int i = 0; i < tamanhoDaTabela; i++) {
        //     cout << arquivo[i].getValorDoNode() << endl;
        //     cout << arquivo[i].getProximoNode() << endl;
        //     cout << arquivo[i].isEstaOcupado() << endl;
        // }
    }
    return arquivo;
}

int main() {
    // for(int i = 0; i < 100; i++) {
    //     int posicaoAtual = i % (11);

    //     cout << i << " " << posicaoAtual << endl;
    // }

    int tamanhoDaTabela = entradaTamanhoDaTabela();

    int posicaoPonteiroControle = tamanhoDaTabela - 1;

    Node *arquivo = inicializaArquivo(tamanhoDaTabela);

    int qtdEntrada = entradaTamanhoDaTabela();

    for(int i = 0; i < qtdEntrada; i++) {
        int valorNewNode;
        cin >> valorNewNode;
        HashEncadeamentoExplicito::insercaoNode(arquivo, valorNewNode, tamanhoDaTabela, &posicaoPonteiroControle);
    }
    
    for(int i = 0; i < tamanhoDaTabela; i++) {
        cout << "Posicao " << i << ": " << arquivo[i].getValorDoNode()
            << " Ponteiro " << i << ": " << arquivo[i].getProximoNode() << endl;
    }
}