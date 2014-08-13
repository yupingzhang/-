//Populating Next Right Pointers in Each Node
/*
  struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
    
          1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
    
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // bfs
        if(root == NULL) return;
        queue<pair<TreeLinkNode*, int/*level*/> > q;
        int level = 0;
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            // push all the elements in one level
            while(!q.empty() && (q.front().second == level)) {
                level = q.front().second;
                TreeLinkNode *temp = q.front().first;
                q.pop();
                
                if(temp->left != NULL) { 
                   
                    if(q.back().second == level+1) { q.back().first->next = temp->left; }
                    q.push(make_pair(temp->left, level+1)); 
                }
                if(temp->right != NULL) { 
                    temp->left->next = temp->right;
                    q.push(make_pair(temp->right, level+1)); 
                   
                }
            }
             
            level++;
        }
        
    }
};
