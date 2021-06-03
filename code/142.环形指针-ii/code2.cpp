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
    // 定义一个慢指针和一个快指针
    ListNode *slow = head, *fast = head->next;
    // 开始循环，判断是否有环
    while (slow != fast && fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    // 循环结束后看看时候是到达链尾终止的，如果是则没有环
    if (fast == nullptr || fast->next == nullptr)
      return nullptr;
    // 重置快慢指针的地址, 此时已知有环
    slow = head->next, fast = head->next->next;
    // 找到他们相遇的点
    while (slow != fast)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    // 相遇后把慢指针重置到开头
    slow = head;
    // 如果此时相遇则表示为环的起始点
    while (slow != fast)
    {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};
// @lc code=end
