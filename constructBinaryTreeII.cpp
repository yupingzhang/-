// Construct Binary Tree from Inorder and Postorder Traversal 
/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
class Solution {
public:
    TreeNode *constructTree(vector<int> &inorder, vector<int> &postorder, int istart, int iend, int pend) {
        if(istart>iend) return NULL;
        else{
            int root_val = postorder[pend];
            TreeNode *root = new TreeNode(root_val);
            int mid;
            for(auto it = inorder.begin() + istart; it <= inorder.begin() + iend; it++) {
                if(*it == root_val) {
                    mid = it - inorder.begin();
                    break;
                }
            }
            
            root->left = constructTree(inorder, postorder, istart, mid-1, pend-1-iend+mid);
            root->right = constructTree(inorder, postorder, mid+1, iend, pend-1);
            return root;
        }
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0) return NULL;
        else{
            constructTree(inorder, postorder, 0, inorder.size()-1, postorder.size()-1);
        }
        
    }
};
