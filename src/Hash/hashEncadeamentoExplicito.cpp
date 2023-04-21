#ifndef HASH_ENCADEAMENTO_EXPLICITO_CPP
#define HASH_ENCADEAMENTO_EXPLICITO_CPP

#include "hashEncadeamentoExplicito.hpp"
#include <iostream>

using namespace std;

using namespace HashEncadeamentoExplicitoClass;

int funcaoHashingPosicao(int valorDoNode, int tamanhoDoArquivo) {
    return valorDoNode % tamanhoDoArquivo;
}

int buscaPosicaoInicial(Node* arquivo, int valorNovoNode, int tamanhoDoArquivo) {
    int posicaoInicial = funcaoHashingPosicao(valorNovoNode, tamanhoDoArquivo);
    return posicaoInicial;
}

void HashEncadeamentoExplicito::insercaoNode(Node* arquivo, int valorNovoNode, int tamanhoDoArquivo, int *posicaoControle) {

    int posicaoDeInsercaoNoArquivo = buscaPosicaoInicial(arquivo, valorNovoNode, tamanhoDoArquivo);

    if(!arquivo[posicaoDeInsercaoNoArquivo].isEstaOcupado()) {
        arquivo[posicaoDeInsercaoNoArquivo].setValorDoNode(valorNovoNode);
        arquivo[posicaoDeInsercaoNoArquivo].setEstaOcupado(true);
    } else {
        int posicaoAtualNaLista = posicaoDeInsercaoNoArquivo;

        // Verificar na posicao atual da lista se o próximo nó está livre, para colocar a
        // posicao do novo nó para ligar a lista com o nó que está sendo inserido
        while(arquivo[posicaoAtualNaLista].getProximoNode() != -1) {
            posicaoAtualNaLista = arquivo[posicaoAtualNaLista].getProximoNode();
        }

        while (*posicaoControle >= 0) {
            if(arquivo[*posicaoControle].isEstaOcupado()) {
                *posicaoControle -= 1;
            } else {
                arquivo[posicaoAtualNaLista].setProximoNode(*posicaoControle);
                arquivo[*posicaoControle].setValorDoNode(valorNovoNode);
                arquivo[*posicaoControle].setEstaOcupado(true);
                return;
            }
        }
    }

}

#endif
