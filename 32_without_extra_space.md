# 32. Longest Valid Parentheses

## Description:

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

## Example:
- Example 1:

  Input: "(()"

  Output: 2

  Explanation: The longest valid parentheses substring is "()"

- Example 2:
  
  Input: ")()())"
  
  Output: 4
  
  Explanation: The longest valid parentheses substring is "()()"*/

## Approach: O(n) time, without extra space

In this approach, we make use of two counters `left` and `right`. 
1. We start traversing the string from the left towards the right and for every '(' encountered, we increment the `left` counter and for every ')' encountered, we increment the `right` counter.
    
2. Whenever `left` becomes equal to `right`, we calculate the length of the current valid string and keep track of maximum length substring found so far. If `right` becomes greater than `left`, we reset `left` and `right` to `0`.

3. Next, we start traversing the string from right to left and similar procedure is applied. However, this time, if `left` becomes greater than `right`, we reset `left` and `right` to `0`.

## Proof

assume the longest substring is `s[i: j + 1]`
1. From left to right，when we reach `i - 1`
- if `left = right != 0`, then we found that the `s[i: j + 1]` is not the longest substring. Contradict!
- if `left = right = 0`, then we can found substring, because when we reach `j`, `left = right`, we will calculate the length of the current valid string.
- if `left < right`, due to rule 2, we reset `left` and `right` to `0`  
- if `left > right`, we cannot find the substring `s[i: j + 1]`, because we will not stop when we reach `j`

2. From right to left, we get the similar result, point 1,2 is the same as from left to right
- if `left > right`, due to rule 3, we reset `left` and `right` to `0`
-   if `left < right`, we cannot find the substring `s[i: j + 1]`, because we will not stop when we reach `i`

3. We can prove the Case 1 Point 4 cannot exist with Case 2 Point 2 simulatenously.

<font size = 8>

```
(    (  )(  ) (  )  )
i-1  i           j  j+1
 |         |         |
L>R       L=R       L<R

```
</font>

- if `i - 1` is `)`, because L > R, therefore, `i - 1` must be a part of valid parentheses, therefore substring `s[i: j + 1]` will not be the longest.
- if `j + 1` is `(`, becasue L < R, therefore, `j + 1` must be a part of valid parentheses, therefore substring `s[i: j + 1]` will not be the longest.
- Therefore,  `i - 1` must be `(`,`j + 1` must be `)`, the `s[i - 1 : j + 2]` is also the valid parenthese. Contradict.

4. Therefore Case 1 Point 4 cannot exist with Case 2 Point 2 simulatenously. One of them will not exist. Therefore, we can find the substring `s[i: j + 1]` either from left to right scan or right to left scan.