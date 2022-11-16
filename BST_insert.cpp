// Definition for a binary tree node.
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
    TreeNode* insertIntoBST (TreeNode* root, int val) {
        if (root == nullptr) {                              // if the root is empty then
            return new TreeNode(val);                       // create a new node with value val
        }
        if (root->val > val) {                              // if the root's val is greater than val
            root->left = insertIntoBST(root->left, val);    // then recurse with the left node
        } else {
            root->right = insertIntoBST(root->right, val);  // if the root's val is less than val
        }                                                   // then recurse with the right node
        
        return root;                                        // returns the current root
    }
};