#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

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
        cout << "p must be a prime number." << endl;
        return 1;
    }

    srand(time(NULL));

    ofstream output_file("entrada.txt");

    output_file << p << endl;
    output_file << n << endl;

    for (int i = 0; i < n; i++) {
        int entrada = rand() % (p - 1) + 1;
        output_file << entrada << endl;
    }

    output_file.close();

    return 0;
}
