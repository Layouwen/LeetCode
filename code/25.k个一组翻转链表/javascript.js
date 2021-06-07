/*

 *
 * [25] K 个一组翻转链表
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
var reverseKGroup = function (head, k) {
  // 如果为空则返回
  if (!head) return null
  // 创建虚头，创建变量 pre 保存虚头的地址
  let ret = new ListNode(-1, head),
    pre = ret
  do {
    // 将反转后的链表连接回去
    pre.next = reverse(pre.next, k)
    // 往后走k步
    for (let i = 0; i < k && pre; i++) {
      pre = pre.next
    }
    // 如果往后走k步后为空，则不够一组，中断循环
    if (!pre) break
  } while (1)
  // 然后真实的头节点
  return ret.next
}

// 反转链表n次
let reverse = function (head, n) {
  let pre = head,
    cur = head,
    con = n
  // 循环判断，走n步后，是否还有值
  while (--n && pre) {
    pre = pre.next
  }
  // 如果为空，则表示不够n个一组，原封不动返回
  if (!pre) return head
  pre = null
  while (con--) {
    cur.next = pre
    pre = cur
    cur = cur.next
    // ;[cur.next, pre, cur] = [pre, cur, cur.next]
  }
  head.next = cur
  return pre
}
// @lc code=end
