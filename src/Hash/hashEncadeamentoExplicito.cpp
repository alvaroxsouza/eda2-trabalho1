#ifndef HASH_ENCADEAMENTO_EXPLICITO_CPP
#define HASH_ENCADEAMENTO_EXPLICITO_CPP

#include "hashEncadeamentoExplicito.hpp"

using namespace HashEncadeamentoExplicitoClass;

int funcaoHashingPosicao(int valorDoNode, int tamanhoDoArquivo)
{
    return valorDoNode % tamanhoDoArquivo;
}

int buscaPosicaoInicial(Node *arquivo, int valorNovoNode, int tamanhoDoArquivo)
{
    int posicaoInicial = funcaoHashingPosicao(valorNovoNode, tamanhoDoArquivo);
    return posicaoInicial;
}

/* 
* Encontra o ultimo nó da lista encadeada de forma a apontar para o próximo nó
*/
int encontrarUltimoNoLivreNaListaEncadeada(Node* arquivo, int& posicaoControle,
    int& quantidadeDeAcessosTotalHEEAE, int posicaoInicialDeInsercaoNoArquivo) {

    int posicaoAtualNaLista = posicaoInicialDeInsercaoNoArquivo;
    while (arquivo[posicaoAtualNaLista].getProximoNode() != -1) {
        posicaoAtualNaLista = arquivo[posicaoAtualNaLista].getProximoNode();
        quantidadeDeAcessosTotalHEEAE++;
    }
    return posicaoAtualNaLista;
}

/* 
* Encontra o primeiro nó livre no arquivo, de cima para baixo, verificando se a posição está ocupada
* para guardar a posição que deve marcar o próxima posição que será inserida caso haja colisão
*/
void encontrarPrimeiroNodeLivre(Node* arquivo, int& posicaoControle, int& quantidadeDeAcessosTotalHEEAE) {
    while (posicaoControle >= 0 && arquivo[posicaoControle].isEstaOcupado()) {
        posicaoControle--;
        quantidadeDeAcessosTotalHEEAE++;
    }
}

void HashEncadeamentoExplicito::insercaoNode(Node* arquivo, int valorNovoNode,
                                              int tamanhoDoArquivo,
                                              int& posicaoControle,
                                              int& quantidadeDeAcessosTotalHEEAE) {
    int posicaoInicialDeInsercaoNoArquivo = buscaPosicaoInicial(arquivo, valorNovoNode, tamanhoDoArquivo);

    if (!arquivo[posicaoInicialDeInsercaoNoArquivo].isEstaOcupado())
    {
        quantidadeDeAcessosTotalHEEAE++;
        arquivo[posicaoInicialDeInsercaoNoArquivo].setValorDoNode(valorNovoNode);
        arquivo[posicaoInicialDeInsercaoNoArquivo].setEstaOcupado(true);
    } else {
        int posicaoAtualNaLista = encontrarUltimoNoLivreNaListaEncadeada(arquivo, posicaoControle,
                                quantidadeDeAcessosTotalHEEAE, posicaoInicialDeInsercaoNoArquivo);
    
        encontrarPrimeiroNodeLivre(arquivo, posicaoControle, quantidadeDeAcessosTotalHEEAE);

        if (posicaoControle >= 0) {
            arquivo[posicaoAtualNaLista].setProximoNode(posicaoControle);
            arquivo[posicaoControle].setValorDoNode(valorNovoNode);
            arquivo[posicaoControle].setEstaOcupado(true);
            quantidadeDeAcessosTotalHEEAE++;
        }
    }
}

#endif
