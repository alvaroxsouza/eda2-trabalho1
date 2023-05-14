#ifndef HASH_ENCADEAMENTO_EXPLICITO_CPP
#define HASH_ENCADEAMENTO_EXPLICITO_CPP

#include "encadeamento_explicito.hpp"

using namespace hash_encadeamento_explicito_class;

int funcao_hash_h1(long int valor_node,
    long int tamanho_arquivo) {
    return valor_node % tamanho_arquivo;
}

int busca_posicao_inicial(node *arquivo,
    long int valor_node,
    long int tamanho_arquivo) {
    int posicao_inicial = funcao_hash_h1(valor_node, tamanho_arquivo);
    return posicao_inicial;
}

/* 
* Encontra o ultimo nó da lista encadeada de forma a apontar para o próximo nó
*/
int encontrar_ultimo_node_livre_lista_encadeada(node* arquivo,
    long int& posicao_ponteiro_encadeamento_explicito,
    long int& quantidade_acessos_total_HEEAE,
    long int posicao_inicial_insercao_arquivo) {

    long int posicao_atual_tabela = posicao_inicial_insercao_arquivo;
    while (arquivo[posicao_atual_tabela].get_proximo_node() != -1) {
        posicao_atual_tabela = arquivo[posicao_atual_tabela].get_proximo_node();
        quantidade_acessos_total_HEEAE++;
    }
    return posicao_atual_tabela;
}

/* 
* Encontra o primeiro nó livre no arquivo, de cima para baixo, verificando se a posição está ocupada
* para guardar a posição que deve marcar o próxima posição que será inserida caso haja colisão
*/
void encontrar_primeiro_registro_livre(node* arquivo, 
    long int& posicao_ponteiro_encadeamento_explicito,
    long int& quantidade_acessos_total_HEEAE) {
    while (posicao_ponteiro_encadeamento_explicito >= 0 
        && arquivo[posicao_ponteiro_encadeamento_explicito].is_esta_ocupado()) {
        posicao_ponteiro_encadeamento_explicito--;
        quantidade_acessos_total_HEEAE++;
    }
}

void hash_encadeamento_explicito::insercao_encadeamento_explicito(node* arquivo,
    long int valor_node,
    long int tamanho_arquivo,
    long int& posicao_ponteiro_encadeamento_explicito,
    long int& total_chaves_inseridas_HEEAE, 
    long int& quantidade_acessos_total_HEEAE) {
    long int posicao_inicial_insercao_arquivo =
        busca_posicao_inicial(arquivo, valor_node, tamanho_arquivo);

    if (!arquivo[posicao_inicial_insercao_arquivo].is_esta_ocupado())
    {
        arquivo[posicao_inicial_insercao_arquivo].set_valor_node(valor_node);
        arquivo[posicao_inicial_insercao_arquivo].set_esta_ocupado(true);
        quantidade_acessos_total_HEEAE++;
        total_chaves_inseridas_HEEAE++;
    } else {
        long int posicao_atual_tabela = 
            encontrar_ultimo_node_livre_lista_encadeada(arquivo,
                posicao_ponteiro_encadeamento_explicito,
                quantidade_acessos_total_HEEAE,
                posicao_inicial_insercao_arquivo);
    
        encontrar_primeiro_registro_livre(arquivo, 
            posicao_ponteiro_encadeamento_explicito,
            quantidade_acessos_total_HEEAE
            );

        if (posicao_ponteiro_encadeamento_explicito >= 0) {
            arquivo[posicao_atual_tabela].set_proximo_node(posicao_ponteiro_encadeamento_explicito);
            arquivo[posicao_ponteiro_encadeamento_explicito].set_valor_node(valor_node);
            arquivo[posicao_ponteiro_encadeamento_explicito].set_esta_ocupado(true);
            total_chaves_inseridas_HEEAE++;
            quantidade_acessos_total_HEEAE++;
        }
    }
}

#endif
