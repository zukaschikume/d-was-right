#include <iostream>
using namespace std;

void rozkladNaCzynnikiPierwsze(int n) {
    // Sprawdzamy dzielnoœæ przez 2
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    // Sprawdzamy dzielnoœæ przez liczby nieparzyste od 3 do sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // Je¿eli n jest wiêksze od 2, to jest liczb¹ pierwsz¹
    if (n > 2) {
        cout << n << " ";
    }
}

int main() {
    int liczba;
    cout << "Podaj liczbê: ";
    cin >> liczba;

    cout << "Rozk³ad na czynniki pierwsze: ";
    rozkladNaCzynnikiPierwsze(liczba);

    return 0;
}