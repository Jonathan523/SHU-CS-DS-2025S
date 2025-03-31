#pragma once
#include <vector>
using namespace std;

class Graph
{
public:
    Graph(int n);
    ~Graph() = default;
    void addEdge(int i, int j);
    void printPath(int i, int j);

private:
    int n;
    vector<vector<int>> adj;
    bool dfs(int current, int target, vector<bool>& visited, vector<int>& path);
};