#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // RECURSIVE APPROACH
    bool isSymmetricRecursive(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isMirror(root->left, root->right);
    }
    
private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        // Both nodes are null - symmetric
        if (left == nullptr && right == nullptr) {
            return true;
        }
        
        // One node is null, other is not - not symmetric
        if (left == nullptr || right == nullptr) {
            return false;
        }
        
        // Check if values are equal and subtrees are mirrors
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
    
public:
    // ITERATIVE APPROACH using queue
    bool isSymmetricIterativeQueue(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            
            // Both nodes are null - continue
            if (left == nullptr && right == nullptr) {
                continue;
            }
            
            // One node is null, other is not - not symmetric
            if (left == nullptr || right == nullptr) {
                return false;
            }
            
            // Values don't match - not symmetric
            if (left->val != right->val) {
                return false;
            }
            
            // Push children in mirror order
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        
        return true;
    }
    
    // ITERATIVE APPROACH using stack
    bool isSymmetricIterativeStack(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        stack<TreeNode*> stk;
        stk.push(root->left);
        stk.push(root->right);
        
        while (!stk.empty()) {
            TreeNode* right = stk.top(); stk.pop();
            TreeNode* left = stk.top(); stk.pop();
            
            // Both nodes are null - continue
            if (left == nullptr && right == nullptr) {
                continue;
            }
            
            // One node is null, other is not - not symmetric
            if (left == nullptr || right == nullptr) {
                return false;
            }
            
            // Values don't match - not symmetric
            if (left->val != right->val) {
                return false;
            }
            
            // Push children in mirror order
            stk.push(left->left);
            stk.push(right->right);
            stk.push(left->right);
            stk.push(right->left);
        }
        
        return true;
    }
    
    
    bool isSymmetric(TreeNode* root) {
        // Choose any of the three approaches
        return isSymmetricRecursive(root);
        // return isSymmetricIterativeQueue(root);
        // return isSymmetricIterativeStack(root);
    }
};


int main() {
    Solution solution;
    
    // Example 1: [1,2,2,3,4,4,3]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);
    
    cout << boolalpha;
    cout << "Example 1 (Recursive): " << solution.isSymmetricRecursive(root1) << endl;        
    cout << "Example 1 (Queue): " << solution.isSymmetricIterativeQueue(root1) << endl;      
    cout << "Example 1 (Stack): " << solution.isSymmetricIterativeStack(root1) << endl;      
    
    // Example 2: [1,2,2,null,3,null,3]
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(3);
    
    cout << "Example 2 (Recursive): " << solution.isSymmetricRecursive(root2) << endl;       
    cout << "Example 2 (Queue): " << solution.isSymmetricIterativeQueue(root2) << endl;     
    cout << "Example 2 (Stack): " << solution.isSymmetricIterativeStack(root2) << endl;     
    
    return 0;
}
