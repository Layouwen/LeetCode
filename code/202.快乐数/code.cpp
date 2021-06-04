/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
  //  获得 84 -> 8*8 + 4*4 形式的结果
  int getNext(int n)
  {
    int result = 0;
    while (n)
    {
      result += (n % 10) * (n % 10);
      n /= 10;
    }
    return result;
  }

  bool isHappy(int n)
  {
    // 定义快慢指针
    int slow = n, fast = n;
    // 开始循环，判断该结构是否死循环，如果有重复节点（有环）则表示不是快乐数
    do
    {
      slow = getNext(slow);
      fast = getNext(getNext(fast));
    } while (slow != fast && fast != 1);
    return fast == 1;
  }
};
// @lc code=end
