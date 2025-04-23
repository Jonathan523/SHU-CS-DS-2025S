/*
    题目：编写求有向无环图中最长路径的算法。
*/

#include "Graph.hpp"
#include <iostream>

int main()
{
    int n, e;
    cin >> n >> e;
    Graph g(n);
    for (int k = 0; k < e; k++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << g.findMaxDepth() << '\n';
}