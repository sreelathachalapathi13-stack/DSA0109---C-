#include <iostream>
#include <string>
using namespace std;

enum class Zone {
    Inner = 0,
    Middle = 1,
    Outer = 2,
    Airport = 3
};

constexpr long long BASE_FARES_PAISE[] = {
    1000, 2000, 3000, 6000
};

constexpr int PEAK_PERCENT = 20;
constexpr int WEEKEND_DISCOUNT_PERCENT = 10;
constexpr long long MIN_BALANCE_PAISE = 5000;

class MonthlyPass {
private:
    bool active;
    bool covered[4];

public:
    MonthlyPass()
        : active(false),
          covered{false, false, false, false} {}

    void activate(Zone first, Zone second) {
        for (bool &x : covered)
            x = false;

        covered[static_cast<int>(first)] = true;
        covered[static_cast<int>(second)] = true;

        active = true;
    }

    bool covers(Zone zone) const {
        return active &&
               covered[static_cast<int>(zone)];
    }
};

class SmartCard {
private:
    long long balancePaise;

public:
    SmartCard(long long balance) {
        balancePaise = balance;
    }

    long long getBalance() const {
        return balancePaise;
    }

    bool deduct(long long fare) {
        if (fare < 0 ||
            balancePaise - fare < MIN_BALANCE_PAISE)
            return false;

        balancePaise -= fare;
        return true;
    }
};

bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

long long calculateFare(
    Zone zone, int hour, bool weekend
) {
    if (hour < 0 || hour > 23)
        return -1;

    long long fare =
        BASE_FARES_PAISE[static_cast<int>(zone)];

    if (weekend)
        fare -= fare * WEEKEND_DISCOUNT_PERCENT / 100;
    else if (isPeak(hour))
        fare += fare * PEAK_PERCENT / 100;

    return fare;
}

string zoneName(Zone zone) {
    switch (zone) {
        case Zone::Inner: return "Inner";
        case Zone::Middle: return "Middle";
        case Zone::Outer: return "Outer";
        case Zone::Airport: return "Airport";
    }

    return "Invalid";
}

string money(long long paise) {
    return "Rs " + to_string(paise / 100) + "." +
           (paise % 100 < 10 ? "0" : "") +
           to_string(paise % 100);
}

int main() {
    SmartCard card(20000);

    MonthlyPass pass;
    pass.activate(Zone::Inner, Zone::Middle);

    struct Trip {
        Zone zone;
        int hour;
        bool weekend;
    };

    Trip trips[] = {
        {Zone::Airport, 12, false},
        {Zone::Airport, 18, false},
        {Zone::Outer, 18, true},
        {Zone::Inner, 9, false}
    };

    for (const Trip& trip : trips) {
        cout << zoneName(trip.zone) << ": ";

        if (pass.covers(trip.zone)) {
            cout << "Monthly pass used; fare Rs 0.00"
                 << "; balance "
                 << money(card.getBalance()) << endl;
            continue;
        }

        long long fare = calculateFare(
            trip.zone, trip.hour, trip.weekend
        );

        if (fare >= 0 && card.deduct(fare)) {
            cout << "Fare " << money(fare)
                 << "; remaining "
                 << money(card.getBalance()) << endl;
        } else {
            cout << "Journey denied; balance "
                 << money(card.getBalance()) << endl;
        }
    }

    return 0;
}