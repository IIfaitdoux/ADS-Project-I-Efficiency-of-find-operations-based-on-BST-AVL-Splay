#include "tree.h"
// Create a new tree node
TreeNode* create_node(int key) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 0;
    return node;
}

TreeNode* bst_insert(TreeNode* root, int key) {
    if (root == NULL) return create_node(key);
    //insert recursively into the bst
    if (key < root->key)
        root->left = bst_insert(root->left, key);
    else if (key > root->key)
        root->right = bst_insert(root->right, key);
    
    return root;
}

TreeNode* bst_find(TreeNode* root, int key) {
    if (root == NULL || root->key == key) return root;
    // find recursively in the bst
    if (key < root->key)
        return bst_find(root->left, key);
    return bst_find(root->right, key);
}

TreeNode* bst_delete(TreeNode* root, int key) {
    if (root == NULL) return NULL;
    // delete recursively from the bst
    if (key < root->key)
        root->left = bst_delete(root->left, key);
    else if (key > root->key)
        root->right = bst_delete(root->right, key);
    else {
        // if the root has an empty subtree
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // if the root has two children, get the inorder successor (smallest in the right subtree)
        TreeNode* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        root->key = temp->key;
        root->right = bst_delete(root->right, temp->key);
    }
    return root;
}
// return the inorder traversal of the bst(maybe used)
void bst_inorder(TreeNode* root) {
    if (root != NULL) {
        bst_inorder(root->left);
        printf("%d ", root->key);
        bst_inorder(root->right);
    }
}
