#include "BalancedBST.hpp"
#include <algorithm>
BalancedBST::BalancedBST(Node* root) : root_(root) { computeHeight(root_); }

// 先算左右子树高度，再设置当前节点的 bf，最后返回当前子树高度
int BalancedBST::computeHeight(Node* node)
{
    if (node == nullptr) {
        return 0;
    }
    int lh = computeHeight(node->left);
    int rh = computeHeight(node->right);
    node->bf = rh - lh;
    return std::max(lh, rh) + 1;
}

// 只沿着 bf > 0 走左子树 / 否则走右子树
int BalancedBST::getHeight() const
{
    int height = 0;
    Node* cur = root_;
    while (cur != nullptr) {
        ++height;
        cur = (cur->bf > 0 ? cur->left : cur->right);
    }
    return ++height;
}