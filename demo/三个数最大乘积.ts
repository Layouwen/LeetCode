/**
 * 输入一个数组，返回其数组内部中，三个数最大的乘积
 * @param arr 
 */
const maximumProduct = (arr: number[]): number => {
  // 从小到大排序
  arr.sort((a, b) => a - b)
  // 获取数组的长度
  let n = arr.length
  // 计算最大三个正数的结果，以及最小两个负数的乘积与最大正数的乘积结果。取最大的值返回
  return Math.max(arr[0] * arr[1] * arr[n - 1], arr[n - 1] * arr[n - 2] * arr[n - 3])
}