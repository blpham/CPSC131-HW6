#include <algorithm>

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {                              // if the current node is empty
            return nullptr;                                 // then return nullptr
        }
        if (root->val == key) {                             // if the root has the same val as key
            if (!root->right) {                             //  and if the root points to nothing on the right,
                TreeNode* left = root->left;                //  create a pointer to the left node,
                delete root;                                //  delete the root, then return the left pointer
                return left;                                     
            } else {                                        //  if the root points to nothing on the left,
                TreeNode* right = root->right;              //  create a pointer to the right node
                while (right->left) {                       //  while loop goes to the very last left node
                    right = right->left;                    //  and makes the right pointer equal to that node
                }                                            
                std::swap(root->val, right->val);           //  swap the values of the root and right pointer
                root->right = deleteNode(root->right, key); //  recurse down the tree with the right node
            }                                               //  to move the values up

        } else if (root->val > key) {                       // if the root's val is greater than key
            root->left = deleteNode(root->left, key);       //  recurse with the left node

        } else {                                            // if the root's val is less than key
            root->right = deleteNode(root->right, key);     //  recurse with the right node
        }
        return root;                                        // returns the root
        }
};

