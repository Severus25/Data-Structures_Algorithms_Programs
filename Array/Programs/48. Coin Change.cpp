// Problem Statement:
// Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, 
// find the number of ways you can make sum by using different combinations from coins[ ].  
// Note: Assume that you have an infinite supply of each type of coin. And you can use any coin as many times as you want.

// Example 1:
// Input:
// N = 3, sum = 4
// coins = {1,2,3}
// Output: 4
// Explanation: Four Possible ways are: {1,1,1,1},{1,1,2},{2,2},{1,3}.

// Example 2:
// Input:
// N = 4, Sum = 10
// coins = {2,5,3,6}
// Output: 5
// Explanation: Five Possible ways are: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.

// Problem Solution:
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<long long> dp(sum + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = coins[i]; j <= sum; j++) {
                dp[j] = (dp[j] + dp[j - coins[i]]);
            }
        }
        return dp[sum];
    }
};
