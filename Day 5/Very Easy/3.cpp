#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findTargetIndices(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end()); // Sort the array
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            result.push_back(i); // Collect indices of the target
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;
    vector<int> indices = findTargetIndices(nums, target);
    
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}
