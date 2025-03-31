/*
    题目：基于图的深度优先搜索策略编写一算法，判别以邻接表方式存储的有向图中是否存在由顶点vi到顶点vj的路径（i!=j）
*/

#include "Graph.hpp"
#include <iostream>

using namespace std;

int main()
{
    int n, e;
    // cout << "请输入顶点数和边数：" << endl;
    cin >> n >> e;
    Graph g(n);
    for (int k = 0; k < e; k++) {
        int u, v;
        // cout << "请输入边的起点和终点：" << endl;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    int m;
    cin >> m;
    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        g.printPath(i, j);
    }
    return 0;
}
