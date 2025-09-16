#include "tree.h"

TreeNode* create_node(int key) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 0;
    return node;
}

TreeNode* bst_insert(TreeNode* root, int key) {
    if (root == NULL) return create_node(key);
    
    if (key < root->key)
        root->left = bst_insert(root->left, key);
    else if (key > root->key)
        root->right = bst_insert(root->right, key);
    
    return root;
}

TreeNode* bst_find(TreeNode* root, int key) {
    if (root == NULL || root->key == key) return root;
    
    if (key < root->key)
        return bst_find(root->left, key);
    return bst_find(root->right, key);
}

TreeNode* bst_delete(TreeNode* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->key)
        root->left = bst_delete(root->left, key);
    else if (key > root->key)
        root->right = bst_delete(root->right, key);
    else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        
        TreeNode* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        root->key = temp->key;
        root->right = bst_delete(root->right, temp->key);
    }
    return root;
}

void bst_inorder(TreeNode* root) {
    if (root != NULL) {
        bst_inorder(root->left);
        printf("%d ", root->key);
        bst_inorder(root->right);
    }
}
