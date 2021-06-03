/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  ListNode *detectCycle(ListNode *head)
  {
    // 如果为空直接返回 nullptr
    if (head == nullptr)
      return nullptr;
    // 快慢指针从头开始
    ListNode *slow = head, *fast = head;
    // 如果没有第二个结点则表示只有一个节点，没有环返回 nullptr
    if (fast->next == nullptr)
      return nullptr;
    // 开始循环,判断是否相遇，如果相遇则表示有环
    do
    {
      slow = slow->next;
      fast = fast->next->next;
    } while (slow != fast && fast && fast->next);
    // 如果快指针的下一个节点指向 nullptr 则表示到达链表末尾，则没有环
    if (fast == nullptr || fast->next == nullptr)
      return nullptr;
    // 到这里表示有环，则重置慢指针，等待快慢指针再次相遇的时候，则表示环的起始点
    slow = head;
    while (slow != fast)
      slow = slow->next, fast = fast->next;
    return fast;
  }
};
// @lc code=end
