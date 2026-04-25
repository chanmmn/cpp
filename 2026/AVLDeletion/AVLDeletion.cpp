#include <iostream>
#include <algorithm>
using namespace std;

struct AVLNode {
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;
};

int height(AVLNode* n) {
    return n ? n->height : 0;
}

AVLNode* newNode(int key) {
    return new AVLNode{key, nullptr, nullptr, 1};
}

int balanceFactor(AVLNode* n) {
    return height(n->right) - height(n->left);
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T = x->right;

    x->right = y;
    y->left = T;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* rebalance(AVLNode* node) {
    int bf = balanceFactor(node);

    // Right heavy
    if (bf > 1) {
        if (balanceFactor(node->right) < 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    // Left heavy
    if (bf < -1) {
        if (balanceFactor(node->left) > 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    return node;
}

AVLNode* insert(AVLNode* root, int key) {
    if (!root) return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    root->height = max(height(root->left), height(root->right)) + 1;
    return rebalance(root);
}

AVLNode* findMin(AVLNode* node) {
    while (node->left) node = node->left;
    return node;
}

AVLNode* deleteNode(AVLNode* root, int key) {
    if (!root) return nullptr;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        AVLNode* successor = findMin(root->right);
        root->key = successor->key;
        root->right = deleteNode(root->right, successor->key);
    }

    root->height = max(height(root->left), height(root->right)) + 1;
    return rebalance(root);
}

int main() {
    AVLNode* root = nullptr;

    for (int i = 1; i <= 7; i++)
        root = insert(root, i);

    cout << "Deleting node 7 from an AVL tree...\n";
    root = deleteNode(root, 7);

    return 0;
}