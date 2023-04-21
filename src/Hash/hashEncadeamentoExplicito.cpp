#include "hashEncadeamentoExplicito.hpp"

using namespace HashEncadeamentoExplicitoClass;

int funcaoHashingPosicao(int valorDoNode, int tamanhoDoArquivo) {
    return valorDoNode % tamanhoDoArquivo;
}

int buscaPosicao(Node* arquivo, Node* newNode, int tamanhoDoArquivo) {
    int posicao = -1;
    int posicaoInicial = funcaoHashingPosicao(newNode->getValorDoNode(), tamanhoDoArquivo);
    return posicao;
}

void insercaoNode(Node* arquivo, Node* newNode, int tamanhoDoArquivo, int posicaoControle) {

    int posicaoDeInsercaoNoArquivo = buscaPosicao(arquivo, newNode, tamanhoDoArquivo);

    if(!arquivo[posicaoDeInsercaoNoArquivo].isEstaOcupado()) {
        arquivo[posicaoDeInsercaoNoArquivo].setValorDoNode(newNode->getValorDoNode());
        arquivo[posicaoDeInsercaoNoArquivo].setProximoNode(-1);
        arquivo[posicaoDeInsercaoNoArquivo].setEstaOcupado(true);
    } else {
        int guardaPosicaoInicial = posicaoDeInsercaoNoArquivo;
        do  {
            if(!arquivo[posicaoControle].isEstaOcupado()) {
                arquivo[posicaoControle].setValorDoNode(newNode->getValorDoNode());
                arquivo[posicaoControle].setProximoNode(-1);
                arquivo[posicaoControle].setEstaOcupado(true);
                posicaoControle--;
            } else {
                posicaoControle--;
            }
        } while(guardaPosicaoInicial != posicaoControle);
        
    }

}
