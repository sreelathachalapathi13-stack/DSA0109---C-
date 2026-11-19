#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Account {
public:
    virtual double rate() const {
        return 3.5;
    }

    virtual void display() const {
        cout << "Normal Account Interest: "
             << rate() << "%" << endl;
    }

    virtual ~Account() {
        cout << "Account Destructor" << endl;
    }
};

class SeniorAccount : public Account {
    double* history;

public:
    SeniorAccount() {
        history = new double[100]{};
    }

    double rate() const override {
        return 4.0;
    }

    void display() const override {
        cout << "Senior Account Interest: "
             << rate() << "%" << endl;
    }

    ~SeniorAccount() override {
        delete[] history;
        cout << "Senior Account Destructor" << endl;
    }
};

int main() {
    vector<unique_ptr<Account>> accounts;

    accounts.push_back(make_unique<Account>());
    accounts.push_back(make_unique<SeniorAccount>());

    cout << "Account Details\n";

    for (const auto& a : accounts) {
        a->display();
    }

    cout << "\nInterest Rates\n";

    for (const auto& a : accounts) {
        cout << a->rate() << "%" << endl;
    }

    cout << "\nProgram completed\n";

    return 0;
}