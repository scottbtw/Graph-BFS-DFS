#include "DFS.h"
#include <stack>
#include <algorithm>

void dfsRecursive(const Graph& g, int v, std::set<int>& visited, std::vector<int>& order) {
    visited.insert(v);
    order.push_back(v);

    for (int n : g.neighbors(v)) {
        if (!visited.count(n)) {
            dfsRecursive(g, n, visited, order);
        }
    }
}

std::vector<int> dfsIterative(const Graph& g, int start) {
    std::vector<int> order;
    std::set<int> visited;
    std::stack<int> st;

    st.push(start);

    while (!st.empty()) {
        int v = st.top();
        st.pop();

        if (visited.count(v)) continue;
        visited.insert(v);
        order.push_back(v);

        auto neigh = g.neighbors(v);
        std::reverse(neigh.begin(), neigh.end());

        for (int n : neigh)
            if (!visited.count(n))
                st.push(n);
    }
    return order;
}

bool hasCycle(const Graph& g, int v, int parent, std::set<int>& visited) {
    visited.insert(v);

    for (int n : g.neighbors(v)) {
        if (!visited.count(n)) {
            if (hasCycle(g, n, v, visited)) return true;
        }
        else if (n != parent) {
            return true;
        }
    }
    return false;
}

