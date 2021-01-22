/**
 *
 * @param A 数组形式的整数加法
 * @param K
 */
const addToArrayForm = (A: number[], K: number): number[] => {
  // 空数组存放结果
  const res: number[] = []
  for (let i = A.length - 1; i >= 0; --i) {
    // 取出最后一位，与 K 最后一位相加
    let sum = A[i] + (K % 10)
    // 把 K 最后一位截掉
    K = Math.floor(K / 10)
    if (sum >= 10) {
      // 如果 sum 结果大于10 进位给 K
      K++
      // 对 sum 处理为个位数
      sum -= 10
    }
    // 将处理后的 sum 添加到数组
    res.push(sum)
  }
  // 如果发现 A 遍历完，K 还有剩余值则代表有进位未处理
  for (; K > 0; K = Math.floor(K / 10)) {
    // 对 K % 得它的个位,添加到数组
    res.push(K % 10)
  }
  // 反转数组得出结果
  res.reverse()
  return res
}

// demo
const a = [9, 9, 9]
const k = 23899
// result
console.log(addToArrayForm(a, k))
