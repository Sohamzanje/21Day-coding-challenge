#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;  // Numbers less than 2 are not prime
    for (int i = 2; i * i <= n; i++) { // Check up to sqrt(n)
        if (n % i == 0) return false;  // Found a divisor, not prime
    }
    return true;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPrime(n))
        cout << "Prime" << endl;
    else
        cout << "Not Prime" << endl;

    return 0;
}