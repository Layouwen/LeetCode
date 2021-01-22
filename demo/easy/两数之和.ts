/**
 * 两数之和
 * @param numArr 
 * @param target 
 */
const twoSum = (numArr: number[], target: number) => {
  const len = numArr.length
  const result: number[] = []
  for (let i = 0; i < len; i++) {
    for (let j = i + 1; j < len; j++) {
      if (numArr[i] + numArr[j] === target) result.push(i, j)
    }
  }
  return result
}

// demo
const arr = [1, 2, 5, 7, 834]
// result
console.log(twoSum(arr, 7))