#include "BalancedBST.hpp"
#include <algorithm>
// 构造函数里一进来就对整棵树 run 一次 computeHeight，
// 把每个节点的 bf 都算好
BalancedBST::BalancedBST(Node* root) : root_(root) { computeHeight(root_); }

// 后序遍历：先算左右子树高度，再设置当前节点的 bf，最后返回当前子树高度
int BalancedBST::computeHeight(Node* node)
{
    if (node == nullptr) {
        return 0;
    }
    int lh = computeHeight(node->left);
    int rh = computeHeight(node->right);
    node->bf = lh - rh;
    return std::max(lh, rh) + 1;
}

// 利用事先算好的 bf，只沿着”bf>0 走左子树 / 否则走右子树“
// 从根到叶子计步，就得到了树高
int BalancedBST::getHeight() const
{
    int height = 0;
    Node* cur = root_;
    while (cur != nullptr) {
        ++height;
        cur = (cur->bf > 0 ? cur->left : cur->right);
    }
    return height;
}
