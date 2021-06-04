/*
 * @lc app=leetcode.cn id=206 lang=javascript
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function (head) {
  // 为空返回
  if (!head) return null
  // 定义一个虚头 pre 保存反转后的头地址，以及 cur 指向头结点，next用于保留下一个节点的地址
  let pre = null,
    cur = head,
    next = head.next
  // 知道cur不为null，则表示没有到底
  while (cur) {
    // 将 cur 向后指向 pre
    cur.next = pre
    // pre 向前走一步
    pre = cur
    // cur 向前走一步
    cur = next
    // next 向前走一步
    next && (next = next.next)
  }
  // 然后翻转后的头结点
  return pre
}
// @lc code=end
