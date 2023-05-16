
#ifndef NODE_HPP
#define NODE_HPP

/* 
* Arquivo de declaração do Node, como um registro, usado no método de 
* Hash com Encademento Explícito com Alocação Estática
*/

namespace node_class {
    class node {
        private:
            int valor_node;
            int proximo_node;
            bool estaOcupado;

        public:
            node();
            node(int valor_node);
            node(int valor_node, int proximo_node);
            int get_valor_node();
            void set_valor_node(int valor_node);
            int get_proximo_node();
            void set_proximo_node(int valor_node);
            bool is_esta_ocupado();
            void set_esta_ocupado(bool estaOcupado);
            ~node();
    };
}

#endif
