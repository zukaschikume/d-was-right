#include <iostream>
#include <cmath>

using namespace std;

double funkcja(double x) {
    return x * x - 4; 
}

double bisection(double a, double b, double epsilon) {
    // Krok K1 i K2: sprawdzamy czy pierwiastek nie znajduje się na granicach przedziału
    if (funkcja(a) == 0.0) {
        return a;  // Jeśli f(a) = 0, to a jest pierwiastkiem
    }
    if (funkcja(b) == 0.0) {
        return b;  // Jeśli f(b) = 0, to b jest pierwiastkiem
    }

    // Krok K3: dopóki szerokość przedziału jest większa niż epsilon
    while ((b - a) > epsilon) {
        // Krok K4: obliczamy środek przedziału
        double srodek = (a + b) / 2.0;

        // Krok K5: jeżeli f(srodek) = 0 to zwracamy środek
        if (funkcja(srodek) == 0.0) {
            return srodek;
        }

        // Krok K6: sprawdzamy w której połowie przedziału znajduje się pierwiastek
        if (funkcja(a) * funkcja(srodek) < 0) {
            b = srodek;  // Pierwiastek znajduje się w lewej części przedziału
        } else {
            a = srodek;  // Pierwiastek znajduje się w prawej części przedziału
        }
    }

    return (a + b) / 2.0;
}

int main() {
    double a = 3, b = 3, epsilon = 0.001; 
    double pierwiastek = bisection(a, b, epsilon);

    cout << "Znalezione miejsce zerowe wynosi: " << pierwiastek << endl;
    return 0;
}
