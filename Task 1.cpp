#include <iostream>
using namespace std;

class SmartCard {
private:
    long long balancePaise;

public:
    SmartCard(long long balance) {
        balancePaise = balance;
    }

    long long getBalance() {
        return balancePaise;
    }

    bool deduct(long long fare) {
        if (fare < 0 || balancePaise - fare < 5000)
            return false;

        balancePaise -= fare;
        return true;
    }
};

class FareTable {
public:
    static long long getFare(int zone) {
        switch (zone) {
            case 1: return 1000;
            case 2: return 2000;
            case 3: return 3000;
            default: return -1;
        }
    }
};

int main() {
    SmartCard card(10000);

    long long fare = FareTable::getFare(1);

    if (fare >= 0 && card.deduct(fare))
        cout << "Journey allowed. Balance paise: "
             << card.getBalance() << endl;
    else
        cout << "Journey denied." << endl;

    return 0;
}