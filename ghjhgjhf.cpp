#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string decToBinary(int n) {
    string binary = "";
    
   
    if (n == 0) {
        return "0";
    }

   
    while (n > 0) {
        binary += (n % 2 == 0) ? '0' : '1';  
        n /= 2;  
    }

    
    reverse(binary.begin(), binary.end());

    return binary;
}

int main() {
    int decimal;
    cout << "Podaj liczbę dziesiętną: ";
    cin >> decimal;

    string binary = decToBinary(decimal);
    cout << "Liczba binarna: " << binary << endl;

    return 0;
}
