/*
 * @lc app=leetcode.cn id=142 lang=javascript
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var detectCycle = function (head) {
  // 如果为空返回空
  if (!head) return null
  // 定义快慢指针
  let pre = head,
    cur = head
  // 循环结点，如果没有到底则继续循环
  while (cur && cur.next) {
    pre = pre.next
    cur = cur.next.next
    // 重合则表示有环
    if (pre === cur) {
      // 重置慢指针的地址
      pre = head
      // 循环链表，再次重合的点就是入口点
      while (cur != pre) {
        pre = pre.next
        cur = cur.next
      }
      return pre
    }
  }
  // 循环结束表述该链表没有环
  return null
}
// @lc code=end
