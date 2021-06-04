/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
  ListNode *deleteDuplicates(ListNode *head)
  {
    // 如果为空链表则返回空
    if (head == nullptr)
      return nullptr;
    // 记录头结点
    ListNode *p = head;
    // 如果 p 有下一个节点则继续判断
    while (p->next)
    {
      // 如果当前 p 的值与下一个节点的值相同，则删除该节点，否则使指针后移
      if (p->next->val == p->val)
      {
        p->next = p->next->next;
      }
      else
      {
        p = p->next;
      }
    }
    // 返回头结点
    return head;
  }
};
// @lc code=end
