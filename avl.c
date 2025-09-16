#include "tree.h"

static int get_balance(TreeNode* node) {
    return node == NULL ? 0 : HEIGHT(node->left) - HEIGHT(node->right);
}

TreeNode* avl_rotate_right(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    UPDATE_HEIGHT(y);
    UPDATE_HEIGHT(x);

    return x;
}

TreeNode* avl_rotate_left(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    UPDATE_HEIGHT(x);
    UPDATE_HEIGHT(y);

    return y;
}

TreeNode* avl_insert(TreeNode* root, int key) {
    if (root == NULL) return create_node(key);

    if (key < root->key)
        root->left = avl_insert(root->left, key);
    else if (key > root->key)
        root->right = avl_insert(root->right, key);
    else
        return root;

    UPDATE_HEIGHT(root);
    int balance = get_balance(root);

    // Left Left
    if (balance > 1 && key < root->left->key)
        return avl_rotate_right(root);

    // Right Right
    if (balance < -1 && key > root->right->key)
        return avl_rotate_left(root);

    // Left Right
    if (balance > 1 && key > root->left->key) {
        root->left = avl_rotate_left(root->left);
        return avl_rotate_right(root);
    }

    // Right Left
    if (balance < -1 && key < root->right->key) {
        root->right = avl_rotate_right(root->right);
        return avl_rotate_left(root);
    }

    return root;
}
