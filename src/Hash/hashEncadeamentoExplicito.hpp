#ifndef HASH_ENCADEAMENTO_EXPLICITO_HPP
#define HASH_ENCADEAMENTO_EXPLICITO_HPP

#include "../Node/node.hpp"

using namespace std;
using namespace NodeClass;

namespace HashEncadeamentoExplicitoClass {
    class HashEncadeamentoExplicito
    {
        private:
            
        public:
            static void insercaoNode(Node* arquivo, int valorNovoNode,
                int tamanhoDoArquivo, int &posicaoControle, int &quantidadeDeAcessosTotalHEEAE);
    };
}

#endif