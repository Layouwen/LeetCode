/*
 * @lc app=leetcode.cn id=202 lang=javascript
 *
 * [202] 快乐数
 */

// @lc code=start
/**
 * @param {number} n
 * @return {boolean}
 */
// 计算下一个值
function getNext(n) {
  let res = 0
  while (n) {
    res += (n % 10) * (n % 10)
    n = Math.floor(n / 10)
  }
  return res
}
var isHappy = function (n) {
  // 定义快慢指针
  let pre = n,
    cur = getNext(n)
  // 只要 cur 不为1或者快慢指针没有重合，就一直循环
  while (cur !== 1 && pre !== cur) {
    pre = getNext(pre)
    cur = getNext(getNext(cur))
  }
  // 循环结束后，可能是因为有环结束，也可能因为cur为1结束
  return cur === 1
}
// @lc code=end
