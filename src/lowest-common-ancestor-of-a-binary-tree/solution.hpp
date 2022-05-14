#include <leetcode.hpp>

using namespace leetcode;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if(left == nullptr && right == nullptr)return nullptr;
        if(left == nullptr)return right;
        if(right == nullptr)return left;
        return root;
    }
};