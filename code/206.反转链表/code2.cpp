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
    // 如果为空节点，或者 next 节点为空，则直接返回空
    if (head == nullptr || head->next == nullptr)
      return head;
    // 记录每次递归的第二个节点为 tail，使用 p 记录未翻转钱的最后一个节点为反转后的头结点
    ListNode *tail = head->next, *p = reverseList(head->next);
    // 反转两个节点位置
    head->next = nullptr;
    tail->next = head;
    // 返回头结点 p
    return p;
  }
};
// @lc code=end
