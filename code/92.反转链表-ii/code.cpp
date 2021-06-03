/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// TODO: 未完成注释
class Solution {
public:
    ListNode *reverseN(ListNode *head, int n){
      if (n==1) return head;
      ListNode *tail = head->next, *p = reverseN(head->next, n-1);
      head->next = tail->next;
      tail->next = head;
      return p;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      // 在链表开天添加虚头
      ListNode ret(0, head), *p = &ret;
      int cnt = right - left + 1;
      while(--left) p = p->next;
      p->next = reverseN(p->next,cnt);
      return ret.next;
    }
};
// @lc code=end

