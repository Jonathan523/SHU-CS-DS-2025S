#pragma once

class BalancedBST
{
public:
    struct Node
    {
        int bf;
        Node* left;
        Node* right;

        Node() : bf(0), left(nullptr), right(nullptr) {}
        ~Node() = default;
    };

    explicit BalancedBST(Node* root);
    ~BalancedBST() = default;

    int getHeight() const;

private:
    Node* root_;
    int computeHeight(Node* node);
};
