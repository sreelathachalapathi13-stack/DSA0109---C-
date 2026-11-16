#include <iostream>
using namespace std;

// Redesigned transaction history using a circular array.
// Adding a transaction takes O(1), unlike shifting the array (O(k)).
class TransactionHistory {
private:
    static const int SIZE = 10;
    double data[SIZE];
    int start;
    int count;

public:
    TransactionHistory() : start(0), count(0) {}

    void add(double amount) {
        if (count < SIZE) {
            data[(start + count) % SIZE] = amount;
            ++count;
        } else {
            data[start] = amount;
            start = (start + 1) % SIZE;
        }
    }

    void display() const {
        cout << "Last " << count << " transactions:\n";
        for (int i = 0; i < count; ++i)
            cout << data[(start + i) % SIZE] << '\n';
    }
};

int main() {
    TransactionHistory history;
    for (int i = 1; i <= 12; ++i)
        history.add(i * 100);
    history.display();
    return 0;
}
