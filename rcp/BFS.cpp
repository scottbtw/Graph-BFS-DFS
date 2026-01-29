#include "BFS.h"
#include <queue>
#include <set>
#include <algorithm>

BFSResult bfs(const Graph& g, int start) {
    BFSResult res;
    std::queue<int> q;
    std::set<int> visited;

    q.push(start);
    visited.insert(start);
    res.distance[start] = 0;
    res.parent[start] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.order.push_back(u);

        for (int v : g.neighbors(u)) {
            if (!visited.count(v)) {
                visited.insert(v);
                q.push(v);
                res.distance[v] = res.distance[u] + 1;
                res.parent[v] = u;
            }
        }
    }
    return res;
}

std::vector<int> shortestPath(const Graph& g, int s, int t) {
    BFSResult r = bfs(g, s);
    if (!r.parent.count(t)) return {};

    std::vector<int> path;
    for (int cur = t; cur != -1; cur = r.parent[cur])
        path.push_back(cur);

    std::reverse(path.begin(), path.end());
    return path;
}
