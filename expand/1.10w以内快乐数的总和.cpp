#include <iostream>

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

int main()
{
  int result = 0;
  for (int i = 1; i <= 100000; i++)
  {
    if (isHappy(i))
      result += i;
  }
  std::cout << "结果为:" << result << std::endl; // 692159746
  return 0;
}