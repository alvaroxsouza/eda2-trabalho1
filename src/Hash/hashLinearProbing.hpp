#ifndef HASH_LINEAR_PROBING_HPP
#define HASH_LINEAR_PROBING_HPP

#include <vector>

using namespace std;

namespace HashLinearProbingClass {
    class HashLinearProbing {
        
        private:
        
        public:
            static void insertLinearProbingHash(vector<int>& tabela_hash, int chave,
                    int quantidade_de_registros, int& total_chaves_inseridas, int& total_acessos);
        
    };
}

#endif