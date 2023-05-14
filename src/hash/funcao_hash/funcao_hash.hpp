#ifndef HASH_FUNCAO_HPP
#define HASH_FUNCAO_HPP

#include <iostream>
#include <math.h>

using namespace std;

namespace hash_funcao_class {
    class hash_funcao {
        private:
        public:
            static long int funcao_hash_h1(
                long int valor_node,
                long int tamanho_arquivo
                );
                
            static long int funcao_hash_h2(
                long int valor_node,
                long int tamanho_arquivo
                );
    };
}

#endif