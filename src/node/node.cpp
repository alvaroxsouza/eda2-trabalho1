#ifndef NODE_CPP
#define NODE_CPP

#include "node.hpp"

using namespace node_class;

/* 
* Arquivo de implementação do Node, como um registro, usado no método de 
* Hash com Encademento Explícito com Alocação Estática
*/

node::node() {
    this->valor_node = 0;
    this->proximo_node = -1;
    this->estaOcupado = false;
}

node::node(int valor_node) {
    this->valor_node = valor_node;
    this->proximo_node = -1;
    this->estaOcupado = true;
}

node::node(int valor_node, int proximo_node) {
    this->valor_node = valor_node;
    this->proximo_node = proximo_node;
    this->estaOcupado = true;
}

node::~node() {}

int node::get_valor_node() {
    return this->valor_node;
}

void node::set_valor_node(int valor_node) {
    this->valor_node = valor_node;
}

int node::get_proximo_node() {
    return this->proximo_node;
}

void node::set_proximo_node(int proximo_node) {
    this->proximo_node = proximo_node;
}

bool node::is_esta_ocupado() {
    return this->estaOcupado;
}

void node::set_esta_ocupado(bool estaOcupado) {
    this->estaOcupado = estaOcupado;
}

#endif
