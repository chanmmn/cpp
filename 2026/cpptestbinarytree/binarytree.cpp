#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    // Insert function: smaller values go left, larger values go right
    TreeNode* insert(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        
        if (val < root->val) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        
        return root;
    }
    
    // Preorder: Root -> Left -> Right
    void preorder(TreeNode* root) {
        if (!root) return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
    
    // Inorder: Left -> Root -> Right
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
    
    // Postorder: Left -> Right -> Root
    void postorder(TreeNode* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
};

int main() {
    // Create Binary Search Tree by inserting 10 values
    BinaryTree bt;
    TreeNode* root = nullptr;
    
    // Insert 10 values
    int values[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35};
    
    cout << "Inserting values: ";
    for (int i = 0; i < 10; i++) {
        cout << values[i] << " ";
        root = bt.insert(root, values[i]);
    }
    cout << "\n\n";
    
    cout << "Preorder:  ";
    bt.preorder(root);
    cout << "\n";
    
    cout << "Inorder:   ";
    bt.inorder(root);
    cout << "\n";
    
    cout << "Postorder: ";
    bt.postorder(root);
    cout << "\n";
    
    return 0;
}