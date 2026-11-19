#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
 
class Book {
    string title;
    string author;
    int copies;
 
    static int validateCopies(int count) {
        if (count < 0)
            throw invalid_argument("Number of copies cannot be negative.");
        return count;
    }
 
public:
    Book() : Book("Unknown", "Unknown", 0) {}
 
    explicit Book(const string& bookTitle)
        : Book(bookTitle, "Unknown", 0) {}
 
    Book(const string& bookTitle, const string& bookAuthor)
        : Book(bookTitle, bookAuthor, 0) {}
 
    Book(const string& bookTitle, const string& bookAuthor, int count)
        : title(bookTitle), author(bookAuthor),
          copies(validateCopies(count)) {}
 
    void display() const {
        cout << "Title: " << title
             << ", Author: " << author
             << ", Copies: " << copies << '\n';
    }
};
 
int main() {
    try {
        Book b1;
        Book b2("C++ Programming");
        Book b3("Data Structures", "Mark Allen", 5);
 
        b1.display();
        b2.display();
        b3.display();
 
        // Uncomment to test invalid copies:
        // Book invalidBook("Test", "Author", -2);
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}
