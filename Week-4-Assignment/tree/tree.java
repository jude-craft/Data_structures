import java.util.*;

// Definition for a binary tree node
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution {
    
    // RECURSIVE APPROACH
    public boolean isSymmetricRecursive(TreeNode root) {
        if (root == null) {
            return true;
        }
        return isMirror(root.left, root.right);
    }
    
    private boolean isMirror(TreeNode left, TreeNode right) {
        // Both nodes are null - symmetric
        if (left == null && right == null) {
            return true;
        }
        
        // One node is null, other is not - not symmetric
        if (left == null || right == null) {
            return false;
        }
        
        // Check if values are equal and subtrees are mirrors
        return (left.val == right.val) &&
               isMirror(left.left, right.right) &&
               isMirror(left.right, right.left);
    }
    
    // ITERATIVE APPROACH using Queue
    public boolean isSymmetricIterativeQueue(TreeNode root) {
        if (root == null) {
            return true;
        }
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root.left);
        queue.offer(root.right);
        
        while (!queue.isEmpty()) {
            TreeNode left = queue.poll();
            TreeNode right = queue.poll();
            
            // Both nodes are null - continue
            if (left == null && right == null) {
                continue;
            }
            
            // One node is null, other is not - not symmetric
            if (left == null || right == null) {
                return false;
            }
            
            // Values don't match - not symmetric
            if (left.val != right.val) {
                return false;
            }
            
            // Add children in mirror order
            queue.offer(left.left);
            queue.offer(right.right);
            queue.offer(left.right);
            queue.offer(right.left);
        }
        
        return true;
    }
    
    // ITERATIVE APPROACH using Stack
    public boolean isSymmetricIterativeStack(TreeNode root) {
        if (root == null) {
            return true;
        }
        
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root.left);
        stack.push(root.right);
        
        while (!stack.isEmpty()) {
            TreeNode right = stack.pop();
            TreeNode left = stack.pop();
            
            // Both nodes are null - continue
            if (left == null && right == null) {
                continue;
            }
            
            // One node is null, other is not - not symmetric
            if (left == null || right == null) {
                return false;
            }
            
            // Values don't match - not symmetric
            if (left.val != right.val) {
                return false;
            }
            
            // Push children in mirror order
            stack.push(left.left);
            stack.push(right.right);
            stack.push(left.right);
            stack.push(right.left);
        }
        
        return true;
    }
    
    // Main function - choose approach
    public boolean isSymmetric(TreeNode root) {
        // Choose any of the three approaches
        return isSymmetricRecursive(root);
        // return isSymmetricIterativeQueue(root);
        // return isSymmetricIterativeStack(root);
    }
    
    
    public static void main(String[] args) {
        Solution solution = new Solution();
        
        // Example 1: [1,2,2,3,4,4,3]
        TreeNode root1 = new TreeNode(1);
        root1.left = new TreeNode(2);
        root1.right = new TreeNode(2);
        root1.left.left = new TreeNode(3);
        root1.left.right = new TreeNode(4);
        root1.right.left = new TreeNode(4);
        root1.right.right = new TreeNode(3);
        
        System.out.println("Example 1 (Recursive): " + solution.isSymmetricRecursive(root1));        
        System.out.println("Example 1 (Queue): " + solution.isSymmetricIterativeQueue(root1));      
        System.out.println("Example 1 (Stack): " + solution.isSymmetricIterativeStack(root1));      
        
        // Example 2: [1,2,2,null,3,null,3]
        TreeNode root2 = new TreeNode(1);
        root2.left = new TreeNode(2);
        root2.right = new TreeNode(2);
        root2.left.right = new TreeNode(3);
        root2.right.right = new TreeNode(3);
        
        System.out.println("Example 2 (Recursive): " + solution.isSymmetricRecursive(root2));       
        System.out.println("Example 2 (Queue): " + solution.isSymmetricIterativeQueue(root2));     
        System.out.println("Example 2 (Stack): " + solution.isSymmetricIterativeStack(root2));     
    }
}