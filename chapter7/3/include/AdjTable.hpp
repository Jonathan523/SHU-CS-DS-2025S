// AdjTable.hpp
#pragma once
#include <iostream>
using std::cout;
using std::cin;
template <typename T>
struct Edge
{
    int index;
    Edge<T>* next;
    Edge(int index, Edge<T>* next) : index(index), next(next) {}
};

template <typename T>
struct Vertex
{
    T data;
    Edge<T>* EdgeLink;
    Vertex() : data(NULL), EdgeLink(nullptr) {}
};

template <typename T>
class AdjTable
{
protected:
    int number;
    int* tag;
    Vertex<T>* VertexTable;
    void DFS(int Index, int length, int* VertexLink, int A, bool& ifFind)
    {
        VertexLink[length] = Index;
        tag[Index] = 1;
        if (length == A) {

            ifFind = true;
            return;
        }
        Edge<T>* p = VertexTable[Index].EdgeLink;
        while (!ifFind && p != nullptr) {
            if (tag[p->index] == 0) {
                DFS(p->index, length + 1, VertexLink, A, ifFind);
                tag[p->index] = 0;
            }
            p = p->next;
        }
    }  // 暴改过的DFS，用深度优先搜索的思想实现寻找路径

    void ShowPath(int* VertexLink, int A)
    {
        for (int i = 0; i <= A; i++) {
            cout << VertexLink[i] << " ";
        }
        cout << '\n';
    }
    // 显示路径

public:
    AdjTable(int Number, T* Vertexs, int** Table)
    {
        number = Number;
        if (number == 0) {
            tag = nullptr;
            VertexTable = nullptr;
            return;
        }
        tag = new int[number];
        VertexTable = new Vertex<T>[number];
        for (int i = 0; i < number; i++) {
            tag[i] = 0;
            VertexTable[i].data = Vertexs[i];
            for (int j = 0; j < number; j++) {
                if (Table[i][j] == 1) {
                    VertexTable[i].EdgeLink =
                        new Edge<T>(j, VertexTable[i].EdgeLink);
                }
            }
        }
    }
    ~AdjTable()
    {
        if (number == 0) {
            return;
        }
        delete[] tag;
        Edge<T>* p = nullptr;
        for (int i = 0; i < number; i++) {
            p = VertexTable[i].EdgeLink;
            while (p != nullptr && p->next != nullptr) {
                VertexTable[i].EdgeLink = p->next;
                delete p;
                p = VertexTable[i].EdgeLink;
            }
        }
        delete[] VertexTable;
    }
    bool FindPath(int A)
    {
        if (A < 0 || A >= number) {
            cout << "不存在路径" << '\n';
            return false;
        }
        int i = 0, j = 0;
        bool ifFind = false;
        int* VertexLink = new int[A + 1];
        while (ifFind == false && i < number) {
            for (j = 0; j < number; j++) {
                tag[j] = 0;
            }
            DFS(i, 0, VertexLink, A, ifFind);
            i++;
        }
        if (ifFind) {
            cout << "存在路径" << '\n';
            ShowPath(VertexLink, A);
        } else {
            cout << "不存在路径" << '\n';
        }
        return ifFind;
    }  // 寻找题目要求的路径
};