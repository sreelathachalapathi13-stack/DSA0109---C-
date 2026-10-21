#include <iostream>
using namespace std;

constexpr long long MIN_BALANCE_PAISE = 5000;

long long proceduralFare(int zone, bool peak) {
    long long fare;

    if (zone == 1)
        fare = 1000;
    else if (zone == 2)
        fare = 2000;
    else if (zone == 3)
        fare = 3000;
    else
        return -1;

    if (peak)
        fare += fare * 20 / 100;

    return fare;
}

bool proceduralCanTravel(long long balance, long long fare) {
    return fare >= 0 &&
           balance - fare >= MIN_BALANCE_PAISE;
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

    bool deduct(long long fare) {
        if (fare < 0 ||
            balancePaise - fare < MIN_BALANCE_PAISE)
            return false;

        balancePaise -= fare;
        return true;
    }
};

int main() {
    long long balance = 10000;

    long long fare = proceduralFare(1, false);

    if (proceduralCanTravel(balance, fare))
        balance -= fare;

    cout << "Procedural balance paise: "
         << balance << endl;

    SmartCard card(10000);

    if (card.deduct(fare))
        cout << "OOP balance paise: "
             << card.getBalance() << endl;

    return 0;
}