#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;
 
class Complex {
    double real;
    double imag;
 
public:
    Complex() : real(0.0), imag(0.0) {}
    Complex(double r) : real(r), imag(0.0) {}
    Complex(double r, double i) : real(r), imag(i) {}
 
    Complex operator+(const Complex& z) const {
        return Complex(real + z.real, imag + z.imag);
    }
 
    Complex operator-(const Complex& z) const {
        return Complex(real - z.real, imag - z.imag);
    }
 
    Complex operator*(const Complex& z) const {
        return Complex(real * z.real - imag * z.imag,
                       real * z.imag + imag * z.real);
    }
 
    Complex operator/(const Complex& z) const {
        double denominator = z.real * z.real + z.imag * z.imag;
        if (denominator == 0.0)
            throw runtime_error("Division by zero impedance");
 
        return Complex((real * z.real + imag * z.imag) / denominator,
                       (imag * z.real - real * z.imag) / denominator);
    }
 
    bool operator==(const Complex& z) const {
        const double epsilon = 1e-9;
        return fabs(real - z.real) < epsilon &&
               fabs(imag - z.imag) < epsilon;
    }
 
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }
 
    friend ostream& operator<<(ostream& out, const Complex& z) {
        out << z.real;
        if (z.imag >= 0)
            out << " + j" << z.imag;
        else
            out << " - j" << -z.imag;
        return out;
    }
};
 
int main() {
    try {
        const double pi = acos(-1.0);
        double frequency = 50.0;
        double omega = 2.0 * pi * frequency;
        double inductance = 0.1;
        double capacitance = 100e-6;
        double resistance = 100.0;
 
        // Impedances: resistor, inductor and capacitor
        Complex Zr(resistance, 0.0);
        Complex Zl(0.0, omega * inductance);
        Complex Zc(0.0, -1.0 / (omega * capacitance));
 
        // Series RLC impedance
        Complex series = Zr + Zl + Zc;
        cout << "Series impedance: " << series << '\n';
        cout << "Series magnitude: " << series.magnitude() << '\n';
 
        // Parallel combination: (Z1 * Z2) / (Z1 + Z2)
        Complex parallel = (Zr * Zl) / (Zr + Zl);
        cout << "Parallel R-L impedance: " << parallel << '\n';
        cout << "Parallel magnitude: " << parallel.magnitude() << '\n';
 
        // Division-by-zero test
        Complex zero(0.0, 0.0);
        Complex test(10.0, 5.0);
        cout << "Division test: " << (test / zero) << '\n';
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }
 
    return 0;
}
