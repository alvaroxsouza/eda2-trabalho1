#include <iostream>
#include <iomanip>

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
        new (&arquivo[i]) Node();
    }
    return arquivo;
}

void liberaArquivo(Node* arquivo, int tamanhoDaTabela) {
    for(int i = 0; i < tamanhoDaTabela; i++) {
        arquivo[i].~Node();
    }
    delete[] arquivo;
}

int main() {
    int tamanhoDaTabela = entradaTamanhoDaTabela();
    int posicaoPonteiroControle = tamanhoDaTabela - 1;

    int quantidadeDeAcessosTotalHEEAE = 0;

    Node *arquivo = inicializaArquivo(tamanhoDaTabela);

    int qtdEntrada = entradaDosValoresDosNosDaEstrutura();

    for(int i = 0; i < qtdEntrada; i++) {
        int valorNewNode;
        cin >> valorNewNode;
        HashEncadeamentoExplicito::insercaoNode(arquivo, valorNewNode, tamanhoDaTabela, posicaoPonteiroControle, quantidadeDeAcessosTotalHEEAE);
    }
    
    for(int i = 0; i < tamanhoDaTabela; i++) {
        cout << "Posicao " << i << ": " << arquivo[i].getValorDoNode()
            << " Ponteiro " << i << ": " << arquivo[i].getProximoNode() << endl;
    }

    double mediaDeAcessos = double(quantidadeDeAcessosTotalHEEAE) / qtdEntrada;

    cout << "Quantidade de acessos: " << quantidadeDeAcessosTotalHEEAE << endl;
    cout << fixed << setprecision(1) << "Media de acessos: " << mediaDeAcessos << endl;

    liberaArquivo(arquivo, tamanhoDaTabela);

}