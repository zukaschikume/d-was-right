#include <iostream>
using namespace std;

double horner(int* wspolczynniki, int stopien, double x) {
    double wynik = wspolczynniki[0]; 
    for (int i = 1; i <= stopien; ++i) {
        wynik = wynik * x + wspolczynniki[i]; 
    }
    return wynik;
}

int main() {
    int stopien;
    double x;


    cout << "Podaj stopien wielomianu: ";
    cin >> stopien;

    int* wspolczynniki = new int[stopien + 1];

    for (int i = stopien; i >= 0; --i) {
        cout << "Podaj wspolczynnik stojacy przy potedze " << i << ": ";
        cin >> wspolczynniki[stopien - i];
    }

    cout << "Podaj argument: ";
    cin >> x;

    double wynik = horner(wspolczynniki, stopien, x);

    cout << "W( " << x << " ) = " << wynik << endl;

    delete[] wspolczynniki;

    return 0;
}
