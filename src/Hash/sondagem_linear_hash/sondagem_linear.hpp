#ifndef HASH_SONDAGEM_LINEAR_HPP
#define HASH_SONDAGEM_LINEAR_HPP

#include <vector>

using namespace std;

namespace sondagem_linear_hash_class {
    class sondagem_linear_hash {
        
        private:
        
        public:
            static void insere_sondagem_linear(vector<long int>& tabela_hash,
                long int chave,
                long int tamanho_arquivo,
                long int& total_chaves_inseridas_sondagem,
                long int& quantidade_acessos_total_sondagem_linear);
                
            static void saida_sondagem_linear(
                vector<long int>& tabela_hash,
                long int tamanho_arquivo
                );
        
    };
}

#endif