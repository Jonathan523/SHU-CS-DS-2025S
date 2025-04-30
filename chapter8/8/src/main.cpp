#include <iostream>
struct TreeNode {
    int key;     
    TreeNode* left;
    TreeNode* right;

    TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

void outputMax(TreeNode* root, int x) {
    if (root == nullptr) {
        return;
    }

    outputMax(root->right, x);

    if (root->key >= x) {
        std::cout << root->key << " ";
        outputMax(root->left, x);
    }
}

TreeNode* insert(TreeNode* root, int k) {
    if (root == nullptr) {
        return new TreeNode(k);
    }
    if (k < root->key) {
        root->left = insert(root->left, k);
    } else if (k > root->key) {
        root->right = insert(root->right, k);
    } else {
        root->key = k;
    }
    return root;
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = nullptr;

    std::cout << "请输入二叉排序树的节点值（输入 -1 表示结束）：" << '\n';
    int value;
    while (true) {
        std::cin >> value;
        if (value == -1) {
            break;
        }
        root = insert(root, value);
    }

    int x_value;
    std::cout << "请输入 x 值：" << '\n';
    std::cin >> x_value;
    std::cout << "输出关键字 >= " << x_value << " 的数据元素 (从大到小):" << '\n';
    outputMax(root, x_value);
    std::cout << '\n';

    // 清理内存
    deleteTree(root);

    return 0;
}

//        10 
//      /   \
//     5     15
//    / \    / \
//   3   7 12   18
//  /
// 2