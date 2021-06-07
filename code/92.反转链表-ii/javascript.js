/*
 * @lc app=leetcode.cn id=92 lang=javascript
 *
 * [92] 反转链表 II
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
 * @param {number} left
 * @param {number} right
 * @return {ListNode}
 */
var reverseBetween = function (head, left, right) {
  // 为空返回
  if (!head) return null
  // 定义虚头，计算需要翻转的次数，保存翻转节点的前一位
  let ret = new ListNode(-1, head),
    cnt = right - left + 1,
    pre = ret
  // 寻找需要翻转的节点前一位
  while (--left) {
    pre = pre.next
  }
  // 连接上翻转后的头节点
  pre.next = reverse(pre.next, cnt)
  return ret.next
}

// 翻转节点
function reverse(head, n) {
  let pre = null,
    cur = head,
    next = head.next
  while (n--) {
    cur.next = pre
    pre = cur
    cur = next
    next && (next = next.next)
  }
  // head 是原本的头节点，翻转后为最后一个节点，将这个节点的下一个节点指向 cur 的位置连接起来
  head.next = cur
  return pre
}
// @lc code=end
