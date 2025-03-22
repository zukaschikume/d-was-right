#include <iostream>
#include <vector>

using namespace std;

// Funkcja obliczająca wartość wielomianu metodą Hornera
double horner(const vector<double>& wspolczynniki, double x) {
    double wynik = wspolczynniki[0];
    for (size_t i = 1; i < wspolczynniki.size(); i++) {
        wynik = wynik * x + wspolczynniki[i];
    }
    return wynik;
}

int main() {
    int stopien;
    cout << "Podaj stopien wielomianu: ";
    cin >> stopien;

    vector<double> wspolczynniki(stopien + 1);
    for (int i = 0; i <= stopien; i++) {
        cout << "Podaj wspolczynnik stojacy przy potedze " << stopien - i << ": ";
        cin >> wspolczynniki[i];
    }

    double argument;
    cout << "Podaj argument: ";
    cin >> argument;

    double wynik = horner(wspolczynniki, argument);
    cout << "W( " << argument << " ) = " << wynik << endl;

    return 0;
}
