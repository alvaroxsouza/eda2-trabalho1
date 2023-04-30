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

long int entradatamanhoDoArquivo() {
    long int tamanhoDaTabela = 0;
    cin >> tamanhoDaTabela;
    return tamanhoDaTabela;
}

long int entradaQuantidadeDeNodesDaEstrutura() {
    long int valorDoNode;
    cin >> valorDoNode;
    return valorDoNode;
}

Node* inicializaArquivo(long int tamanhoDaTabela) {
    Node* arquivo = new Node[tamanhoDaTabela];
    for(long int i = 0; i < tamanhoDaTabela; i++) {
        new (&arquivo[i]) Node();
    }
    return arquivo;
}

// Função de criação da tabela hash
vector<long int> criar_tabela_hash(long int quantidade_de_registros){
    long int posicao_vazia = -1;
    vector<long int> tabela_hash(quantidade_de_registros, posicao_vazia);
    return tabela_hash;
}

void liberaArquivo(Node* arquivo, long int tamanhoDaTabela) {
    for(long int i = 0; i < tamanhoDaTabela; i++) {
        arquivo[i].~Node();
    }
    delete[] arquivo;
}

int main() {
    long int tamanhoDoArquivo = entradatamanhoDoArquivo();
    long int qtdEntrada = entradaQuantidadeDeNodesDaEstrutura();

    long int posicaoPonteiroControle = tamanhoDoArquivo - 1;

    long int quantidadeDeAcessosTotalHEEAE = 0;
    long int quantidadeDeAcessosTotalHDouble = 0;
    long int quantidadeDeAcessosTotalHLP = 0;
    long int quantidadeDeAcessosTotalHPerfect = 0;
    
    long int totalDeChavesInseridasHDouble = 0;
    long int totalDeChavesInseridasHLP = 0;
    long int totalDeChavesInseridasHPerfect = 0;

    Node *arquivoHEEAE = inicializaArquivo(tamanhoDoArquivo);
    vector<long int> arquivoDoubleHashing = criar_tabela_hash(tamanhoDoArquivo);
    vector<long int> arquivoPerfectHashing = criar_tabela_hash(tamanhoDoArquivo);
    vector<long int> arquivoLinearProbing = criar_tabela_hash(tamanhoDoArquivo);

    for(long int i = 0; i < qtdEntrada; i++) {
        long int valorDeEntrada;
        cin >> valorDeEntrada;

        HashEncadeamentoExplicito::insercaoNode(arquivoHEEAE, valorDeEntrada, tamanhoDoArquivo,
            posicaoPonteiroControle, quantidadeDeAcessosTotalHEEAE);
        
        HashDouble::insertDoubleHash(arquivoDoubleHashing, valorDeEntrada, tamanhoDoArquivo,
            totalDeChavesInseridasHDouble, quantidadeDeAcessosTotalHDouble);
        
        HashLinearProbing::insertLinearProbingHash(arquivoLinearProbing, valorDeEntrada,
            qtdEntrada, totalDeChavesInseridasHLP, quantidadeDeAcessosTotalHLP);
        
        // HashPerfect::insertPerfectHash(arquivo, valorDeEntrada, tamanhoDaTabela,
        //     posicaoPonteiroControle, quantidadeDeAcessosTotalHPerfect);
    }

    double mediaDeAcessosHEEAE = double(quantidadeDeAcessosTotalHEEAE) / qtdEntrada;
    double mediaDeAcessosHDouble = double(quantidadeDeAcessosTotalHDouble) / totalDeChavesInseridasHDouble;
    double mediaDeAcessosHLP = double(quantidadeDeAcessosTotalHLP) / totalDeChavesInseridasHLP;
    double mediaDeAcessosHPerfect = double(quantidadeDeAcessosTotalHPerfect) / totalDeChavesInseridasHPerfect;

    cout << "Quantidade de acessos Encadeamento aberto com alocação estática: " 
    << quantidadeDeAcessosTotalHEEAE << endl << fixed << setprecision(1) 
    << "Media de acessos: " << mediaDeAcessosHEEAE << endl;

    cout << "Quantidade de acessos double hashing: " << quantidadeDeAcessosTotalHDouble << endl;
    cout << fixed << setprecision(1) << "Media de acessos: " << mediaDeAcessosHDouble << endl;

    cout << "Quantidade de acessos linear probing: " << quantidadeDeAcessosTotalHLP << endl; 
    cout << fixed << setprecision(1) << "Media de acessos: " << mediaDeAcessosHLP << endl;

    cout << "Quantidade de acessos perfect hashing: " << quantidadeDeAcessosTotalHPerfect << endl;
    cout << fixed << setprecision(1) << "Media de acessos: " << mediaDeAcessosHPerfect << endl;
    
}