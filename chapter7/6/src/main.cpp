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
    cout << g.findMaxDepth() << endl;
}