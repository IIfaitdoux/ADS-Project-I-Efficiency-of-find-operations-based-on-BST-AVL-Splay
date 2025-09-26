#include "tree.h"

TreeNode* insert(TreeNode* root, int key, int TreeType) {
    switch (TreeType)
    {
    case 0:  // BST
        return bst_insert(root, key);
        break;
    case 1:  // AVL
        return avl_insert(root, key);
        break;
    case 2:  // Splay
        return splay_insert(root, key);
        break;
    default:
        return root;
    }
}

TreeNode* delete(TreeNode* root, int key, int TreeType) {
    switch (TreeType)
    {
    case 0:  // BST
        return bst_delete(root, key);
        break;
    case 1:  // AVL
        return avl_delete(root, key);
        break;
    case 2:  // Splay
        return splay_delete(root, key);
        break;
    default:
        return root;
    }
}

TreeNode* create_node(int key) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 0;
    return node;
}
