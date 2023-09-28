// Problem Statement:
// You are given an array arr[] of N integers. The task is to find the smallest positive number missing from the array.
// Note: Positive number starts from 1.

// Example 1:
// Input:
// N = 5
// arr[] = {1,2,3,4,5}
// Output: 6
// Explanation: Smallest positive missing 
// number is 6.

// Example 2:
// Input:
// N = 5
// arr[] = {0,-10,1,3,-20}
// Output: 2
// Explanation: Smallest positive missing 
// number is 2.

// Problem Solution:
class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        sort(arr,arr+n);
        int j=0;
        while(arr[j]<=0)
        {
            j++;
        }
        for(int i=1;i<=n;i++)
        {
            if(arr[j]!=i ) return i;
            
            if(arr[j]==arr[j+1])
            {
                i--;
            }
            j++;
        }
    } 
};
