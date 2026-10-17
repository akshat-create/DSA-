
class Solution {
public:
    TreeNode* ans = NULL;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;

        if (root == p || root == q) {
            ans = root;
            return ans;
        }

        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        else if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        else {
            ans = root;
            return ans;
        }
    }
};
