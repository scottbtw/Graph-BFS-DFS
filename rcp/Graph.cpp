#include "Graph.h"
#include <algorithm>

Graph::Graph(bool directed) : directed(directed), edges(0) {}

void Graph::addVertex(int v) {
    if (adj.find(v) == adj.end())
        adj[v] = std::vector<int>();
}

void Graph::addEdge(int u, int v) {
    addVertex(u);
    addVertex(v);

    adj[u].push_back(v);
    std::sort(adj[u].begin(), adj[u].end()); // детерминизм

    if (!directed) {
        adj[v].push_back(u);
        std::sort(adj[v].begin(), adj[v].end());
    }

    edges++;
}

std::vector<int> Graph::neighbors(int v) const {
    auto it = adj.find(v);
    if (it == adj.end()) return {};
    return it->second;
}

int Graph::V() const {
    return adj.size();
}

int Graph::E() const {
    return edges;
}

bool Graph::isDirected() const {
    return directed;
}

