#include <iostream>
#include <string>
using namespace std;

bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

long long baseFare(int zone) {
    switch (zone) {
        case 1: return 1000;
        case 2: return 2000;
        case 3: return 3000;
        default: return -1;
    }
}

long long calculateFare(
    int zone, int hour, bool weekend = false
) {
    if (hour < 0 || hour > 23)
        return -1;

    long long fare = baseFare(zone);

    if (fare < 0)
        return -1;

    if (weekend)
        fare -= fare * 10 / 100;
    else if (isPeak(hour))
        fare += fare * 20 / 100;

    return fare;
}

bool canTravel(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= 5000;
}

string money(long long paise) {
    return "Rs " + to_string(paise / 100) + "." +
           (paise % 100 < 10 ? "0" : "") +
           to_string(paise % 100);
}

int main() {
    struct Test {
        string name;
        int zone;
        int hour;
        bool weekend;
        long long balance;
        long long expectedFare;
        bool expectedAllowed;
    };

    Test tests[] = {
        {"Inner off-peak", 1, 11, false, 10000, 1000, true},
        {"Middle off-peak", 2, 12, false, 10000, 2000, true},
        {"Outer off-peak", 3, 12, false, 10000, 3000, true},
        {"Inner peak", 1, 8, false, 10000, 1200, true},
        {"At 10 AM", 1, 10, false, 10000, 1000, true},
        {"At 5 PM", 1, 17, false, 10000, 1200, true},
        {"At 8 PM", 1, 20, false, 10000, 1000, true},
        {"Exactly Rs 50 left", 1, 12, false, 6000, 1000, true},
        {"Unknown zone", 9, 12, false, 10000, -1, false},
        {"Weekend discount", 3, 18, true, 10000, 2700, true},
        {"Peak outer fare", 3, 18, false, 10000, 3600, true}
    };

    for (const auto& t : tests) {
        long long fare = calculateFare(
            t.zone, t.hour, t.weekend
        );

        bool allowed = canTravel(t.balance, fare);

        bool pass = fare == t.expectedFare &&
                    allowed == t.expectedAllowed;

        cout << t.name << ": ";

        if (fare < 0)
            cout << "Invalid fare";
        else
            cout << money(fare);

        cout << ", Journey: "
             << (allowed ? "Allowed" : "Denied");

        cout << ", Test: "
             << (pass ? "PASS" : "FAIL") << endl;
    }

    return 0;
}