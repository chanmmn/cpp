#include <iostream>
using namespace std;

struct BSTNode {
    int key;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* newNode(int key) {
    return new BSTNode{key, nullptr, nullptr};
}

BSTNode* insert(BSTNode* root, int key) {
    if (!root) return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

BSTNode* findMin(BSTNode* node) {
    while (node->left) node = node->left;
    return node;
}

BSTNode* deleteNode(BSTNode* root, int key) {
    if (!root) return nullptr;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // node found
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        BSTNode* successor = findMin(root->right);
        root->key = successor->key;
        root->right = deleteNode(root->right, successor->key);
    }
    return root;
}

int main() {
    BSTNode* root = nullptr;

    // Worst-case insertion order (sorted)
    for (int i = 1; i <= 7; i++)
        root = insert(root, i);

    cout << "Deleting node 7 from a skewed BST...\n";
    root = deleteNode(root, 7);

    return 0;
}