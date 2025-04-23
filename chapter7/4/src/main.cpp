// main.cpp
/*
第7章第4题：编写一算法，在以邻接矩阵方式存储的有向图G中求顶点i到j的不含回路的，长度为k的路径数
*/
#include "AdjMatrix.hpp"

int main()
{
    int vertexs[7] = {0, 1, 2, 3, 4, 5, 6};
    int edges[7][7] = {{0, 1, 0, 1, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 1, 0, 0},
                       {0, 1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 1},
                       {0, 0, 0, 0, 0, 0, 0}};

    int* edge_ptrs[7];
    for (int i = 0; i < 7; i++) {
        edge_ptrs[i] = edges[i];  // 每行首地址存入指针数组
    }

    AdjMatrix<int> graph(7, vertexs, edge_ptrs);

    int i, j, k;
    cout << "请依次输入目标节点i和j，以及路径长度k：";
    cin >> i >> j >> k;
    // cout << i << ' ' << j << ' ' << k << '\n';
    cout << "从顶点" << i << "到顶点" << j << "的无回路路径数为："
         << graph.FindPath(i, j, k) << '\n';
}
