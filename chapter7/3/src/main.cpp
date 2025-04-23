// main.cpp
/*
第3题：编写一算法，判断以邻接表方式存储的无向图中是否存在一条长度为A的简单路径
*/
#include "AdjTable.hpp"
int main()
{
    int number = 6, A;
    char Vertexs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int Edges[6][6] = {{0, 1, 1, 0, 1, 1}, {1, 0, 0, 1, 1, 0},
                       {1, 0, 0, 1, 0, 1}, {0, 1, 1, 0, 1, 1},
                       {1, 1, 0, 1, 0, 1}, {1, 0, 1, 1, 1, 0}};

    int* edge_ptrs[6];
    for (int i = 0; i < 6; i++) {
        edge_ptrs[i] = Edges[i];  // 每行首地址存入指针数组
    }

    AdjTable<char> graph(number, Vertexs, edge_ptrs);
    cout << "请输入A：";
    cin >> A;
    bool ifFind = graph.FindPath(A);
    return 0;
}