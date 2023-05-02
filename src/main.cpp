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

vector<long int> criar_tabela_hash(long int quantidade_de_registros){
    long int posicao_vazia = -1;
    vector<long int> tabela_hash(quantidade_de_registros, posicao_vazia);
    return tabela_hash;
}

vector<vector<long int>> criar_tabela_nivel_um(long int quantidade_de_registros) {
    vector<vector<long int>> tabela_nivel_um(quantidade_de_registros);
    return tabela_nivel_um;
}

vector<vector<long int>> criar_tabela_nivel_dois(long int quantidade_de_registros) {
    vector<vector<long int>> tabela_nivel_dois(quantidade_de_registros);
    return tabela_nivel_dois;
}

void gerar_variaveis_aleatorias(int &a, int &b) {
    srand(time(NULL));
    a = rand() % 101;
    b = rand() % 101;
}

void liberaArquivo(Node* arquivo, long int tamanhoDaTabela) {
    for(long int i = 0; i < tamanhoDaTabela; i++) {
        arquivo[i].~Node();
    }
    delete[] arquivo;
}

void saidaInformacoesArquivo(long int tamanhoDoArquivo,long int qtdEntrada) {
    cout << "Tamanho do arquivo: " << tamanhoDoArquivo << endl;
    cout << "Quantidade de chaves: " << qtdEntrada << endl;
}

void estatisticasHEEAE(long int quantidadeDeAcessosTotalHEEAE, long int mediaDeAcessosHEEAE) {
    cout << "Quantidade de acessos Encadeamento aberto com alocação estática: " 
    << quantidadeDeAcessosTotalHEEAE << endl << fixed << setprecision(1) 
    << "Media de acessos: " << mediaDeAcessosHEEAE << endl;
}

void estatisticasHDouble(long int quantidadeDeAcessosTotalHDouble,long int mediaDeAcessosHDouble) {
    cout << "Quantidade de acessos double hashing: " << quantidadeDeAcessosTotalHDouble << endl;
    cout << fixed << setprecision(1) << "Media de acessos: " << mediaDeAcessosHDouble << endl;
}

void estatisticasHLinearProbing(long int quantidadeDeAcessosTotalHLP,long int mediaDeAcessosHLP) {
    cout << "Quantidade de acessos linear probing: " << quantidadeDeAcessosTotalHLP << endl; 
    cout << fixed << setprecision(1) << "Media de acessos: " << mediaDeAcessosHLP << endl;
}

void estatisticasHPerfect(long int quantidadeDeAcessosTotalHPerfect,long int mediaDeAcessosHPerfect) {
    cout << "Quantidade de acessos perfect hashing: " << quantidadeDeAcessosTotalHPerfect << endl;
    cout << fixed << setprecision(1) << "Media de acessos: " << mediaDeAcessosHPerfect << endl;
}

int main() {
    long int tamanhoDoArquivo = entradatamanhoDoArquivo();
    long int qtdEntrada = entradaQuantidadeDeNodesDaEstrutura();

    long int posicaoPonteiroControle = tamanhoDoArquivo - 1;

    long int quantidadeDeAcessosTotalHEEAE = 0;
    long int quantidadeDeAcessosTotalHDouble = 0;
    long int quantidadeDeAcessosTotalHLP = 0;
    long int quantidadeDeAcessosTotalHPerfect = 0;
    
    long int totalDeChavesInseridasHEEAE = 0;
    long int totalDeChavesInseridasHDouble = 0;
    long int totalDeChavesInseridasHLP = 0;
    long int totalDeChavesInseridasHPerfect = 0;

    Node *arquivoHEEAE = inicializaArquivo(tamanhoDoArquivo);
    vector<long int> arquivoDoubleHashing = criar_tabela_hash(tamanhoDoArquivo);
    vector<long int> arquivoPerfectHashing = criar_tabela_hash(tamanhoDoArquivo);
    vector<long int> arquivoLinearProbing = criar_tabela_hash(tamanhoDoArquivo);

    vector<long int> chaves;

    for(long int i = 0; i < qtdEntrada; i++) {
        long int valorDeEntrada;
        cin >> valorDeEntrada;

        HashEncadeamentoExplicito::insercaoNode(arquivoHEEAE, valorDeEntrada, tamanhoDoArquivo,
            posicaoPonteiroControle, totalDeChavesInseridasHEEAE, quantidadeDeAcessosTotalHEEAE);
        
        HashDouble::insertDoubleHash(arquivoDoubleHashing, valorDeEntrada, tamanhoDoArquivo,
            totalDeChavesInseridasHDouble, quantidadeDeAcessosTotalHDouble);
        
        HashLinearProbing::insertLinearProbingHash(arquivoLinearProbing, valorDeEntrada,
            qtdEntrada, totalDeChavesInseridasHLP, quantidadeDeAcessosTotalHLP);

        chaves.push_back(valorDeEntrada);
    }

    int a, b;
    gerar_variaveis_aleatorias(a, b);

    vector<vector<long int>> nivel_um = criar_tabela_nivel_um(qtdEntrada);
    vector<vector<long int>> nivel_dois = criar_tabela_nivel_dois(qtdEntrada);

    HashPerfect::insertPerfectHash(nivel_um, nivel_dois, chaves, qtdEntrada, a, b,
        quantidadeDeAcessosTotalHPerfect, totalDeChavesInseridasHPerfect);

    double mediaDeAcessosHEEAE = double(quantidadeDeAcessosTotalHEEAE) / totalDeChavesInseridasHEEAE;
    double mediaDeAcessosHDouble = double(quantidadeDeAcessosTotalHDouble) / totalDeChavesInseridasHDouble;
    double mediaDeAcessosHLP = double(quantidadeDeAcessosTotalHLP) / totalDeChavesInseridasHLP;
    double mediaDeAcessosHPerfect = double(quantidadeDeAcessosTotalHPerfect) / totalDeChavesInseridasHPerfect;

    HashDouble::saidaDoubleHash(arquivoDoubleHashing, tamanhoDoArquivo);
    HashLinearProbing::saidaLinearProbingHash(arquivoLinearProbing, tamanhoDoArquivo);
    HashPerfect::saidaPefectHash(nivel_um, nivel_dois, tamanhoDoArquivo, a, b);

    saidaInformacoesArquivo(tamanhoDoArquivo, qtdEntrada);
    estatisticasHEEAE(quantidadeDeAcessosTotalHEEAE, mediaDeAcessosHEEAE);
    estatisticasHDouble(quantidadeDeAcessosTotalHDouble,mediaDeAcessosHDouble);
    estatisticasHLinearProbing(quantidadeDeAcessosTotalHLP, mediaDeAcessosHLP);
    estatisticasHPerfect(quantidadeDeAcessosTotalHPerfect, mediaDeAcessosHPerfect);
}
