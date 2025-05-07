// 假设平衡二叉树中每个结点都标明了该节点的平衡因子bf，请试设计一个算法，利用平衡因子计算二叉树的高度
#include "BalancedBST.hpp"
#include <iostream>


int main()
{
    //       o
    //      / \
    //     o   o
    //    / \   \
    //   o   o   o
    //  / \       \
    // o   o       o
    std::cout << "       o" << '\n'
              << "      / \\\n"
              << "     o   o\n"
              << "    / \\   \\\n"
              << "   o   o   o\n"
              << "  / \\       \\\n"
              << " o   o       o\n";
    auto* root = new BalancedBST::Node();
    root->left = new BalancedBST::Node();
    root->right = new BalancedBST::Node();
    root->left->left = new BalancedBST::Node();
    root->left->right = new BalancedBST::Node();
    root->right->right = new BalancedBST::Node();
    root->right->right->left = new BalancedBST::Node();
    root->left->left->left = new BalancedBST::Node();
    root->right->left = new BalancedBST::Node();
    
    root->left->left->right = new BalancedBST::Node();
    root->right->right->right = new BalancedBST::Node();

    BalancedBST bst(root);

    std::cout << "这棵树的高度是: " << bst.getHeight() << '\n';

    return 0;
}
