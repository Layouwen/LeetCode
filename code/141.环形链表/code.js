/*
 * @lc app=leetcode.cn id=141 lang=javascript
 *
 * [141] 环形链表
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
 * @return {boolean}
 */
var hasCycle = function (head) {
  // 为空返回
  if (!head) return false
  // 定义快慢指针
  let pre = head,
    cur = head
  // 如果指针以及指针下一个结点不为空则循环链表，查找是否有重合处
  while (cur && cur.next) {
    // pre 一次走一步
    pre = pre.next
    // cur 一次走两步
    cur = cur.next.next
    // 如果重合了表示存在环
    if (pre === cur) return true
  }
  // 出来表示没有重合处，返回false
  return false
}
// @lc code=end
