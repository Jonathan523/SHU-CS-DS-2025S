#pragma once

class BalancedBST
{
public:
    // 每个节点只保存平衡因子 bf 和左右子指针
    struct Node
    {
        int bf;
        Node* left;
        Node* right;
        // 默认构造把 bf 设为 0，孩子设为 nullptr
        Node() : bf(0), left(nullptr), right(nullptr) {}
        ~Node() = default;
    };

    // 传入一个已经搭好 left/right 指针的子树根，
    // 构造时自动做一次后序遍历计算所有节点的 bf
    explicit BalancedBST(Node* root);
    ~BalancedBST() = default;

    // 基于节点上的 bf，沿着”高的一边“一路向下，计算树高
    int getHeight() const;

private:
    Node* root_;
    // 后序遍历返回子树高度并写入 node->bf
    int computeHeight(Node* node);
};
