#include <iostream>
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

vector<int> findPrimesInRange(int lower, int upper) {
    vector<int> primes;
    for (int i = lower; i <= upper; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    srand(time(NULL));
    
    vector<int> primes = findPrimesInRange(100000, 1000000);
    
    for (int i = 0; i < 10; i++) {
        int index = rand() % primes.size();
        cout << primes[index] << " ";
    }
    
    cout << endl;
    
    return 0;
}