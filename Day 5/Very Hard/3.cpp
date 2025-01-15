#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int maxVal;

public:
    FenwickTree(int n) : tree(n + 1, 0), maxVal(n) {}

    void update(int index, int delta) {
        while (index <= maxVal) {
            tree[index] += delta;
            index += index & (-index);
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & (-index);
        }
        return sum;
    }
};

int createSortedArray(vector<int>& instructions) {
    const int MOD = 1e9 + 7;
    int maxVal = *max_element(instructions.begin(), instructions.end());
    FenwickTree fenwick(maxVal);
    long long cost = 0;

    for (int i = 0; i < instructions.size(); ++i) {
        int leftCost = fenwick.query(instructions[i] - 1);
        int rightCost = i - fenwick.query(instructions[i]);
        cost += min(leftCost, rightCost);
        fenwick.update(instructions[i], 1);
        cost %= MOD;
    }
    return cost;
}
