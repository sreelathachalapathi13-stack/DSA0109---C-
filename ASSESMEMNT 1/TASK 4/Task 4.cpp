#include <iostream>
using namespace std;

int main() {
    int a = 7, b = 2;

    double c = a / b;
    double d = static_cast<double>(a) / b;

    cout << c << " " << d << endl;

    char ch = 'A' + 2;

    cout << ch << " " << ch + 1 << endl;

    bool flag = 5;

    cout << flag << " ";
    cout << boolalpha << flag << endl;

    unsigned int u = 1;
    int s = -1;

    cout << (s < u ? "s < u" : "s >= u") << endl;

    return 0;
}