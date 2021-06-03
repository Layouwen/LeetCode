/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
  bool hasCycle(ListNode *head)
  {
    // 如果链表为空返回 false
    if (head == nullptr)
      return false;
    // 定义两个指针分别指向第一个和第二个
    ListNode *slow = head, *fast = head->next;
    // 开始循环链表, 如果他们相遇了则停止。如果其中一个为空则到达链表末尾，则停止
    while (slow != fast && fast && fast->next)
    {
      // 持续让 p 和 q 往后走，p 每次走一步， q 每次走两步
      slow = slow->next;
      fast = fast->next->next;
    }
    // 如果 q 和 q 的下一个有值。则表示有环
    return fast && fast->next;
  }
};
// @lc code=end
