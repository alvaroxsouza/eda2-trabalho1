
#ifndef NODE
#define NODE

namespace NodeClass {
    class Node
    {
    private:
        int valorDoNode;
        int proximoNode;
        bool estaOcupado;

    public:
        Node();
        Node(int valorDoNo);
        Node(int valorDoNo, int proximoNode);
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
