#pragma once

template <typename T>
struct Bian
{
    int index;
    Bian<T>* next;
};

template <typename T>
struct JieDian
{
    T data;
    Bian<T>* BianLink;
};

template <typename T>
class AdjTable
{
protected:
    int number;
    int* tag;
    JieDian<T>* JieDianTable;
    void DFS(int Index, int length, int* JieDianLink, int A,
             bool& ifFind);  // 暴改过的DFS，用深度优先搜索的思想实现寻找路径

public:
    AdjTable(int Number = 0, JieDian<T>* Table = nullptr);
    ~AdjTable();
    bool FindPath(int A, int* JieDianIndex);  // 寻找题目要求的路径
    void ShowPath(int* JieDianIndex, int A);  // 显示路径
};