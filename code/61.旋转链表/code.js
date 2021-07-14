/*
 * @lc app=leetcode.cn id=61 lang=javascript
 *
 * [61] 旋转链表
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
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function (head, k) {
  if (!head) return null
  let cur = head
  let length = 1
  // 通过 cur 指针找到链表最后一个节点
  while (cur.next) {
    cur = cur.next
    // 每次走一步，长度加一
    length += 1
  }
  // 将最后一个节点的 next 指向 head。使其形成环
  cur.next = head
  for (let i = 0; i < length - (k % length) - 1; i++) {
    head = head.next
  }
  // 将移动后的节点，下一个节点保存起来，此时 cur 就是旋转后的头结点
  cur = head.next
  // 将尾结点断开
  head.next = null
  // 返回头结点
  return cur
}
// @lc code=end
