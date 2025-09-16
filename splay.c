#include "tree.h"

TreeNode* splay(TreeNode* root, int key) {
    if (root == NULL || root->key == key) return root;

    if (root->key > key) {
        if (root->left == NULL) return root;
        
        if (root->left->key > key) {
            root->left->left = splay(root->left->left, key);
            root = avl_rotate_right(root);
        } else if (root->left->key < key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = avl_rotate_left(root->left);
        }
        
        return (root->left == NULL) ? root : avl_rotate_right(root);
    } else {
        if (root->right == NULL) return root;

        if (root->right->key > key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = avl_rotate_right(root->right);
        } else if (root->right->key < key) {
            root->right->right = splay(root->right->right, key);
            root = avl_rotate_left(root);
        }
        
        return (root->right == NULL) ? root : avl_rotate_left(root);
    }
}

TreeNode* splay_insert(TreeNode* root, int key) {
    root = bst_insert(root, key);
    return splay(root, key);
}

TreeNode* splay_find(TreeNode* root, int key) {
    return splay(root, key);
}

TreeNode* splay_delete(TreeNode* root, int key) {
    if (root == NULL) return NULL;
    
    root = splay(root, key);
    
    if (key != root->key) return root;
    
    TreeNode* temp = root;
    if (root->left == NULL) {
        root = root->right;
    } else {
        root = splay(root->left, key);
        root->right = temp->right;
    }
    
    free(temp);
    return root;
}
