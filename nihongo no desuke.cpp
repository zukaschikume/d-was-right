#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x - 4;  // Przykład: x^2 - 4 = 0, pierwiastki to x = -2 i x = 2
}

double bisection(double a, double b, double epsilon) {
    while ((b - a) / 2 > epsilon) {
        double c = (a + b) / 2;
        if (f(c) == 0) return c;
        (f(a) * f(c) < 0) ? b = c : a = c;  // Warunek zmiany przedziału
    }
    return (a + b) / 2;
}

int main() {
    cout << "Pierwiastek to: " << bisection(0, 3, 1e-6) << endl;
    return 0;
}