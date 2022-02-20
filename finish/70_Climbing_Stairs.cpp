/*
70. Climbing Stairs
Easy

5595

178

Add to List

Share
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        // if (n == 2)
        //     return 2;
        
        // return climbStairs(n - 1) + climbStairs(n - 2); // 复杂度太高

        int * cs = new int [n + 1];

        cs[1] = 1;
        cs[0] = 1;

        for (int i = 2; i <=n; ++i){
            cs[i] = cs[i - 1] + cs[i - 2];
        }

        int result = cs[n];

        delete [] cs;

        return result;
    }
};

int main(){
    int n;
    Solution sol;

    n = 3;
    cout << sol.climbStairs(n) << endl;

    return 0;
}