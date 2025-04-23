#pragma once
#define minNum 0xc0c0c0c0
#include <iostream>
using namespace std;

template <typename T>
struct TreeNode
{
    T data;
    int index;
    TreeNode<T>* leftChild;
    TreeNode<T>* rightChild;
    TreeNode(T Data, int Index, TreeNode<T>* LeftChild = nullptr,
             TreeNode<T>* RightChild = nullptr)
        : data(Data), index(Index), leftChild(LeftChild), rightChild(RightChild)
    {
    }
};

template <typename T>
class BinaryTree
{
protected:
    int number;
    TreeNode<T>* root;
    TreeNode<T>* findByIndex(TreeNode<T>* curNode, int index, bool& ifFind)
    {
        if (curNode->index == index) {
            ifFind = true;
            return curNode;
        }
        TreeNode<T>* target;
        if (curNode->leftChild != nullptr) {
            target = findByIndex(curNode->leftChild, index, ifFind);
            if (ifFind)
            {
                return target;
            }
        }
        if (curNode->rightChild != nullptr) {
            target = findByIndex(curNode->rightChild, index, ifFind);
            if (ifFind)
            {
                return target;
            }
        }
        return nullptr;
    }
    bool inOrder(TreeNode<T>* curNode, T& curMax)
    {
        if (curNode->leftChild != nullptr) {
            if (inOrder(curNode->leftChild, curMax) == false)
            {
                return false;
            }
        }
        if (curNode->data < curMax)
        {
            return false;
        }
        curMax = curNode->data;
        if (curNode->rightChild != nullptr) {
            if (inOrder(curNode->rightChild, curMax) == false)
            {
                return false;
            }
        }
        return true;
    }

public:
    BinaryTree(T rootData)
    {
        root = new TreeNode<T>(rootData, 0);
        number = 1;
    }
    void addChild(int parent, T data, bool LorR)
    {
        bool ifFind = false;
        TreeNode<T>* parentNode = findByIndex(root, parent, ifFind);
        if (LorR) {
            parentNode->leftChild = new TreeNode<T>(data, number);
        } else {
            parentNode->rightChild = new TreeNode<T>(data, number);
        }
        number++;
    }
    bool ifSortTree()
    {
        int min = minNum;
        return inOrder(root, min);
    }
};