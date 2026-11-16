#include <iostream>
using namespace std;

int& highestMark(int marks[], int n) {
    int highest = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[highest]) highest = i;
    return marks[highest];
}

// This function is intentionally unsafe. Do not call it.
// A compiler should warn because it returns a reference to a local variable.
int& dangerousLocalReference() {
    int value = 50;
    return value; // dangling reference: undefined behaviour if used
}

const int& highestMarkConst(const int marks[], int n) {
    int highest = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[highest]) highest = i;
    return marks[highest];
}

int highestMarkCopy(const int marks[], int n) {
    int highest = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[highest]) highest = i;
    return marks[highest];
}

int main() {
    int marks[] = {78, 92, 85, 88};
    int n = 4;

    cout << "Highest mark: " << highestMark(marks, n) << '\n';
    highestMark(marks, n) += 2;
    cout << "After moderation: " << marks[1] << '\n';

    cout << "Const reference: " << highestMarkConst(marks, n) << '\n';
    cout << "Returned copy: " << highestMarkCopy(marks, n) << '\n';
    return 0;
}
