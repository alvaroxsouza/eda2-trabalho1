#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    int p = atoi(argv[1]);
    int n = atoi(argv[2]);

    if (!isPrime(p)) {
        cout << "P não é número primo" << endl;
        return 1;
    }



    srand(time(NULL));

    ofstream output_file("entrada.txt");

    output_file << p << endl;
    // output_file << n << endl;

    vector<int> entradas;
    for (int i = 0; i < n; i++) {
        int entrada;
        do {
            entrada = rand() % 551 + 80;
        } while (find(entradas.begin(), entradas.end(), entrada) != entradas.end());
        entradas.push_back(entrada);
        output_file << entrada << endl;
    }
    output_file.close();

    return 0;
}
