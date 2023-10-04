// Problem Statement:
// Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

// Example 1:
// Input: N = 4
// arr = {1, 5, 11, 5}
// Output: YES
// Explanation: 
// The two parts are {1, 5, 5} and {11}.

// Example 2:
// Input: N = 3
// arr = {1, 3, 5}
// Output: NO
// Explanation: This array can never be 
// partitioned into two such parts.

// Problem Solution:
class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = accumulate(arr, arr + N, 0);
        if(sum & 1) return 0;
        vector<vector<bool>> dp(N, vector<bool>(sum + 1, false));
        dp[0][0] = true;

        for(int i = 1; i < N; i++) {
            for(int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                
                if(j - arr[i] >= 0)
                    dp[i][j] = dp[i][j] | dp[i - 1][j - arr[i]];
            }
        }
        
        return (int) dp[N - 1][sum / 2];
    }
};
