// Problem Statement:
// Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) 
// which has the maximum sum and return its sum.

// Example 1:
// Input:
// N = 5
// Arr[] = {1,2,3,-2,5}
// Output:
// 9
// Explanation:
// Max subarray sum is 9
// of elements (1, 2, 3, -2, 5) which 
// is a contiguous subarray.

// Example 2:
// Input:
// N = 4
// Arr[] = {-1,-2,-3,-4}
// Output:
// -1
// Explanation:
// Max subarray sum is -1 
// of element (-1)

// Problem Solution:
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        //Kadane's Algo
        long long curSum=0,maxSum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            curSum+=arr[i];
            if(curSum>maxSum)
                maxSum=curSum;
            if(curSum<0)
                curSum=0;
        }
        return maxSum;
        
    }
};
