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

Node::~Node() {
    delete this;
}

int Node::getValorDoNode() {
    return this->valorDoNode;
}

void Node::setValorDoNode(int valorDoNo) {
    this->valorDoNode = valorDoNo;
}

int Node::getProximoNode() {
    return this->valorDoNode;
}

void Node::setProximoNode(int valorDoNode) {
    this->valorDoNode = valorDoNode;
}

bool Node::isEstaOcupado() {
    return this->estaOcupado;
}

void Node::setEstaOcupado(bool estaOcupado) {
    this->estaOcupado = estaOcupado;
}

