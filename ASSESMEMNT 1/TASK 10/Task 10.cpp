#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    long long journeys[] = {
        20000, 500000, 3000000
    };

    long long farePaise = 3600;

    cout << fixed << setprecision(2);

    for (long long n : journeys) {
        long long totalPaise = n * farePaise;

        double totalRupees =
            static_cast<double>(n) * 36.0;

        cout << "Journeys: " << n << endl;

        cout << "Total paise: "
             << totalPaise << endl;

        cout << "Total rupees: "
             << totalPaise / 100.0 << endl;

        cout << "Double total: "
             << totalRupees << endl;

        cout << "Difference: "
             << totalRupees - totalPaise / 100.0
             << endl << endl;
    }

    cout << "INT_MAX: "
         << numeric_limits<int>::max() << endl;

    cout << "3 million journeys total paise: "
         << 3000000LL * farePaise << endl;

    return 0;
}