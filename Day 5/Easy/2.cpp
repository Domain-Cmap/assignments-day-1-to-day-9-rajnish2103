#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = nums[i] * nums[i]; // Square each element
    }
    sort(nums.begin(), nums.end()); // Sort the array
    return nums;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sortedSquares(nums);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
