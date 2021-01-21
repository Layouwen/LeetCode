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

const arr = [1, 2, 5, 7, 834]

console.log(twoSum(arr, 7))