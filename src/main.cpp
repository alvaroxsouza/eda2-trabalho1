#include <iostream>
#include <iomanip>

#include "Node/node.hpp"
#include "Hash/hashEncadeamentoExplicito.hpp"
#include "Hash/hashDouble.hpp"
#include "Hash/hashLinearProbing.hpp"
#include "Hash/hashPerfect.hpp"

using namespace std;
using namespace NodeClass;
using namespace HashEncadeamentoExplicitoClass;
using namespace HashPerfectClass;
using namespace HashDoubleClass;
using namespace HashLinearProbingClass;

int entradatamanhoDoArquivo() {
    int tamanhoDaTabela = 0;
    cin >> tamanhoDaTabela;
    return tamanhoDaTabela;
}

int entradaQuantidadeDeNodesDaEstrutura() {
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

// Função de criação da tabela hash
vector<int> criar_tabela_hash(int quantidade_de_registros){
    int posicao_vazia = -1;
    vector<int> tabela_hash(quantidade_de_registros, posicao_vazia);
    return tabela_hash;
}

void liberaArquivo(Node* arquivo, int tamanhoDaTabela) {
    for(int i = 0; i < tamanhoDaTabela; i++) {
        arquivo[i].~Node();
    }
    delete[] arquivo;
}

int main() {
    int tamanhoDoArquivo = entradatamanhoDoArquivo();
    int qtdEntrada = entradaQuantidadeDeNodesDaEstrutura();

    int posicaoPonteiroControle = tamanhoDoArquivo - 1;

    int quantidadeDeAcessosTotalHEEAE = 0;
    int quantidadeDeAcessosTotalHDouble = 0;
    int quantidadeDeAcessosTotalHLP = 0;
    int quantidadeDeAcessosTotalHPerfect = 0;

    Node *arquivoHEEAE = inicializaArquivo(tamanhoDoArquivo);
    vector<int> arquivoDoubleHashing = criar_tabela_hash(tamanhoDoArquivo);
    vector<int> arquivoPerfectHashing = criar_tabela_hash(tamanhoDoArquivo);
    vector<int> arquivoLinearProbing = criar_tabela_hash(tamanhoDoArquivo);

    for(int i = 0; i < qtdEntrada; i++) {
        int valorDeEntrada;
        cin >> valorDeEntrada;

        HashEncadeamentoExplicito::insercaoNode(arquivoHEEAE, valorDeEntrada, tamanhoDoArquivo,
            posicaoPonteiroControle, quantidadeDeAcessosTotalHEEAE);
        
        HashDouble::insertDoubleHash(arquivoDoubleHashing, valorDeEntrada, tamanhoDoArquivo,
            qtdEntrada, quantidadeDeAcessosTotalHDouble);
        
        HashLinearProbing::insertLinearProbingHash(arquivoLinearProbing, valorDeEntrada,
            tamanhoDoArquivo, qtdEntrada, quantidadeDeAcessosTotalHLP);
        
        // HashPerfect::insertPerfectHash(arquivo, valorDeEntrada, tamanhoDaTabela,
        //     posicaoPonteiroControle, quantidadeDeAcessosTotalHPerfect);
    }

    double mediaDeAcessosHEEAE = double(quantidadeDeAcessosTotalHEEAE) / qtdEntrada;
    double mediaDeAcessosHDouble = double(quantidadeDeAcessosTotalHDouble) / qtdEntrada;
    double mediaDeAcessosHLP = double(quantidadeDeAcessosTotalHLP) / qtdEntrada;
    double mediaDeAcessosHPerfect = double(quantidadeDeAcessosTotalHPerfect) / qtdEntrada;

    cout << "Quantidade de acessos Encadeamento aberto com alocação estática: " 
    << quantidadeDeAcessosTotalHEEAE << endl << fixed << setprecision(1) 
    << "Media de acessos: " << mediaDeAcessosHEEAE << endl;

    cout << "Quantidade de acessos double hashing: " << quantidadeDeAcessosTotalHDouble << endl << fixed 
    << setprecision(1) << "Media de acessos: " << mediaDeAcessosHDouble << endl;

    cout << "Quantidade de acessos linear probing: " << quantidadeDeAcessosTotalHLP << endl << fixed 
    << setprecision(1) << "Media de acessos: " << mediaDeAcessosHLP << endl;

    cout << "Quantidade de acessos perfect hashing: " << quantidadeDeAcessosTotalHPerfect << endl 
    << fixed << setprecision(1) << "Media de acessos: " << mediaDeAcessosHPerfect << endl;
    
}