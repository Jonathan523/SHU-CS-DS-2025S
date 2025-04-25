/*
第8章第7题
请编写一个判别给定二叉树是否为二叉排序树的算法，设二叉树用二叉链表存储。
*/
#include "binaryTree.hpp"

int main()
{
    int data, parent, lorR, number;
    bool LorR;
    cout << "请输入节点个数，以及第0个节点（根节点）的数据\n";
    cin >> number >> data;
    BinaryTree<int> Tree(data);
    cout << "请依次输入接下来第个节点的数据，父节点标号，以及是左孩子还是右孩子"
            "（1表示左孩子，0表示右孩子）\n";
    for (int i = 1; i < number; i++) {
        cin >> data >> parent >> lorR;
        if (lorR == 1)
        {
            LorR = true;
        }
        else
        {
            LorR = false;
        }
        Tree.addChild(parent, data, LorR);
    }
    if (Tree.ifSortTree())
    {
        cout << "你输入的二叉树是二叉排序树\n";
    }
    else
    {
        cout << "你输入的二叉树不是二叉排序树\n";
    }
        return 0;
}