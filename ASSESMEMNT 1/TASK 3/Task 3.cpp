#include <iostream>
#include <climits>
using namespace std;

int main() {
    cout << "Size of bool: " << sizeof(bool) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of long long: " << sizeof(long long) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;

    cout << "INT_MIN: " << INT_MIN << endl;
    cout << "INT_MAX: " << INT_MAX << endl;

    cout << "LLONG_MIN: " << LLONG_MIN << endl;
    cout << "LLONG_MAX: " << LLONG_MAX << endl;

    long long journeys = 3000000;
    long long farePaise = 3600;

    long long totalPaise = journeys * farePaise;

    cout << "Total collection in paise: "
         << totalPaise << endl;

    cout << "Total collection in rupees: "
         << totalPaise / 100 << endl;

    return 0;
}