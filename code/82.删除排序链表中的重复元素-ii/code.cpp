/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    // 定义虚头，创建 p 节点指向虚头
    ListNode ret(0, head), *p = &ret, *q;
    // 如果 p 后面有节点，则继续循环判断
    while (p->next)
    {
      // 如果 p 后面节点的值与后面后面的值相同，则表示重复
      if (p->next->next && p->next->val == p->next->next->val)
      {
        // 此时使用循环让 q 去查找到不相等的值，如果相等继续往后查找
        q = p->next->next;
        while (q && q->val == p->next->val)
          q = q->next;
        // 找到后将 p 指针的下一个指向不重复的值
        p->next = q;
      }
      else
      {
        // 否则 p 往后走一步，继续判断后面的节点是否有重复
        p = p->next;
      }
    }
    return ret.next;
  }
};
// @lc code=end
