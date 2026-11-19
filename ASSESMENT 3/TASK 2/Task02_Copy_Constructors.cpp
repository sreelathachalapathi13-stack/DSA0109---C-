#include <iostream>
#include <string>
using namespace std;
 
class Prescription {
    int n;
    string* medicines;
 
public:
    explicit Prescription(int count)
        : n(count), medicines(count > 0 ? new string[count] : nullptr) {}
 
    // Deep-copy constructor
    Prescription(const Prescription& other)
        : n(other.n),
          medicines(other.n > 0 ? new string[other.n] : nullptr) {
        for (int i = 0; i < n; ++i)
            medicines[i] = other.medicines[i];
        cout << "Copy constructor called\n";
    }
 
    // Deep-copy assignment operator
    Prescription& operator=(const Prescription& other) {
        if (this != &other) {
            string* newMedicines =
                other.n > 0 ? new string[other.n] : nullptr;
 
            for (int i = 0; i < other.n; ++i)
                newMedicines[i] = other.medicines[i];
 
            delete[] medicines;
            medicines = newMedicines;
            n = other.n;
        }
        return *this;
    }
 
    ~Prescription() {
        delete[] medicines;
    }
 
    void set(int i, const string& medicine) {
        if (i >= 0 && i < n)
            medicines[i] = medicine;
    }
 
    string get(int i) const {
        if (i >= 0 && i < n)
            return medicines[i];
        return "Invalid index";
    }
 
    void display() const {
        for (int i = 0; i < n; ++i)
            cout << medicines[i] << ' ';
        cout << '\n';
    }
};
 
int main() {
    Prescription p(2);
    p.set(0, "Paracetamol");
    p.set(1, "ORS");
 
    Prescription q = p;       // Copy constructor
    q.set(1, "Cetirizine");
 
    Prescription r(1);
    r = p;                    // Copy assignment
    p.set(0, "Ibuprofen");
 
    cout << p.get(0) << ' ' << p.get(1) << " | "
         << q.get(0) << ' ' << q.get(1) << " | "
         << r.get(0) << ' ' << r.get(1) << '\n';
 
    p = p;                    // Self-assignment test
    return 0;
}
