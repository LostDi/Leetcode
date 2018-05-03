/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int lastval=INT_MAX;
        int mindiff=INT_MAX;
        inorderT(root,mindiff,lastval);
        return mindiff;
    }
    void inorderT(TreeNode* root,int &mindiff,int &lastval){
        if(!root){
            return;
        }
        inorderT(root->left,mindiff,lastval);
        mindiff=abs(min(mindiff,root->val-lastval));
        lastval=root->val;
        inorderT(root->right,mindiff,lastval);
        return;
    }
};
