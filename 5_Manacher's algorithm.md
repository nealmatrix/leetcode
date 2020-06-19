# Manacher's algorithm

## 前言

* 本篇针对leetcode Q5 longest palindromic substring问题介绍Manacher's algorithm
  
  以下为问题叙述：

  Given a string s, find the longest palindromic substring in s.

* 此算法是non-trivial algorithm, 复杂度可以由一般的O($n^2$)降为O(n)
  
* 阅读此算法前需了解center expand算法，复杂度为O($n^2$)
  
* 定义最大回文半径：确定center后向外判断是否为palindromic的字母个数
  
  例如 `abcba`，以c为中心，最大回文半径即是2，以左边b为中心，最大回文半径为0，因为b向外扩展1个字母就已经不是palindromic
  

* 此算法与center expand算法前面思路相似，但是后面expand center检测最大回文半径时，每个center不是互相独立，而是可以通过前面的center的结果帮助推导后面center的最大回文半径，从而大大降低算法复杂度
  
## 算法介绍

1. 预处理：将input string字母间隙以及最左边和最右边插入#字，这样确定center的时候，间隙为center的情况就是以#字为center
   
   例如 `abcba`，插入#后即为 `#a#b#c#b#a#`

2. 定义`S`为原字符串下标
   
   定义`T`为插入#后字符串下标

   定义`P`为计算`T`每个字符为center的最大回文半径，初始值为0

   例如如下：

<font size = 6>

```
S:  a b a a b c
T: #a#b#a#a#b#c#
P: 0000000000000
```
</font>

   定义`L`，`R`为以某个字母为中心时的最大回文半径的最左边和最右边

   定义`i`， `i_m`或者`i_mirror`为某个回文序列中对应的两个字母

   例如如下：
   
   以`T[4] #`为center, `i`和`i_m`对应的两个`a`是以`C`为中心的对应字母
   
<font size = 6>

```
       L       C       R
       |       |       |
T: # a # b # a # a # b # c #
             |   |
             i_m i
```
</font>

3. 如何通过前面的center `i_mirror`的结果帮助推导后面center `i`的最大回文半径
   
- 如果`P[i_mirror] < T[i_mirror] - T[L]`，即如下图，左边a的最大回文半径没有超过以C为中心的最大回文半径，那么`P[i] = P[i_mirror]`
   
<font size = 6>

```
T: 0 1 2 3 4 5 6 7 8 9 10
       L       C       R
       |       |       |
T: # a # b # a # a # b # c #
             |   |
             i_m i
P:           1
```
</font>

    
- 如果`P[i_mirror] >= T[i_mirror] - T[L]`，即如下图，左边`b`的最大回文半径超过以`C`为中心的最大回文半径，那么至少能保证右边`b`的最大回文半径可以延伸到以`C`为中心的最大右回文半径，即`P[i] >= T[R] - T[i] = T[i_mirror] - T[L]`
    
  这时检测右边b在R以外是否可以延伸，如果可以延伸就update L，R
    
<font size = 6>

```
T: 0 1 2 3 4 5 6 7 8 9 10
       L       C       R
       |       |       |
T: # a # b # a # a # b # c #
             |   |
             i_m i
P:       3
```
</font>

4. 按照3中介绍的规则，可以从左到右依次计算`P[i]`得到下图

    
<font size = 6>

```
T: 0 1 2 3 4 5 6 7 8 9 10
T: # a # b # a # a # b # c #
P: 0 1 0 3 0 1 4 1 0 1 0 1 0    
```
</font>

## 复杂度计算

因为每次计算最大回文半径都是只计算在之前的最大回文半径最右边R的右侧是否会延伸，所以所有的字符计算过后累计的循环次数是和字符数成正比，所以复杂度为O(n)