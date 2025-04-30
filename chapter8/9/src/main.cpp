#include <iostream>
#include <algorithm>

struct Node {
    int data;    
    Node *left;  
    Node *right; 
    int lsize;   
    int height;  

    Node(int val) : data(val), left(nullptr), right(nullptr), lsize(1), height(1) {}
};

int getHeight(Node* node) {
    if (node == nullptr) { return 0;
}
    return node->height;
}

int getBalance(Node* node) {
    if (node == nullptr) { return 0;
}
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    y->lsize = ((y->left != nullptr) ? y->left->lsize : 0) + 1;
    x->lsize = ((x->left != nullptr) ? x->left->lsize : 0) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    x->lsize = ((x->left != nullptr) ? x->left->lsize : 0) + 1;
    y->lsize = ((y->left != nullptr) ? y->left->lsize : 0) + 1;

    return y;
}

Node* insert(Node* node, int key) {
    if (node == nullptr) { return new Node(key);
}

    if (key < node->data) {
        node->left = insert(node->left, key);
    } else if (key > node->data) {
        node->right = insert(node->right, key);
    } else {
        return node; // 重复值不插入
    }

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    node->lsize = ((node->left != nullptr) ? node->left->lsize : 0) + 1;

    int balance = getBalance(node);

    // LL
    if (balance > 1 && key < node->left->data) {
        return rightRotate(node);
    }
    // RR
    if (balance < -1 && key > node->right->data) {
        return leftRotate(node);
    }
    // LR
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RL
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int calculateSubtreeSize(Node* node) {
    if (node == nullptr) { return 0;
}
    return calculateSubtreeSize(node->left) + calculateSubtreeSize(node->right) + 1;
}

void updateAllLSizes(Node* node) {
    if (node == nullptr) { return;
}
    updateAllLSizes(node->left);
    updateAllLSizes(node->right);
    node->lsize = calculateSubtreeSize(node->left) + 1;
}

Node* findKthSmallest(Node* root, int k) {
    if (k <= 0 || root == nullptr) {
        return nullptr;
    }

    Node* p = root;
    while (p != nullptr) {
        int currentRank = p->lsize;

        if (k == currentRank) {
            return p;
        } else if (k < currentRank) {
            p = p->left;
        } else {
            k = k - currentRank;
            p = p->right;
        }
    }

    return nullptr;
}

void deleteTree(Node* root) {
    if (root == nullptr) { return;
}
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;

    std::cout << "请输入AVL树的节点值（输入 -1 表示结束）：" << '\n';
    int value;
    while (true) {
        std::cin >> value;
        if (value == -1) {
            break;
        }
        root = insert(root, value);
    }

    updateAllLSizes(root);

    std::cout << "请输入要查找的第 k 小的节点：" << '\n';
    int k;

    std::cin >> k;
    Node* result = findKthSmallest(root, k);
    if (result != nullptr) {
        std::cout << "树中第 " << k << " 小的节点数据是: " << result->data << '\n';
    } else {
        std::cout << "未能找到第 " << k << " 小的节点 (k 可能超出范围)." << '\n';
    }


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