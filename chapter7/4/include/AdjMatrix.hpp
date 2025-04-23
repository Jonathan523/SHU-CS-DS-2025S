// AdjMatrix.hpp
#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using std::cin;
using std::cout;

struct StepRecord
{
    int step;
    int current;
    StepRecord* previous;
    StepRecord(int s, int c, StepRecord* p) : step(s), current(c), previous(p)
    {
    }
};

template <typename T>
class AdjMatrix
{
protected:
    int number;
    T* data;
    int* tag;
    int** edges;
    vector<StepRecord> steplist;

    int
    DFS(int current, int target,
        int remainSteps)  // 和上一题一样，还是在每次准备回溯前把结点重新改为可以访问
    {
        if (remainSteps == 0) {
            return (current == target) ? 1 : 0;
        }
        int count = 0;
        for (int next = 0; next < number; next++) {
            if (edges[current][next] == 1 && tag[next] == 0) {
                tag[next] = 1;  // 标记访问
                count += DFS(next, target, remainSteps - 1);
                tag[next] = 0;  // 回溯解除标记
            }
        }
        return count;
    }

public:
    AdjMatrix(int Number, T* Vertexs, int** Edges)
    {
        number = Number;
        if (number == 0) {
            tag = nullptr;
            data = nullptr;
            edges = nullptr;
            return;
        }
        tag = new int[number];
        data = new T[number];
        edges = new int*[number];
        for (int i = 0; i < number; i++) {
            tag[i] = 0;
            data[i] = Vertexs[i];
            edges[i] = new int[number];
            for (int j = 0; j < number; j++) {
                edges[i][j] = Edges[i][j];
            }
        }
    }

    ~AdjMatrix()
    {
        if (number == 0) {
            return;
        }
        delete[] tag;
        delete[] data;
        for (int i = 0; i < number; i++) {
            delete[] edges[i];
        }
    }

    int FindPath(int i, int j, int k)
    {
        if (i < 0 || i >= number || j < 0 || j >= number || k < 0 ||
            k >= number) {
            // cout << "输入的下标不合法" << '\n';
            return 0;
        }
        int waynum = 0;
        tag[i] = 1;
        return DFS(i, j, k);
    }
};