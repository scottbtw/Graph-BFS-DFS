#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>

class Graph {
private:
    std::map<int, std::vector<int>> adj;
    bool directed;
    int edges;

public:
    Graph(bool directed = false);

    void addVertex(int v);
    void addEdge(int u, int v);

    std::vector<int> neighbors(int v) const;

    int V() const;
    int E() const;

    bool isDirected() const;
};

#endif

