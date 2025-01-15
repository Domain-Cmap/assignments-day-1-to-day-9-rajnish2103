#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    // Assign unique group IDs for items with no group
    int newGroupId = m;
    for (int i = 0; i < n; ++i) {
        if (group[i] == -1) group[i] = newGroupId++;
    }

    // Graphs and in-degrees for items and groups
    vector<vector<int>> itemGraph(n), groupGraph(newGroupId);
    vector<int> itemIndegree(n, 0), groupIndegree(newGroupId, 0);

    // Build graphs
    for (int i = 0; i < n; ++i) {
        for (int before : beforeItems[i]) {
            itemGraph[before].push_back(i);
            itemIndegree[i]++;
            if (group[i] != group[before]) {
                groupGraph[group[before]].push_back(group[i]);
                groupIndegree[group[i]]++;
            }
        }
    }

    // Topological sort helper
    auto topologicalSort = [](const vector<vector<int>>& graph, vector<int>& indegree) {
        queue<int> q;
        vector<int> order;

        for (int i = 0; i < indegree.size(); ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            order.push_back(node);
            for (int neighbor : graph[node]) {
                if (--indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        return (order.size() == indegree.size()) ? order : vector<int>();
    };

    // Sort groups and items
    vector<int> groupOrder = topologicalSort(groupGraph, groupIndegree);
    vector<int> itemOrder = topologicalSort(itemGraph, itemIndegree);

    if (groupOrder.empty() || itemOrder.empty()) return {};  // Cycle detected

    // Group items by their groups
    unordered_map<int, vector<int>> groupedItems;
    for (int item : itemOrder) {
        groupedItems[group[item]].push_back(item);
    }

    // Merge items based on group order
    vector<int> result;
    for (int grp : groupOrder) {
        for (int item : groupedItems[grp]) {
            result.push_back(item);
        }
    }

    return result;
}
