#include <iostream>
using namespace std;

void rozkladNaCzynnikiPierwsze(int n) {
    // Sprawdzamy dzielno�� przez 2
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    // Sprawdzamy dzielno�� przez liczby nieparzyste od 3 do sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // Je�eli n jest wi�ksze od 2, to jest liczb� pierwsz�
    if (n > 2) {
        cout << n << " ";
    }
}

int main() {
    int liczba;
    cout << "Podaj liczb�: ";
    cin >> liczba;

    cout << "Rozk�ad na czynniki pierwsze: ";
    rozkladNaCzynnikiPierwsze(liczba);

    return 0;
}