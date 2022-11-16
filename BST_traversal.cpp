#include <vector>
#include <stack>

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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> tree;              // create a vector to represent the BST
        std::stack<TreeNode*> stack;        // create a stack of Tree nodes

        while(root || !stack.empty()) {     // loop through as long as root exists and stack is not empty
            while(root) {                   //   while the root exists
                stack.push(root);           //     push the root onto the stack
                root = root->left;          //     make root equal to the left node
            }
            root = stack.top();             //   make root equal to the node on the top of the stack
            stack.pop();                    //   removes top of the stack since it was copied onto root
            tree.push_back(root->val);      //   add val of the root to the end of the tree vector
            root = root->right;             //   turns root into the next right node
        }
        return tree;                        // returns the tree vector
    }
};
