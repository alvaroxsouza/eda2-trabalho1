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
            static void insertPerfectHash(vector<vector<int>>& nivel_um, vector<vector<int>>& nivel_dois,
                int chave, int quantidade_de_registros, int a, int b, int& total_acessos,
                int& total_chaves_inseridas);
    };
}

#endif