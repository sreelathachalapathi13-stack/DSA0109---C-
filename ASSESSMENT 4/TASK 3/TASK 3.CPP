#include <iostream>
#include <string>
using namespace std;

class Address {
    string city;
    int pin;

public:
    Address(string c, int p) : city(c), pin(p) {
        cout << "Address Constructor" << endl;
    }

    string str() const {
        return city + "-" + to_string(pin);
    }

    ~Address() {
        cout << "Address Destructor" << endl;
    }
};

class Course {
    string courseName;

public:
    Course(string c) : courseName(c) {
        cout << "Course Constructor" << endl;
    }

    ~Course() {
        cout << "Course Destructor" << endl;
    }
};

class Person {
protected:
    string name;
    int age;
    Address home;

public:
    Person(string n, int a, string city, int pin)
        : name(n), age(a), home(city, pin) {
        cout << "Person Constructor" << endl;
    }

    virtual ~Person() {
        cout << "Person Destructor" << endl;
    }
};

class Student : virtual public Person {
protected:
    long long regNo;
    Course course;

public:
    Student(string n, int a, long long r,
            string city, int pin, string c)
        : Person(n, a, city, pin),
          regNo(r), course(c) {
        cout << "Student Constructor" << endl;
    }

    void print() const {
        cout << regNo << " " << name
             << " (" << age << ") "
             << home.str() << endl;
    }

    ~Student() override {
        cout << "Student Destructor" << endl;
    }
};

class Staff : virtual public Person {
protected:
    string department;

public:
    Staff(string n, int a, string city,
          int pin, string d)
        : Person(n, a, city, pin), department(d) {
        cout << "Staff Constructor" << endl;
    }

    ~Staff() override {
        cout << "Staff Destructor" << endl;
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int a, long long r,
                      string city, int pin,
                      string c, string d)
        : Person(n, a, city, pin),
          Student(n, a, r, city, pin, c),
          Staff(n, a, city, pin, d) {
        cout << "TeachingAssistant Constructor" << endl;
    }

    ~TeachingAssistant() override {
        cout << "TeachingAssistant Destructor" << endl;
    }
};

int main() {
    cout << "\nSTUDENT OBJECT\n";

    {
        Student s("Kavya", 19, 192311001,
                  "Salem", 636001, "C++");

        s.print();
    }

    cout << "\nSTAFF OBJECT\n";

    {
        Staff st("Ravi", 40, "Chennai",
                 600001, "CSE");
    }

    cout << "\nTEACHING ASSISTANT OBJECT\n";

    {
        TeachingAssistant ta(
            "Arun", 22, 192311002,
            "Madurai", 625001,
            "AIML", "Computer Science"
        );

        ta.print();
    }

    return 0;
}