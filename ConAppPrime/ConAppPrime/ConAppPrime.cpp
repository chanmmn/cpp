// ConAppPrime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool isPrime2(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void segmentedSieve(int low, int high) {
    std::vector<bool> isPrime(high - low + 1, true);
    std::vector<int> primes;

    for (int p = 2; p * p <= high; ++p) {
        for (int i = std::max(p * p, (low + p - 1) / p * p); i <= high; i += p) {
            isPrime[i - low] = false;
        }
    }

    for (int i = low; i <= high; ++i) {
        if (isPrime[i - low]) {
            primes.push_back(i);
        }
    }

    std::cout << "Prime numbers between " << low << " and " << high << ": ";
    for (int prime : primes) {
        std::cout << prime << " ";
    }
}

int main()
{
    std::cout << "Hello World!\n";
    int lower, upper;
    std::cout << "Enter lower and upper limits: ";
    std::cin >> lower >> upper;

    segmentedSieve(lower, upper);
    return 0;
}

