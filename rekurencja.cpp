#include <iostream>
#include <limits> 

using namespace std;

int GetNumberFromUser() {
    int n;
    cout << "Podaj liczbę całkowitą n: ";
    while (!(cin >> n) || n < 1) {
        cout << "Niepoprawna liczba. Podaj liczbę całkowitą większą lub równą 1: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    return n;
}

int CalculateSumRecursive(int n) {
    if (n == 1) {
        return 1; 
    }
    return n + CalculateSumRecursive(n - 1); 
}


void DisplayResult(int sum) {
    cout << "Suma liczb od 1 do n wynosi: " << sum << endl;
}

int main() {
    int n = GetNumberFromUser();

    int sum = CalculateSumRecursive(n);


    DisplayResult(sum);

    return 0;
}
