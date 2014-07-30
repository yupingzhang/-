// Construct Binary Tree from Preorder and Inorder Traversal 
/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 1. Find the first node in the preorder vector, which is the root of the current tree.
 2. Find the position of root node in the inorder vector, which divide the inorder vector into 2 sub tree inorder vectors. Left part is the left sub-tree, right part is the right sub-tree.
 3. repeat 1 & 2
 */
class Solution {
public:
    TreeNode *constructTree(vector<int> &preorder, vector<int> &inorder, int istart, int iend, int pstart) {
        if(istart>iend) return NULL;
        int root_val = preorder[pstart];
        TreeNode *root = new TreeNode(root_val);
        int mid;
        for(auto it = inorder.begin() + istart; it != inorder.begin() + iend+1; it++) {
            if(*it == root_val) {
                mid = it - inorder.begin();
                break;
            }
        }

        root->left = constructTree(preorder, inorder, istart, mid-1, pstart+1 );
        root->right = constructTree(preorder, inorder, mid+1, iend, pstart+1+mid-istart);
        
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0) {
            return NULL;
        }else {
            return constructTree(preorder, inorder, 0, inorder.size()-1, 0);
        }
    }
};
