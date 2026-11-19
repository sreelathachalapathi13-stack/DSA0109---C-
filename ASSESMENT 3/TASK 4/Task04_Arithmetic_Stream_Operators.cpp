#include <iomanip>
#include <iostream>
using namespace std;
 
class Money {
    long long paise;
 
public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}
 
    Money operator+(const Money& other) const {
        Money result;
        result.paise = paise + other.paise;
        return result;
    }
 
    Money operator-(const Money& other) const {
        Money result;
        result.paise = paise - other.paise;
        return result;
    }
 
    Money& operator+=(const Money& other) {
        paise += other.paise;
        return *this;
    }
 
    bool operator==(const Money& other) const {
        return paise == other.paise;
    }
 
    bool operator<(const Money& other) const {
        return paise < other.paise;
    }
 
    friend ostream& operator<<(ostream& out, const Money& amount) {
        long long absolutePaise =
            amount.paise < 0 ? -amount.paise : amount.paise;
 
        if (amount.paise < 0)
            out << "-";
 
        out << "Rs " << absolutePaise / 100 << '.'
            << setw(2) << setfill('0') << absolutePaise % 100
            << setfill(' ');
        return out;
    }
 
    friend istream& operator>>(istream& in, Money& amount) {
        long long rupees;
        int p;
        if (in >> rupees >> p)
            amount.paise = rupees * 100 + p;
        return in;
    }
};
 
int main() {
    Money a(120, 75), b(79, 25);
    Money c = a + b;
 
    cout << c << '\n';
    cout << boolalpha << (c == Money(200)) << '\n';
 
    Money x(0, 75), y(0, 50);
    cout << "Paise carry: " << x + y << '\n';
 
    Money difference = Money(10, 0) - Money(15, 50);
    cout << "Negative subtraction: " << difference << '\n';
 
    a += b;
    cout << "After += : " << a << '\n';
    return 0;
}
