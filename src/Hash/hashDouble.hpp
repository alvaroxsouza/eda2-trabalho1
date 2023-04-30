#ifndef HASH_DOUBLE_HPP
#define HASH_DOUBLE_HPP

#include <cmath>
#include <vector>

using namespace std;

namespace HashDoubleClass {
    class HashDouble {
        private:
        
        public:
            static void insertDoubleHash(vector<int>& tabela_hash, int chave,
                int quantidade_de_registros, int& total_chaves_inseridas, int& total_acessos);
    };
}

#endif
