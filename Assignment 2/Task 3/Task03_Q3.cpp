#include <iostream>
using namespace std;

struct Parcel {
    double weightKg;
    bool express;
    bool insured;
};

double charge(int grams, bool express = false, bool insured = false) {
    double total = grams * 0.02;
    if (express) total += 30;
    if (insured) total += 20;
    cout << "Integer grams: ";
    return total;
}

double charge(double kg, bool express = false, bool insured = false) {
    double total = kg * 50;
    if (express) total += 30;
    if (insured) total += 20;
    cout << "Double kilograms: ";
    return total;
}

double charge(const Parcel& p) {
    double total = p.weightKg * 50;
    if (p.express) total += 30;
    if (p.insured) total += 20;
    cout << "Parcel object: ";
    return total;
}

int main() {
    Parcel p{2.5, true, true};

    cout << "charge(2) = " << charge(2) << '\n';
    cout << "charge(2.0f) = " << charge(2.0f) << '\n';
    cout << "charge(500) = " << charge(500) << '\n';
    cout << "charge(2.5) = " << charge(2.5) << '\n';
    cout << "charge(2, true) = " << charge(2, true) << '\n';
    cout << "charge(p) = " << charge(p) << '\n';
    return 0;
}
