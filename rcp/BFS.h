#ifndef BFS_H
#define BFS_H

#include "Graph.h"
#include <vector>
#include <map>

struct BFSResult {
    std::vector<int> order;
    std::map<int, int> distance;
    std::map<int, int> parent;
};

BFSResult bfs(const Graph& g, int start);
std::vector<int> shortestPath(const Graph& g, int s, int t);

#endif
