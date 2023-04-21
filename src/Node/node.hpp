
#ifndef NODE
#define NODE

namespace NodeClass {
    class Node
    {
    private:
        int valorDoNo;
        int proximoElemento;

    public:
        Node();
        Node(int valorDoNo);
        Node(int valorDoNo, int proximoElemento);
        int getValorDoNode();
        void setValorDoNode(int valorDoNo);

        ~Node();
    };
}

#endif
