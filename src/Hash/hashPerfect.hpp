#ifndef HASH_PERFECT_HPP
#define HASH_PERFECT_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace HashPerfectClass {
    class HashPerfect {
        private:
        /* data */
        public:
            static void insertPerfectHash(
                vector<vector<long int>>& nivel_um,
                vector<vector<long int>>& nivel_dois,
                long int chave,
                long int quantidade_de_registros,
                int a, int b,
                long int& total_acessos,
                long int& total_chaves_inseridas);
    };
}

#endif