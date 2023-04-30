#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(0));
    int p = rand() % 999990 + 11;
    while (!is_prime(p)) {
        p = rand() % 999990 + 11;
    }
    ofstream file;
    file.open("entrada.txt");
    file << p << endl;
    int n = rand() % (p - 1) + 1;
    file << n << endl;
    for (int i = 0; i < n; i++) {
        int x = rand() % 1000000 + 1;
        file << x << endl;
    }
    file.close();
    return 0;
}