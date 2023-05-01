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
            static void insercaoNode(Node* arquivo, long int valorNovoNode,
                long int tamanhoDoArquivo, long int &posicaoControle,
                long int& totalDeChavesInseridasHEEAE,
                long int& quantidadeDeAcessosTotalHEEAE);
    };
}

#endif