#include "AdjTable.hpp"
#include <iostream>
using namespace std;

template <typename T>
AdjTable<T>::AdjTable(int Number, JieDian<T>* Table)
{
    number = Number;
    if (number == 0) {
        tag = nullptr;
        JieDianTable = nullptr;
        return;
    }
    tag = new int[number];
    JieDianTable = new JieDian<T>[number];
    for (int i = 0; i < number; i++) {
        tag[i] = 0;
        JieDianTable[i] = Table[i];
    }
}

template <typename T>
AdjTable<T>::~AdjTable()
{
    if (number == 0) {
        return;
    }
    delete[] tag;
    Bian<T>* p = nullptr;
    for (int i = 0; i < number; i++) {
        p = JieDianTable[i].BianLink;
        while (p != nullptr && p->next != nullptr) {
            JieDianTable[i].BianLink = p->next;
            delete p;
            p = JieDianTable[i].BianLink;
        }
    }
    delete[] JieDianTable;
}

template <typename T>
void AdjTable<T>::DFS(int Index, int length, int* JieDianLink, int A,
                      bool& ifFind)
{
    if (length == A) {
        ifFind = true;
        return;
    }
    tag[Index] = length;
    Bian<T>* p = JieDianTable[Index].BianLink;
    while (p != nullptr) {
        if (tag[p->index] == 0) {
            DFS(p->index, length + 1, JieDianLink, A, ifFind);
            if (ifFind) {
                JieDianLink[length] = Index;
                return;
            }
        }
        p = p->next;
    }
    return;
}

template <typename T>
bool AdjTable<T>::FindPath(int A, int* JieDianLink)
{
    if (A < 0 || A >= number) {
        cout << "输入的顶点不合法" << endl;
        return false;
    }
    int i = 0, j = 0;
    bool ifFind = false;
    JieDianLink = new int[A];
    while (ifFind = false && i < number) {
        for (j = 0; j < number; j++) {
            tag[j] = 0;
        }
        DFS(i, 1, JieDianLink, A, ifFind);
        i++;
    }
    return ifFind;
}

template <typename T>
void AdjTable<T>::ShowPath(int* JieDianLink, int A)
{
    for (int i = 0; i < A; i++) {
        cout << JieDianTable[JieDianLink[i]].data << " ";
    }
    cout << endl;
}
