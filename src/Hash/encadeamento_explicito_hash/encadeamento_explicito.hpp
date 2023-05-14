#ifndef HASH_ENCADEAMENTO_EXPLICITO_HPP
#define HASH_ENCADEAMENTO_EXPLICITO_HPP

#include "../../node/node.hpp"
#include "../funcao_hash/funcao_hash.hpp"

using namespace std;
using namespace node_class;
using namespace hash_funcao_class;

namespace hash_encadeamento_explicito_class {
    class hash_encadeamento_explicito
    {
        private:
            
        public:
            static void insercao_encadeamento_explicito(
                node* arquivo,
                long int valor_node,
                long int tamanho_arquivo,
                long int &posicaoControle,
                long int& total_chaves_inseridas_HEEAE,
                long int& quantidade_acessos_total_HEEAE
                );

            static void saida_encadeamento_explicito(
                node* arquivo,
                long int tamanho_arquivo
                );
    };
}

#endif