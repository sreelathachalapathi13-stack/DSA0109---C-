#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Cart {
    string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;

public:
    // Add item using this pointer
    Cart& add(string item, double price) {
        if (n < 10) {
            this->items[n] = item;
            this->prices[n] = price;
            n++;
        }
        return *this;
    }

    // Set discount using this pointer
    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double t = 0;

        for (int i = 0; i < n; ++i)
            t += prices[i];

        return t * (100 - discount) / 100;
    }

    void display() const {
        for (int i = 0; i < n; i++) {
            cout << items[i] << " - Rs."
                 << prices[i] << endl;
        }

        cout << "Total: Rs." << total() << endl;
    }
};

int main() {
    // 1. Direct object access
    Cart c;

    c.add("Rice", 60)
     .add("Dal", 120)
     .setDiscount(10);

    cout << "Direct Object Access\n";
    c.display();

    // 2. Pointer access
    Cart* p = &c;

    p->add("Oil", 180);

    cout << "\nPointer Access\n";
    cout << fixed << setprecision(2);
    cout << "Total: " << p->total() << endl;

    // 3. Reference access
    Cart& ref = c;

    ref.add("Sugar", 50);

    cout << "\nReference Access\n";
    cout << "Total: " << ref.total() << endl;

    // 4. Dynamic object using new
    Cart* dynamicCart = new Cart();

    dynamicCart->add("Milk", 40);
    dynamicCart->add("Bread", 30);

    cout << "\nDynamic Object Access\n";
    cout << "Total: " << dynamicCart->total() << endl;

    delete dynamicCart;

    // Array of pointers to Cart objects
    Cart c1, c2, c3;

    c1.add("Rice", 100);
    c2.add("Oil", 200);
    c3.add("Fruits", 300);

    Cart* carts[3] = {&c1, &c2, &c3};

    Cart* highest = carts[0];

    for (int i = 1; i < 3; i++) {
        if (carts[i]->total() > highest->total()) {
            highest = carts[i];
        }
    }

    cout << "\nCart with Highest Total: "
         << highest->total() << endl;

    return 0;
}