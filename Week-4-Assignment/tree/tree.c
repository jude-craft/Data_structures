#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// RECURSIVE APPROACH
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    // Both nodes are NULL - symmetric
    if (left == NULL && right == NULL) {
        return true;
    }
    
    // One node is NULL, other is not - not symmetric
    if (left == NULL || right == NULL) {
        return false;
    }
    
    // Check if values are equal and subtrees are mirrors
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetricRecursive(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return isMirror(root->left, root->right);
}

// ITERATIVE APPROACH using array as stack
#define MAX_NODES 2000

bool isSymmetricIterative(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    
    // Use arrays to simulate stack for left and right nodes
    struct TreeNode* leftStack[MAX_NODES];
    struct TreeNode* rightStack[MAX_NODES];
    int top = -1;
    
    // Push initial nodes
    leftStack[++top] = root->left;
    rightStack[top] = root->right;
    
    while (top >= 0) {
        struct TreeNode* left = leftStack[top];
        struct TreeNode* right = rightStack[top--];
        
        // Both nodes are NULL - continue
        if (left == NULL && right == NULL) {
            continue;
        }
        
        // One node is NULL, other is not - not symmetric
        if (left == NULL || right == NULL) {
            return false;
        }
        
        // Values don't match - not symmetric
        if (left->val != right->val) {
            return false;
        }
        
        // Push children in mirror order
        leftStack[++top] = left->left;
        rightStack[top] = right->right;
        
        leftStack[++top] = left->right;
        rightStack[top] = right->left;
    }
    
    return true;
}

// Main function for both approaches
bool isSymmetric(struct TreeNode* root) {
    // Choose either recursive or iterative approach
    return isSymmetricRecursive(root);
    // return isSymmetricIterative(root);
}


int main() {
    // Example 1: [1,2,2,3,4,4,3]
    struct TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(2);
    root1->left->left = createNode(3);
    root1->left->right = createNode(4);
    root1->right->left = createNode(4);
    root1->right->right = createNode(3);
    
    printf("Example 1 (Recursive): %s\n", 
           isSymmetricRecursive(root1) ? "true" : "false");  
    printf("Example 1 (Iterative): %s\n", 
           isSymmetricIterative(root1) ? "true" : "false");  
    
    // Example 2: [1,2,2,null,3,null,3]
    struct TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(2);
    root2->left->right = createNode(3);
    root2->right->right = createNode(3);
    
    printf("Example 2 (Recursive): %s\n", 
           isSymmetricRecursive(root2) ? "true" : "false");  
    printf("Example 2 (Iterative): %s\n", 
           isSymmetricIterative(root2) ? "true" : "false");  
    
    return 0;
}
