#include <iostream>
using namespace std;

enum class Zone {
    Inner, Middle, Outer
};

constexpr long long FARES_PAISE[] = {
    1000, 2000, 3000
};

constexpr int PEAK_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

long long calculateFare(Zone zone, int hour) {
    if (hour < 0 || hour > 23)
        return -1;

    int index = static_cast<int>(zone);

    long long fare = FARES_PAISE[index];

    if (isPeak(hour))
        fare += fare * PEAK_PERCENT / 100;

    return fare;
}

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

    bool pay(long long fare) {
        if (fare < 0 ||
            balancePaise - fare < MIN_BALANCE_PAISE)
            return false;

        balancePaise -= fare;
        return true;
    }
};

int main() {
    SmartCard card(10000);

    long long fare = calculateFare(Zone::Outer, 18);

    cout << "Fare paise: " << fare << endl;

    if (card.pay(fare))
        cout << "Accepted. Remaining paise: "
             << card.getBalance() << endl;
    else
        cout << "Denied. Remaining paise: "
             << card.getBalance() << endl;

    return 0;
}