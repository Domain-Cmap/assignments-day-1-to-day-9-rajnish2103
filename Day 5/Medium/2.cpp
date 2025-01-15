#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    auto binarySearch = [&](bool findFirst) {
        int left = 0, right = nums.size() - 1, result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                result = mid;
                if (findFirst) right = mid - 1;  // Search left half
                else left = mid + 1;            // Search right half
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    };

    int first = binarySearch(true);
    if (first == -1) return {-1, -1};  // Target not found
    int last = binarySearch(false);

    return {first, last};
}
