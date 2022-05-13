#pragma once

#include <time.h>
#include <stdlib.h>

#include <vector>

namespace leetcode {

    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* make(int size, int range = 10000){
        ListNode* head = nullptr;
        ListNode* tail = head;

        srand(time(nullptr));

        while(size--){
            auto* temp = new ListNode(rand() % range);
            if(head == nullptr){
                head = temp;
                tail = head;
            }else{
                tail->next = temp;
                tail = temp;
            }
        }
        return head;
    }

    ListNode* copy(ListNode* src){
        ListNode* head = nullptr;
        ListNode* tail = head;
        ListNode* cur = src;

        while(cur){
            if(head == nullptr){
                head = new ListNode(cur->val);
                tail = head;
            }else{
                tail->next = new ListNode(cur->val);
                tail = tail->next;
            }
            cur = cur->next;
        }
        return head;
    }

    std::vector<int> to_array(ListNode* node){
        std::vector<int> data;
        ListNode* cur = node;
        while(cur){
            data.push_back(cur->val);
            cur = cur->next;
        }
        return data;
    }

    ListNode* from_array(std::vector<int>& nums){
        ListNode* head = nullptr;
        ListNode* tail = head;
        for(auto i = 0; i < nums.size(); i++){
            if(head == nullptr){
                head = new ListNode(nums[i]);
                tail = head;
            }else{
                tail->next = new ListNode(nums[i]);
            }
            tail = tail->next;
        }
        return head;
    }

    void destory(ListNode* node){
        while(node){
            ListNode* next = node->next;
            delete node;
            node = next;
        }
    }
}

