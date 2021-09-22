#include "algm.h"

//动态规划
//注意三点：重叠子问题、最优子结构、状态转移方程

//斐波那契数列
//暴力递归
int fib(int N){
    if(N == 1 || N == 2) return 1;
    return fib(N-1) + fib(N - 2);
}

//带备忘录。通过一个数组来记录是否计算过，避免重复计算
int fib(int N){
    if(N < 1) return 0;
    vector<int> memo(N+1,0);
    return helper(memo,N);
}
int helper(vector<int> &memo,int n){
    if(n == 1 || n == 2) return 1;
    if(memo[n] != 0) return memo[n];
    memo[n] = helper(memo,n-1) + helper(memo,n-2);
    return  memo[n];
}

//动态规划
int fib(int N){
    if(N < 1) return 0;
    vector<int> dp(N+1,0);
    dp[1] = 1,dp[2] = 1;
    for(int i = 3; i <= N; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[N];
}



//凑零钱问题
