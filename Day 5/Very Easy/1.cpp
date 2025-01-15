#include <iostream>
#include <vector>
using namespace std;

int searchNumber(int k, const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == k) {
            return i + 1; // Return 1-based index
        }
    }
    return -1; // Element not found
}

int main() {
    int k = 16;
    vector<int> arr = {9, 7, 16, 16, 4};
    cout << searchNumber(k, arr) << endl;
    return 0;
}
