
#ifndef NODE_HPP
#define NODE_HPP

namespace NodeClass {
    class Node {
        private:
            int valorDoNode;
            int proximoNode;
            bool estaOcupado;

        public:
            Node();
            Node(int valorDoNode);
            Node(int valorDoNode, int proximoNode);
            int getValorDoNode();
            void setValorDoNode(int valorDoNode);
            int getProximoNode();
            void setProximoNode(int valorDoNode);
            bool isEstaOcupado();
            void setEstaOcupado(bool estaOcupado);

            ~Node();
    };
}

#endif
