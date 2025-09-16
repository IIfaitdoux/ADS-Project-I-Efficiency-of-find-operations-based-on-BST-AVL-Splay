#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define HEIGHT(n) ((n) == NULL ? -1 : (n)->height)
#define UPDATE_HEIGHT(n) ((n)->height = MAX(HEIGHT((n)->left), HEIGHT((n)->right)) + 1)
// Tree structure definition
typedef struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;  
} TreeNode;

// Basic operations for bst
TreeNode* bst_insert(TreeNode* root, int key);
TreeNode* bst_delete(TreeNode* root, int key);
TreeNode* bst_find(TreeNode* root, int key);
void bst_inorder(TreeNode* root);

// Basic operations for avl
TreeNode* avl_insert(TreeNode* root, int key);
TreeNode* avl_delete(TreeNode* root, int key);
TreeNode* avl_rotate_right(TreeNode* y);
TreeNode* avl_rotate_left(TreeNode* x);

// Basic operations for splay
TreeNode* splay(TreeNode* root, int key);
TreeNode* splay_insert(TreeNode* root, int key);
TreeNode* splay_delete(TreeNode* root, int key);
TreeNode* splay_find(TreeNode* root, int key);

#endif
