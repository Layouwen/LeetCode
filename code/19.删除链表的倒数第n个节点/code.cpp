/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    // 如果需要对头结点进行操作，则定义多一个虚拟头结点
    ListNode ret(0, head), *q = head, *p = &ret;
    // 让q先走n步
    while (n--)
      q = q->next;
    // 然后 p 和 q 同时往后走，直到q为nullptr，此时q指向删除节点的前一位
    while (q)
      p = p->next, q = q->next;
    // 此时使p跳过这个节点即可
    p->next = p->next->next;
    // 因为删除的节点可能是头结点，所以直接返回虚头的下一个节点
    return ret.next;
  }
};
// @lc code=end
