#include <cstring>
#include <iostream>
using namespace std;
 
class Text {
    char* data;
 
public:
    Text(const char* value = "") {
        if (!value)
            value = "";
        data = new char[strlen(value) + 1];
        strcpy(data, value);
    }
 
    // Deep-copy constructor
    Text(const Text& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }
 
    // Copy assignment operator
    Text& operator=(const Text& other) {
        if (this != &other) {
            char* newData = new char[strlen(other.data) + 1];
            strcpy(newData, other.data);
            delete[] data;
            data = newData;
        }
        return *this;
    }
 
    // Concatenation
    Text operator+(const Text& other) const {
        size_t newLength = strlen(data) + strlen(other.data);
        char* buffer = new char[newLength + 1];
 
        strcpy(buffer, data);
        strcat(buffer, other.data);
 
        Text result(buffer);
        delete[] buffer;
        return result;
    }
 
    bool operator==(const Text& other) const {
        return strcmp(data, other.data) == 0;
    }
 
    bool operator!=(const Text& other) const {
        return !(*this == other);
    }
 
    friend ostream& operator<<(ostream& out, const Text& text) {
        out << text.data;
        return out;
    }
 
    ~Text() {
        delete[] data;
    }
};
 
int main() {
    Text first("Hello ");
    Text second("World");
    Text third("!");
 
    Text message = first + second + third;
    cout << "Message: " << message << '\n';
 
    Text copy = message;
    cout << "Copy: " << copy << '\n';
 
    Text empty;
    cout << "Empty text: [" << empty << "]\n";
 
    cout << boolalpha;
    cout << "message == copy: " << (message == copy) << '\n';
    cout << "message != first: " << (message != first) << '\n';
 
    copy = copy; // Self-assignment test
    cout << "After self-assignment: " << copy << '\n';
    return 0;
}
