#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
 
class Time {
    int seconds;
 
public:
    explicit Time(int totalSeconds = 0) : seconds(totalSeconds) {
        if (seconds < 0)
            seconds = 0;
    }
 
    // Prefix increment
    Time& operator++() {
        ++seconds;
        return *this;
    }
 
    // Postfix increment
    Time operator++(int) {
        Time old = *this;
        ++seconds;
        return old;
    }
 
    bool operator==(const Time& other) const {
        return seconds == other.seconds;
    }
 
    bool operator<(const Time& other) const {
        return seconds < other.seconds;
    }
 
    void display() const {
        int h = seconds / 3600;
        int m = (seconds % 3600) / 60;
        int s = seconds % 60;
        cout << h << ':' << (m < 10 ? "0" : "") << m
             << ':' << (s < 10 ? "0" : "") << s << '\n';
    }
};
 
class Playlist {
    vector<string> tracks;
 
public:
    Playlist(initializer_list<string> list) : tracks(list) {}
 
    string& operator[](int index) {
        if (index < 0 || index >= static_cast<int>(tracks.size()))
            throw out_of_range("Playlist index out of range");
        return tracks[index];
    }
 
    const string& operator[](int index) const {
        if (index < 0 || index >= static_cast<int>(tracks.size()))
            throw out_of_range("Playlist index out of range");
        return tracks[index];
    }
 
    int size() const {
        return static_cast<int>(tracks.size());
    }
};
 
int main() {
    Time t(5);
    Time a = t++;
    Time b = ++t;
 
    cout << "a = ";
    a.display();
    cout << "b = ";
    b.display();
    cout << "t = ";
    t.display();
 
    Time lastSecond(3599);
    ++lastSecond;
    cout << "After minute rollover: ";
    lastSecond.display();
 
    Playlist playlist{"Song One", "Song Two", "Song Three"};
    cout << "First track: " << playlist[0] << '\n';
    playlist[1] = "Updated Song";
    cout << "Second track: " << playlist[1] << '\n';
 
    const Playlist& readOnlyPlaylist = playlist;
    cout << "Third track: " << readOnlyPlaylist[2] << '\n';
 
    try {
        cout << playlist[-1] << '\n';
    }
    catch (const out_of_range& e) {
        cout << e.what() << '\n';
    }
 
    try {
        cout << playlist[playlist.size()] << '\n';
    }
    catch (const out_of_range& e) {
        cout << e.what() << '\n';
    }
    return 0;
}
