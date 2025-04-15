#include <iostream>
#include <cmath>

using namespace std;

double funkcja(double x) {
    return x * x - 4; 
}

double bisection(double a, double b, double epsilon) {
    // sprawdzamy czy pierwiastek nie znajduje się na granicach przedziału
    if (funkcja(a) == 0.0) {
        return a;  
    }
    if (funkcja(b) == 0.0) {
        return b;  
    }

    //  dopóki szerokość przedziału jest większa niż epsilon
    while ((b - a) > epsilon) {
        //  obliczamy środek przedziału
        double srodek = (a + b) / 2.0;

        if (funkcja(srodek) == 0.0) {
            return srodek;
        }

        // sprawdzamy w której połowie przedziału znajduje się pierwiastek
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
