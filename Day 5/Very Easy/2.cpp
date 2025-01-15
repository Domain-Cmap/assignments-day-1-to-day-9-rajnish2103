#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortedArraySearch(int k, const vector<int>& arr) {
    return binary_search(arr.begin(), arr.end(), k); // Use STL binary search
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 6};
    int k = 6;
    cout << (sortedArraySearch(k, arr) ? "true" : "false") << endl;
    return 0;
}
