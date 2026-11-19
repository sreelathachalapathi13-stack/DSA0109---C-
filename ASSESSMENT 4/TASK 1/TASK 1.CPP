#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Staff {
protected:
    string name;
    int id;
    double basic;

public:
    Staff(string n, int i, double b)
        : name(n), id(i), basic(b) {}

    virtual double pay() const = 0;

    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << pay() << endl;
    }

    virtual ~Staff() {}
};

class Professor : public Staff {
    double research;

public:
    Professor(string n, int i, double b, double r)
        : Staff(n, i, b), research(r) {}

    double pay() const override {
        return basic + basic * 0.42 + research;
    }
};

class LabAssistant : public Staff {
public:
    LabAssistant(string n, int i, double b)
        : Staff(n, i, b) {}

    double pay() const override {
        return basic + basic * 0.42;
    }
};

class GuestFaculty : public Staff {
    double hours, rate;

public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n, i, 0), hours(h), rate(r) {}

    double pay() const override {
        return hours * rate;
    }
};

int main() {
    vector<Staff*> employees;

    employees.push_back(new Professor("Ravi", 101, 50000, 10000));
    employees.push_back(new LabAssistant("Kumar", 102, 30000));
    employees.push_back(new GuestFaculty("Anu", 103, 40, 500));

    for (Staff* s : employees) {
        s->display();
        cout << "------------------" << endl;
    }

    for (Staff* s : employees)
        delete s;

    return 0;
}