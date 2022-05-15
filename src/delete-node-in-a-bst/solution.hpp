#include <leetcode.hpp>

using namespace leetcode;

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)return root;

        if(key > root->val){
            root->right = deleteNode(root->right, key);
        }else if(key < root->val){
            root->left = deleteNode(root->left, key);
        }else{
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                root = nullptr;
            }else if(root->right != nullptr){
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            }else{
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }

private:
    int successor(TreeNode* root){
        auto cur = root->right;
        while(cur->left != nullptr){
            cur = cur->left;
        }
        return cur->val;
    }

    int predecessor(TreeNode* root){
        auto cur = root->left;
        while(cur->right != nullptr){
            cur = cur->right;
        }
        return cur->val;
    }
};