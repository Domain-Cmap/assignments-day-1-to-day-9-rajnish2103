#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    int moves = 0;
    for (int i = 0; i < seats.size(); i++) {
        moves += abs(seats[i] - students[i]); // Calculate the absolute difference
    }
    return moves;
}

int main() {
    vector<int> seats = {3, 1, 5};
    vector<int> students = {2, 7, 4};
    cout << minMovesToSeat(seats, students) << endl;
    return 0;
}
