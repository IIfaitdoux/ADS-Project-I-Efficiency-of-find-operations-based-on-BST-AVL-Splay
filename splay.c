#include "tree.h"

/**
 * @brief Performs the splay operation on a tree
 * 
 * The splay operation moves the node with the given key to the root through a series
 * of rotations. This is the core operation of a Splay tree and is performed after
 * every access, making frequently accessed nodes quicker to reach in subsequent operations.
 * 
 * There are three main cases in splaying:
 * 1. Zig: Single rotation when target is child of root
 * 2. Zig-Zig: Two rotations in same direction
 * 3. Zig-Zag: Two rotations in opposite directions
 * 
 * @param root The root of the tree
 * @param key The key to splay to the root
 * @return TreeNode* The new root after splaying
 */
TreeNode* splay(TreeNode* root, int key) {
    // Base case: empty tree or key found at root
    if (root == NULL || root->key == key) return root;

    // Key is in left subtree
    if (root->key > key) {
        if (root->left == NULL) return root;  // Key not found
        
        // Zig-Zig case (Left Left)
        if (root->left->key > key) {
            root->left->left = splay(root->left->left, key);
            root = avl_rotate_right(root);
        } 
        // Zig-Zag case (Left Right)
        else if (root->left->key < key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = avl_rotate_left(root->left);
        }
        
        // Final Zig case or return as is if key not found
        return (root->left == NULL) ? root : avl_rotate_right(root);
    } 
    // Key is in right subtree
    else {
        if (root->right == NULL) return root;  // Key not found

        // Zig-Zag case (Right Left)
        if (root->right->key > key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = avl_rotate_right(root->right);
        } 
        // Zig-Zig case (Right Right)
        else if (root->right->key < key) {
            root->right->right = splay(root->right->right, key);
            root = avl_rotate_left(root);
        }
        
        // Final Zig case or return as is if key not found
        return (root->right == NULL) ? root : avl_rotate_left(root);
    }
}
// Insert the key and splay it to the root
TreeNode* splay_insert(TreeNode* root, int key) {
    root = bst_insert(root, key);
    return splay(root, key);
}

// Find the key and splay it to the root
TreeNode* splay_find(TreeNode* root, int key) {
    return splay(root, key);
}

TreeNode* splay_delete(TreeNode* root, int key) {
    if (root == NULL) return NULL;
    
    // Bring the key to root if it exists
    root = splay(root, key);
    
    // If key not found, return unchanged tree
    if (key != root->key) return root;
    
    TreeNode* temp = root;
    if (root->left == NULL) {
        // No left subtree, make right child the new root
        root = root->right;
    } else {
        // Splay the maximum key in left subtree to root,
        // then attach the right subtree
        root = splay(root->left, key); //special note*: here key is not in the tree, so it will splay the max node
        root->right = temp->right;
    }
    
    free(temp);
    return root;
}
