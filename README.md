# leetcode
***
###1. two sum
1. brute force可以做，但是用hash table可以进一步提高效率
可以用one-pass hash table，即加入一个数的时候先检测是否有对应的数已经在hash table中了。
***
###2. Add Two Numbers
1. 第一个点可以直接是虚构的，而实际第一个点为第二个点，避免代码的重复
2. 第二个循环和第一个循环可以合并，只要设置到NULL后，加的数值为0即可，避免代码重复
***
###3. longest Substring Without Repeating Characters
1. Unordered map, insert会首先遍历整个集合，判断是否存在相同的key，如果存在则直接返回，放弃插入操作。如果不存在才进行插入。
而[]方式是通过重载[]操作符来实现的，它直接进行插入或覆盖。
***
###4. Median of Two Sorted Arrays
1. 将A，B各分成两部分A left，B left，A right，B right
```
1. len(A left + B left) = len(A right + B right)
2. A[i-1] <= B[j] and B[j-1]<=A[i]
```
这样复杂度就是O(log(min(m , n)))
***
###5. Longest Palindromic Substring
1. **A palindrome is a string which reads the same in both directions.**
2. For example, SS = "aba" is a palindrome, SS = "abc" is not.
算法见笔记

***
###8. String to Integer (atoi)
逻辑上可以更加简洁，比较solution 和 solutionV1
