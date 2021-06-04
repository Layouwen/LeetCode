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
    // 使用递归进行反转数组
    /**
     * 4->5->2->1
     * 4->5 5->2->1
     * 5->2 2->1
     * 2->1 1
     * 1->2
     * 1->2->5
     * 1->2->5->4
     * return 1
     */
    ListNode *reverseN(ListNode *head, int n){
      // 递归到链表最后一个节点则直接返回
      if (n==1) return head;
      // 记录每次的第二个节点，和保存最终反转后的头节点
      ListNode *tail = head->next, *p = reverseN(head->next, n-1);
      // 4->2->9
      // 头结点先指向第二个节点的后面 4->9
      head->next = tail->next;
      // 然后第二个节点在指向头结点实现反转 2->4
      tail->next = head;
      // 2->4->9
      return p;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      // 在链表开头添加虚头 0, 并保存引用用于返回第一个节点
      ListNode ret(0, head), *p = &ret;
      int cnt = right - left + 1;
      // 递归 p 到需要反转的前一个节点
      while(--left) p = p->next;
      // 递归结束后将 p 指向反转后的链表
      p->next = reverseN(p->next,cnt);
      // 然后第一个节点
      return ret.next;
    }
};
// @lc code=end

