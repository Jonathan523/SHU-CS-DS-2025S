#include "Graph.hpp"
#include <iostream>
#include <vector>
using namespace std;

Graph::Graph(int n) : n(n), adj(n) {}

void Graph::addEdge(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < n) {
        adj[i].push_back(j);
    }
}

bool Graph::dfs(int current, int target, vector<bool>& visited,
                vector<int>& path)
{
    visited[current] = true;
    path.push_back(current);
    if (current == target) {
        return true;
    }
    for (auto& v : adj[current]) {
        if (!visited[v]) {
            if (dfs(v, target, visited, path)) {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

void Graph::printPath(int i, int j)
{
    vector<bool> visited(n, false);
    vector<int> path;
    if (dfs(i, j, visited, path)) {
        cout << "存在从 " << i << " 到 " << j << " 的路径：" << endl;
        for (size_t idx = 0; idx < path.size(); idx++) {
            cout << path[idx];
            if (idx != path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    } else {
        cout << "不存在从 " << i << " 到 " << j << " 的路径：" << endl;
    }
}
