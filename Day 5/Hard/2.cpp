#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<vector<int>>& mat, int k) {
    auto mergeRows = [](vector<int>& a, vector<int>& b, int k) {
        priority_queue<int> maxHeap;
        for (int x : a) {
            for (int y : b) {
                int sum = x + y;
                maxHeap.push(sum);
                if (maxHeap.size() > k) maxHeap.pop();
            }
        }

        vector<int> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top());
            maxHeap.pop();
        }
        sort(result.begin(), result.end());
        return result;
    };

    vector<int> current = mat[0];
    for (int i = 1; i < mat.size(); ++i) {
        current = mergeRows(current, mat[i], k);
    }

    return current[k - 1];
}
