#pragma once
#include <vector>
using namespace std;

class Graph
{
public:
    Graph(int n);
    ~Graph(){};
    void addEdge(int i, int j);
    int findMaxDepth();

private:
    int n;
    vector<vector<int> > adj;
    vector<bool> vis;
    void dfs(int current, int depth, int& max_depth);
};