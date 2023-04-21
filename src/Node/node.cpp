#include "node.hpp"

using namespace NodeClass;

Node::Node() {
    this->valorDoNo = 0;
    this->proximoElemento = -1;
}

Node::Node(int valorDoNo) {
    this->valorDoNo = valorDoNo;
    this->proximoElemento = -1;
}

Node::Node(int valorDoNo, int proximoElemento) {
    this->valorDoNo = valorDoNo;
    this->proximoElemento = proximoElemento;
}

Node::~Node() {
    delete this;
}

int Node::getValorDoNode() {
    return this->valorDoNo;
}

void Node::setValorDoNode(int valorDoNo) {
    this->valorDoNo = valorDoNo;
}
