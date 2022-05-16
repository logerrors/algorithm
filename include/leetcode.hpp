#pragma once

#include <time.h>
#include <stdlib.h>

#include <vector>
#include <algorithm>
#include <memory>
#include <string>
#include <deque>
#include <optional>

namespace leetcode
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    template<typename T>
    T* from_string(std::string str);
    
    template<>
    TreeNode* from_string(std::string str){
        if(std::empty(str))return nullptr;
        if(std::size(str) < 2)return nullptr;
        if(str[0] != '[' && str.back() != ']')return nullptr;

        // spilit
        std::vector<std::optional<int>> nums;
        for(auto i = 1; i < std::size(str) - 1;){
            int j = i;
            while(str[j] != ',' && j < std::size(str) - 1)++j;
            std::string num_str = str.substr(i, j - i);
            if(num_str == "null"){
                nums.push_back(std::nullopt);
            }else{
                nums.push_back(std::stoi(num_str));
            }
            i = j + 1;
        }

        // build tree
        TreeNode* head = nullptr;
        std::deque<TreeNode*> node_deque;

        if(nums.empty())return head;

        int index = 0;
        TreeNode* cur = nullptr;
        int len = std::size(nums);
        head = new TreeNode(nums[index].value());
        node_deque.push_back(head);
        while(index < len){
            index++;
            if(index > len)return head;
            cur = node_deque.front();
            node_deque.pop_front();
            auto left = nums[index];
            if(left.has_value()){
                cur->left = new TreeNode(left.value());
                node_deque.push_back(cur->left);
            }
            index++;
            if(index > len)return head;
            auto right = nums[index];
            if(right.has_value()){
                cur->right = new TreeNode(right.value());
                node_deque.push_back(cur->right);
            }

        }

        return head;
    }
    
    template<>
    ListNode* from_string(std::string str){
        if(std::empty(str))return nullptr;
        if(std::size(str) < 2)return nullptr;
        if(str[0] != '[' && str.back() != ']')return nullptr;

        // spilit
        std::vector<int> nums;
        for(auto i = 1; i < std::size(str) - 1;){
            int j = i;
            while(str[j] != ',' && j < std::size(str) - 1)++j;
            std::string num_str = str.substr(i, j - i);
            nums.push_back(std::stoi(num_str));
            i = j + 1;
        }

        // build list
        ListNode* head = nullptr;
        ListNode* tail = head;
        for(auto i = 0; i < nums.size(); i++){
            if(head == nullptr){
                head = new ListNode(nums[i]);
                tail = head;
            }else{
                tail->next = new ListNode(nums[i]);
                tail = tail->next;
            }
        }

        return head;
    }
    
    ListNode *from_random(int size, int range = 10000)
    {
        ListNode *head = nullptr;
        ListNode *tail = head;

        srand(time(nullptr));

        while (size--)
        {
            auto *temp = new ListNode(rand() % range);
            if (head == nullptr)
            {
                head = temp;
                tail = head;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
        return head;
    }

    ListNode *copy(ListNode *src)
    {
        ListNode *head = nullptr;
        ListNode *tail = head;
        ListNode *cur = src;

        while (cur)
        {
            if (head == nullptr)
            {
                head = new ListNode(cur->val);
                tail = head;
            }
            else
            {
                tail->next = new ListNode(cur->val);
                tail = tail->next;
            }
            cur = cur->next;
        }
        return head;
    }

    TreeNode* copy(TreeNode* src){ 
        if(src == nullptr)return nullptr;
        TreeNode* head = new TreeNode(src->val);
        head->left = copy(src->left);
        head->right = copy(src->right);
        return head;
    }

    std::vector<int> to_array(ListNode *node)
    {
        std::vector<int> data;
        ListNode *cur = node;
        while (cur)
        {
            data.push_back(cur->val);
            cur = cur->next;
        }
        return data;
    }

    ListNode *from_array(std::vector<int> &nums)
    {
        ListNode *head = nullptr;
        ListNode *tail = head;
        for (auto i = 0; i < nums.size(); i++)
        {
            if (head == nullptr)
            {
                head = new ListNode(nums[i]);
                tail = head;
            }
            else
            {
                tail->next = new ListNode(nums[i]);
            }
            tail = tail->next;
        }
        return head;
    }

    template<typename T>
    void destroy(T *node);

    template<>
    void destroy(ListNode *node)
    {
        while (node)
        {
            ListNode *next = node->next;
            delete node;
            node = next;
        }
    }

    template<>
    void destroy(TreeNode* node){
        if(node == nullptr)return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    template<typename T>
    T* find(T* node, int val);

    template<>
    TreeNode* find(TreeNode* node, int val){
        if(node == nullptr)return nullptr;
        if(node->val == val)return node;
        auto* left = find(node->left, val);
        if(left != nullptr)return left;
        auto* right = find(node->right, val);
        if(right != nullptr)return right;
        return nullptr;
    }

    template<>
    ListNode* find(ListNode* node, int val){
        if(node == nullptr)return nullptr;
        ListNode* cur = node;
        while(cur){
            if(cur->val == val)return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    template<typename T>
    bool equal(T* node1, T* node2);

    template<>
    bool equal(ListNode* node1, ListNode* node2){
        if(node1 == node2)return true;
        while(node1 != nullptr && node2 != nullptr){
            if(node1->val != node2->val)return false;
            node1 = node1->next;
            node2 = node2->next;
        }
        return node1 == nullptr && node2 == nullptr;
    }

    template<>
    bool equal(TreeNode* node1, TreeNode* node2){
        if(node1 == nullptr && node2 == nullptr)return true;
        if(node1 == nullptr || node2 == nullptr)return false;

        if(node1->val == node2->val){
            return equal(node1->left, node2->left) && equal(node1->right, node2->right);
        }
        return false;
    }

}
