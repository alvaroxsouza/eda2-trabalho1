#ifndef HASH_PERFEITO_HPP
#define HASH_PERFEITO_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "../funcao_hash/funcao_hash.hpp"

using namespace std;

namespace hash_perfeito_class {
    class hash_perfeito {
        private:
        /* data */
        public:
            static void insere_perfeito_hash(
                vector<vector<long int>>& nivel_um,
                vector<vector<long int>>& nivel_dois,
                vector<long int>& chaves,
                long int tamanho_arquivo,
                int a, int b,
                long int& total_chaves_inseridas_perfeito,
                long int& quantidade_acessos_total_perfeito
                );
                
            static void saida_perfeito_hash(
                vector<vector<long int>>& nivel_um,
                vector<vector<long int>>& nivel_dois,
                long int tamanho_arquivo
                );
    };
}

#endif