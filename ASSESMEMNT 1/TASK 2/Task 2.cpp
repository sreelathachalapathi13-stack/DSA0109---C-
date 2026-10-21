#include <iostream>
using namespace std;

enum class Zone {
    Inner, Middle, Outer
};

constexpr long long INNER_FARE_PAISE = 1000;
constexpr long long MIDDLE_FARE_PAISE = 2000;
constexpr long long OUTER_FARE_PAISE = 3000;

constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

int main() {
    cout << "Inner fare: "
         << INNER_FARE_PAISE << " paise" << endl;

    cout << "Middle fare: "
         << MIDDLE_FARE_PAISE << " paise" << endl;

    cout << "Outer fare: "
         << OUTER_FARE_PAISE << " paise" << endl;

    cout << "Peak surcharge: "
         << PEAK_SURCHARGE_PERCENT << "%" << endl;

    cout << "Minimum balance: "
         << MIN_BALANCE_PAISE << " paise" << endl;

    return 0;
}