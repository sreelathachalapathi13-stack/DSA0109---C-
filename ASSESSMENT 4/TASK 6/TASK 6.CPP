#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Vehicle {
protected:
    string registration;
    double dailyRate;
    bool rented;

public:
    Vehicle(string r, double rate)
        : registration(r), dailyRate(rate), rented(false) {}

    virtual double charge(int days) const = 0;

    virtual void display() const = 0;

    void rent() {
        if (!rented) {
            rented = true;
            cout << registration << " rented successfully" << endl;
        }
        else {
            cout << registration << " is already rented" << endl;
        }
    }

    void returnVehicle(int daysLate) {
        if (rented) {
            double amount = charge(daysLate > 0 ? daysLate : 1);
            double lateCharge = daysLate > 0 ? daysLate * 100 : 0;

            cout << registration << " returned successfully" << endl;
            cout << "Late Charge: Rs." << lateCharge << endl;

            rented = false;
        }
        else {
            cout << "Vehicle was not rented" << endl;
        }
    }

    virtual ~Vehicle() {}
};

class Bicycle : public Vehicle {
public:
    Bicycle(string r, double rate)
        : Vehicle(r, rate) {}

    double charge(int days) const override {
        return dailyRate * days;
    }

    void display() const override {
        cout << "Bicycle: " << registration
             << " Rate: " << dailyRate << endl;
    }
};

class MotorVehicle : public Vehicle {
protected:
    double fuelLevel;
    string serviceDate;

public:
    MotorVehicle(string r, double rate,
                 double fuel, string date)
        : Vehicle(r, rate),
          fuelLevel(fuel), serviceDate(date) {}
};

class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(string r, double rate,
               double fuel, string date)
        : MotorVehicle(r, rate, fuel, date) {}

    double charge(int days) const override {
        return dailyRate * days;
    }

    void display() const override {
        cout << "Two Wheeler: " << registration
             << " Rate: " << dailyRate
             << " Fuel: " << fuelLevel << endl;
    }
};

class Car : public MotorVehicle {
protected:
    int seats;

public:
    Car(string r, double rate, double fuel,
        string date, int s)
        : MotorVehicle(r, rate, fuel, date), seats(s) {}

    double charge(int days) const override {
        return dailyRate * days;
    }

    void display() const override {
        cout << "Car: " << registration
             << " Rate: " << dailyRate
             << " Seats: " << seats << endl;
    }
};

class ElectricCar : public Car {
    double batteryCapacity;

public:
    ElectricCar(string r, double rate,
                string date, int s, double battery)
        : Car(r, rate, 0, date, s),
          batteryCapacity(battery) {}

    double charge(int days) const override {
        return dailyRate * days + batteryCapacity * 2;
    }

    void display() const override {
        cout << "Electric Car: " << registration
             << " Rate: " << dailyRate
             << " Battery: " << batteryCapacity
             << " kWh" << endl;
    }
};

// New vehicle type added without modifying existing classes
class ElectricBus : public Vehicle {
    double batteryCapacity;

public:
    ElectricBus(string r, double rate, double battery)
        : Vehicle(r, rate), batteryCapacity(battery) {}

    double charge(int days) const override {
        return dailyRate * days + batteryCapacity * 3;
    }

    void display() const override {
        cout << "Electric Bus: " << registration
             << " Rate: " << dailyRate
             << " Battery: " << batteryCapacity
             << " kWh" << endl;
    }
};

int main() {
    vector<unique_ptr<Vehicle>> fleet;

    fleet.push_back(make_unique<Bicycle>("B101", 100));
    fleet.push_back(make_unique<TwoWheeler>(
        "T101", 300, 5, "2026-12-01"));

    fleet.push_back(make_unique<Car>(
        "C101", 1000, 20, "2026-12-10", 5));

    fleet.push_back(make_unique<ElectricCar>(
        "E101", 1500, "2026-12-15", 5, 60));

    fleet.push_back(make_unique<ElectricBus>(
        "EB101", 3000, 200));

    cout << "VEHICLE RENTAL FLEET\n\n";

    for (const auto& v : fleet) {
        v->display();
    }

    cout << "\nRENTING VEHICLES\n";

    for (const auto& v : fleet) {
        v->rent();
    }

    cout << "\nRENTAL CHARGES FOR 3 DAYS\n";

    for (const auto& v : fleet) {
        cout << "Charge: Rs."
             << v->charge(3) << endl;
    }

    cout << "\nRETURNING VEHICLES\n";

    for (const auto& v : fleet) {
        v->returnVehicle(2);
    }

    cout << "\nFLEET DETAILS\n";

    for (const auto& v : fleet) {
        v->display();
    }

    return 0;
}