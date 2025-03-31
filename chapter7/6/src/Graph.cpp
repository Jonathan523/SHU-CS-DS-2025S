#include "Graph.hpp"
#include <vector>

Graph::Graph(int n) : n(n), adj(n + 1), vis(n + 1, false) {}

void Graph::addEdge(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < n) {
        adj[i].push_back(j);
    }
}

void Graph::dfs(int current, int depth, int& max_depth)
{
    vis[current] = true;
    max_depth = max(max_depth, depth);
    for (auto& v : adj[current]) {
        if (!vis[v]) {
            dfs(v, depth + 1, max_depth);
        }
    }
    return;
}

int Graph::findMaxDepth()
{
    int overall_max_depth = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int max_depth = 0;
            dfs(i, 2, max_depth);
            overall_max_depth = max(overall_max_depth, max_depth);
        };
    }
    return overall_max_depth;
}