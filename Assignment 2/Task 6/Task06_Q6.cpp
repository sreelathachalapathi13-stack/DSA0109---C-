#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
private:
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

inline int minutesBetween(const Time& a, const Time& b) {
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;
    return abs(first - second);
}

inline bool earlier(const Time& a, const Time& b) {
    if (a.h != b.h) return a.h < b.h;
    return a.m < b.m;
}

int main() {
    Time departure(9, 45), arrival(13, 10);
    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';

    Time t1(11, 50), t2(12, 10);
    cout << minutesBetween(t1, t2) << ' '
         << earlier(t1, t2) << '\n';

    Time same(8, 30);
    cout << minutesBetween(same, same) << ' '
         << earlier(same, same) << '\n';
    return 0;
}
