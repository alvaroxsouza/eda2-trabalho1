#ifndef NODE_CPP
#define NODE_CPP

#include "node.hpp"

using namespace NodeClass;

Node::Node() {
    this->valorDoNode = 0;
    this->proximoNode = -1;
    this->estaOcupado = false;
}

Node::Node(int valorDoNode) {
    this->valorDoNode = valorDoNode;
    this->proximoNode = -1;
    this->estaOcupado = true;
}

Node::Node(int valorDoNode, int proximoNode) {
    this->valorDoNode = valorDoNode;
    this->proximoNode = proximoNode;
    this->estaOcupado = true;
}

Node::~Node() {}

int Node::getValorDoNode() {
    return this->valorDoNode;
}

void Node::setValorDoNode(int valorDoNode) {
    this->valorDoNode = valorDoNode;
}

int Node::getProximoNode() {
    return this->proximoNode;
}

void Node::setProximoNode(int proximoNode) {
    this->proximoNode = proximoNode;
}

bool Node::isEstaOcupado() {
    return this->estaOcupado;
}

void Node::setEstaOcupado(bool estaOcupado) {
    this->estaOcupado = estaOcupado;
}

#endif
