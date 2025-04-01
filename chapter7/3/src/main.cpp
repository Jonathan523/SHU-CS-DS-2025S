#include "AdjTable.hpp"
#include <iostream>

using namespace std;

#define MAX 1000

int main()
{
    int number, edge, A;
    int* JieDianLink;
    bool ifFind = false;
    cin >> number;
    JieDian<int>* JieDianTable = new JieDian<int>[number];
    for (int i = 0; i < number; i++) {
        cin >> JieDianTable[i].data;
        JieDianTable[i].BianLink = nullptr;
    }
    cin >> edge;
    for (int i = 0; i < edge; i++) {
        int a, b;
        cin >> a >> b;
        Bian<int>* p = new Bian<int>;
        p->index = b;
        p->next = JieDianTable[a].BianLink;
        JieDianTable[a].BianLink = p;
    }
    AdjTable<int> graph(number, JieDianTable);
    cin >> A;
    JieDianLink = new int[A];
    ifFind = graph.FindPath(A, JieDianLink);
    if (ifFind) {
        cout << "存在路径" << endl;
        graph.ShowPath(JieDianLink, A);
    } else {
        cout << "不存在路径" << endl;
    }
    return 0;
}