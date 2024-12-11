#include <iostream>
using namespace std;

void rozkladNaCzynnikiPierwsze(int n) {
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    if (n > 2) {
        cout << n << " ";
    }
}

int main() {
    int liczba;
    cout << "Podaj liczbę: ";
    cin >> liczba;

    cout << "Rozkład na czynniki pierwsze: ";
    rozkladNaCzynnikiPierwsze(liczba);
    
    return 0;
}
