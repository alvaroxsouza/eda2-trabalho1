#ifndef HASH_DOUBLE_HPP
#define HASH_DOUBLE_HPP

#include <cmath>
#include <vector>

using namespace std;

namespace HashDoubleClass {
    class HashDouble {
        private:
        
        public:
            static void insertDoubleHash(
                vector<long int>& tabela_hash,
                long int chave,
                long int quantidade_de_registros,
                long int& total_chaves_inseridas,
                long int& total_acessos);
    };
}

#endif
