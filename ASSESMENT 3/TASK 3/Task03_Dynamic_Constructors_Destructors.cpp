#include <iostream>
using namespace std;
 
class Event {
    int rows;
    int seatsPerRow;
    bool** seatMap;
 
public:
    Event(int r, int s) : rows(r), seatsPerRow(s), seatMap(nullptr) {
        if (rows <= 0 || seatsPerRow <= 0) {
            rows = 0;
            seatsPerRow = 0;
            cout << "Event created with an empty seat map\n";
            return;
        }
 
        seatMap = new bool*[rows];
        int createdRows = 0;
 
        try {
            for (; createdRows < rows; ++createdRows) {
                seatMap[createdRows] = new bool[seatsPerRow]{false};
            }
        }
        catch (...) {
            for (int i = 0; i < createdRows; ++i)
                delete[] seatMap[i];
            delete[] seatMap;
            seatMap = nullptr;
            throw;
        }
 
        cout << "Event created: " << rows << " rows, "
             << seatsPerRow << " seats per row\n";
    }
 
    void bookSeat(int row, int seat) {
        if (!seatMap || row < 0 || row >= rows ||
            seat < 0 || seat >= seatsPerRow) {
            cout << "Invalid seat\n";
            return;
        }
 
        if (seatMap[row][seat])
            cout << "Seat already booked\n";
        else {
            seatMap[row][seat] = true;
            cout << "Seat booked\n";
        }
    }
 
    void cancelSeat(int row, int seat) {
        if (!seatMap || row < 0 || row >= rows ||
            seat < 0 || seat >= seatsPerRow) {
            cout << "Invalid seat\n";
            return;
        }
 
        if (!seatMap[row][seat])
            cout << "Seat is not booked\n";
        else {
            seatMap[row][seat] = false;
            cout << "Booking cancelled\n";
        }
    }
 
    ~Event() {
        if (seatMap) {
            for (int i = 0; i < rows; ++i)
                delete[] seatMap[i];
            delete[] seatMap;
        }
        cout << "Event closed. Seat map memory released.\n";
    }
};
 
int main() {
    Event morningShow(3, 5);       // Stack object
    morningShow.bookSeat(1, 2);
    morningShow.cancelSeat(1, 2);
 
    {
        Event specialShow(2, 4);   // Block-scope object
        specialShow.bookSeat(0, 1);
    } // Destructor runs here
 
    Event* eveningShow = new Event(4, 6); // Heap object
    eveningShow->bookSeat(2, 3);
    delete eveningShow;            // Destructor runs here
 
    Event emptyEvent(0, 5);         // Zero-row test
    return 0;
}
