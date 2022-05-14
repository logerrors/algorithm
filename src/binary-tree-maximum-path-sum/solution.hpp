#include <leetcode.hpp>

#include <limits.h>
using namespace leetcode;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ret;
    }

    int dfs(TreeNode* node){
        if(node == nullptr)return 0;
        int left = std::max(0, dfs(node->left));
        int right = std::max(0, dfs(node->right));
        ret = std::max(ret, left + right + node->val);
        return std::max(left, right) + node->val;
    }
private:
    int ret = INT_MIN;
};