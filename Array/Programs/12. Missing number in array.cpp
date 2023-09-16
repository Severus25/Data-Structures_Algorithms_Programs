// Problem Statement:
// Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

// Example 1:
// Input:
// N = 5
// A[] = {1,2,3,5}
// Output: 4

// Example 2:
// Input:
// N = 10
// A[] = {6,1,2,8,3,4,7,10,5}
// Output: 9

// Problem Solution:
class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        
        int actual_sum = (n*(n+1)) / 2;
        int calculate_sum = 0;
        
        for(int i=0;i<=n-2;i++){
            calculate_sum += array[i];
        }
        return actual_sum - calculate_sum;
    }
};
