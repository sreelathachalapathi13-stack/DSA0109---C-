#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    int hour;

    cout << "Enter departure hour (0-23): ";

    while (!(cin >> hour) || hour < 0 || hour > 23) {
        cout << "Invalid hour. Enter again: ";

        cin.clear();

        cin.ignore(
            numeric_limits<streamsize>::max(), '\n'
        );
    }

    bool peak =
        (hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20);

    cout << boolalpha;
    cout << "Peak hour: " << peak << endl;

    long long farePaise = 3000;

    if (peak)
        farePaise += farePaise * 20 / 100;

    cout << "Fare: Rs "
         << farePaise / 100 << "."
         << setw(2) << setfill('0')
         << farePaise % 100 << endl;

    return 0;
}