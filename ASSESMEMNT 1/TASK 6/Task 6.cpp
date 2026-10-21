#include <iostream>
#include <iomanip>
using namespace std;

enum class Zone {
    Inner, Middle, Outer
};

constexpr int BASE_PAISE[] = {
    1000, 2000, 3000
};

constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

long long calculateFare(Zone zone, bool peak) {
    int base = 0;

    switch (zone) {
        case Zone::Inner:
            base = BASE_PAISE[0];
            break;

        case Zone::Middle:
            base = BASE_PAISE[1];
            break;

        case Zone::Outer:
            base = BASE_PAISE[2];
            break;

        default:
            return -1;
    }

    long long fare = base;

    if (peak)
        fare += fare * PEAK_SURCHARGE_PERCENT / 100;

    return fare;
}

bool canTravel(long long balance, long long fare) {
    return fare >= 0 &&
           balance - fare >= MIN_BALANCE_PAISE;
}

int main() {
    long long balance = 10000;

    struct Trip {
        Zone zone;
        bool peak;
    };

    Trip trips[] = {
        {Zone::Inner, false},
        {Zone::Outer, true},
        {Zone::Middle, false}
    };

    for (const Trip& trip : trips) {
        long long fare = calculateFare(
            trip.zone, trip.peak
        );

        if (canTravel(balance, fare)) {
            balance -= fare;

            cout << "Fare Rs "
                 << fare / 100 << "."
                 << setw(2) << setfill('0')
                 << fare % 100 << setfill(' ');
        } else {
            cout << "Denied (low balance)";
        }

        cout << " balance Rs "
             << balance / 100 << endl;
    }

    return 0;
}