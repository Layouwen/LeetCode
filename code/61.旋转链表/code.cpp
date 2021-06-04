/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
  ListNode *rotateRight(ListNode *head, int k)
  {
    // 如果为空链表直接返回
    if (head == nullptr)
      return nullptr;
    // 记录链表的长度
    int n = 1;
    // p 节点指向开头
    ListNode *p = head;
    // 遍历节点，直到 p 没有下一个节点
    while (p->next)
    {
      p = p->next;
      n += 1;
    }

    // 找到最后的节点后把链表连成一个环
    p->next = head;
    // 对k的取模，去掉整圈的次数，得到左移的次数
    k %= n;
    // 总次数减去左移次数得出右移的次数
    k = n - k;
    // 循环右移 p 节点k次，此时为偏移后的尾节点
    while (k--)
    {
      p = p->next;
    }
    // 设置尾结点下一个为头结点
    head = p->next;
    // 取消尾结点的next，断开环
    p->next = nullptr;
    // 返回头结点
    return head;
  }
};
// @lc code=end
