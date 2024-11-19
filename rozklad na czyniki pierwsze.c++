#include <iostream>
using namespace std;

void rozkladNaCzynnikiPierwsze(int n) {
    // Sprawdzamy dzielność przez 2
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    // Sprawdzamy dzielność przez liczby nieparzyste od 3 do sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // Jeżeli n jest większe od 2, to jest liczbą pierwszą
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
