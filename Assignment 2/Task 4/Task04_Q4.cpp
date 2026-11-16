#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    double balance;
    double transactions[10];
    int count;

public:
    SavingsAccount(string number, double openingBalance)
        : accountNumber(number), balance(openingBalance), count(0) {}

    void deposit(double amount) {
        if (amount <= 0) return;
        balance += amount;
        addTransaction(amount);
    }

    void withdraw(double amount);
    void miniStatement() const;

private:
    void addTransaction(double amount) {
        if (count < 10) {
            transactions[count++] = amount;
        } else {
            for (int i = 1; i < 10; ++i)
                transactions[i - 1] = transactions[i];
            transactions[9] = amount;
        }
    }
};

void SavingsAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        cout << "Invalid withdrawal\n";
        return;
    }
    balance -= amount;
    addTransaction(-amount);
}

void SavingsAccount::miniStatement() const {
    cout << "Account: " << accountNumber << '\n';
    cout << "Balance: " << balance << '\n';
    cout << "Last transactions:\n";
    for (int i = 0; i < count; ++i)
        cout << transactions[i] << '\n';
}

int main() {
    SavingsAccount account("SB1001", 5000);
    account.deposit(1000);
    account.withdraw(500);
    account.deposit(250);
    account.withdraw(100);
    account.miniStatement();
    return 0;
}
