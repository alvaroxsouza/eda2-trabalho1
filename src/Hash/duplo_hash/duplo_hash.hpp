#ifndef HASH_DUPLO_HPP
#define HASH_DUPLO_HPP

#include <cmath>
#include <vector>
#include "../funcao_hash/funcao_hash.hpp"

using namespace std;
using namespace hash_funcao_class;

namespace hash_duplo_class {
    class hash_duplo {
        private:
        
        public:
            static void insere_duplo_hash(
                vector<long int>& tabela_hash,
                long int chave,
                long int tamanho_arquivo,
                long int& total_chaves_inseridas_duplo,
                long int& quantidade_acessos_total_duplo
                );
                
            static void saida_duplo_hash(
                vector<long int>& tabela_hash,
                long int tamanho_arquivo
                );
    };
}

#endif
