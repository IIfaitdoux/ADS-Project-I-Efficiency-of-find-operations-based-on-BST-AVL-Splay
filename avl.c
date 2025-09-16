#include "tree.h"

static int get_balance(TreeNode* node) {
    return node == NULL ? 0 : HEIGHT(node->left) - HEIGHT(node->right);
}

TreeNode* avl_rotate_right(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;
    // Perform single rotation
    x->right = y;
    y->left = T2;
    // Update heights
    UPDATE_HEIGHT(y);
    UPDATE_HEIGHT(x);

    return x;
}

TreeNode* avl_rotate_left(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;
    // Perform single rotation
    y->left = x;
    x->right = T2;
    // Update heights
    UPDATE_HEIGHT(x);
    UPDATE_HEIGHT(y);

    return y;
}

/* Unified balance function that handles all four rotation cases:
 * LL (Left Left): balance > 1 && left_balance >= 0
 * LR (Left Right): balance > 1 && left_balance < 0
 * RR (Right Right): balance < -1 && right_balance <= 0
 * RL (Right Left): balance < -1 && right_balance > 0
 */
TreeNode* avl_balance(TreeNode* root) {
    if (root == NULL) return NULL;

    int balance = get_balance(root);
    
    // Left heavy
    if (balance > 1) {
        int left_balance = get_balance(root->left);
        if (left_balance >= 0) {
            // Left Left Case
            return avl_rotate_right(root);
        } else {
            // Left Right Case
            root->left = avl_rotate_left(root->left);
            return avl_rotate_right(root);
        }
    }
    
    // Right heavy
    if (balance < -1) {
        int right_balance = get_balance(root->right);
        if (right_balance <= 0) {
            // Right Right Case
            return avl_rotate_left(root);
        } else {
            // Right Left Case
            root->right = avl_rotate_right(root->right);
            return avl_rotate_left(root);
        }
    }
    
    // Already balanced
    return root;
}

// Find node with minimum value in AVL tree
static TreeNode* find_min_node(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

TreeNode* avl_insert(TreeNode* root, int key) {
    if (root == NULL) return create_node(key);
    
    // Insert the key recursively
    if (key < root->key)
        root->left = avl_insert(root->left, key);
    else if (key > root->key)
        root->right = avl_insert(root->right, key);
    else // if(key == root->key)
        return root;
        
    // Update height of this ancestor node
    UPDATE_HEIGHT(root);
    
    // Balance the tree
    return avl_balance(root);
}

TreeNode* avl_delete(TreeNode* root, int key) {
    // Standard BST delete
    if (root == NULL) return root;

    // Recursive deletion
    if (key < root->key)
        root->left = avl_delete(root->left, key);
    else if (key > root->key)
        root->right = avl_delete(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        TreeNode* temp = find_min_node(root->right);
        root->key = temp->key;
        root->right = avl_delete(root->right, temp->key);
    }

    if (root == NULL) return root;

    // Update height
    UPDATE_HEIGHT(root);
    
    // Balance the tree
    return avl_balance(root);
}
