/**
 * 最长连续递增序列
 * @param nums
 */
const findLengthOfLCIS = (nums: number[]): number => {
  let ans = 0;
  const n = nums.length;
  let start = 0;
  for (let i = 0; i < n; i++) {
    // 如果当前值比上一个小，则重置开始位置
    if (i > 0 && nums[i] <= nums[i - 1]) start = i;
    // 计算当前长度，与之前的结果比较，获取最长的长度
    ans = Math.max(ans, i - start + 1);
  }
  return ans;
};

const demo = [1, 3, 1, 2, 1, 4, 5, 6];

console.log(findLengthOfLCIS(demo));
