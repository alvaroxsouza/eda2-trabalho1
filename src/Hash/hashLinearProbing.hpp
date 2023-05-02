#ifndef HASH_LINEAR_PROBING_HPP
#define HASH_LINEAR_PROBING_HPP

#include <vector>

using namespace std;

namespace HashLinearProbingClass {
    class HashLinearProbing {
        
        private:
        
        public:
            static void insertLinearProbingHash(vector<long int>& tabela_hash,
                long int chave,
                long int quantidade_de_registros,
                long int& total_chaves_inseridas,
                long int& total_acessos);
                
            static void saidaLinearProbingHash(
                vector<long int>& tabela_hash,
                long int quantidade_de_registros
                );
        
    };
}

#endif