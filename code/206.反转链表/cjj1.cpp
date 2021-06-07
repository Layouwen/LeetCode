/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    // 如果为空节点，则直接返回
    if (head == nullptr)
      return head;
    // 定义三个指针 pre 指向翻转后的头节点，cur 指向未翻转的头节点，p 指向头结点的下一个节点
    ListNode *pre = nullptr, *cur = head, *p = head->next;
    // 如果 cur 存在则继续往后移动
    while (cur)
    {
      // 未翻转的头节点指向 pre
      cur->next = pre;
      // pre 往前走一步，到 cur 处
      pre = cur;
      // cur 往前走一步到 p 节点处，如果此时 cur 不为空则 p 节点继续走一步
      (cur = p) && (p = p->next);
    }
    // 返回反转后的头节点
    return pre;
  }
};
// @lc code=end
