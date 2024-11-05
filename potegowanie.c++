#include <iostream>
using namespace std;

long long szybkiePotegowanie(long long podstawa, long long wykladnik) {
    if (wykladnik == 0)
        return 1;

    long long polowa = szybkiePotegowanie(podstawa, wykladnik / 2);

    if (wykladnik % 2 == 0)
        return polowa * polowa;
    else 
        return polowa * polowa * podstawa;
}

int main() {
    long long podstawa, wykladnik;
    cout << "Podaj baze (a): ";
    cin >> podstawa;
    cout << "Podaj wykladnik (n): ";
    cin >> wykladnik;

    long long wynik = szybkiePotegowanie(podstawa, wykladnik);
    cout << podstawa << "^" << wykladnik << " = " << wynik << endl;

    return 0;
}
