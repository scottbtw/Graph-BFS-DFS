#ifndef DFS_H
#define DFS_H

#include "Graph.h"
#include <vector>
#include <set>

void dfsRecursive(const Graph& g, int v, std::set<int>& visited, std::vector<int>& order);
std::vector<int> dfsIterative(const Graph& g, int start);
bool hasCycle(const Graph& g, int v, int parent, std::set<int>& visited);

#endif
