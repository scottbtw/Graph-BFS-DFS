#include <iostream>
#include "Graph.h"
#include "BFS.h"
#include "DFS.h"

int main() {
    Graph g(false);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    auto bfsRes = bfs(g, 0);
    std::cout << "BFS order: ";
    for (int v : bfsRes.order) std::cout << v << " ";

    auto path = shortestPath(g, 0, 5);
    std::cout << "\nShortest path 0->5: ";
    for (int v : path) std::cout << v << " ";

    std::set<int> visited;
    std::cout << "\nHas cycle: "
              << (hasCycle(g, 0, -1, visited) ? "Yes" : "No");

    return 0;
}

