// Problem Statement:
// Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array(In Place).
// In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....
// If there are multiple solutions, find the lexicographically smallest one.
// Note:The given array is sorted in ascending order, and you don't need to return anything to make changes in the original array itself.

// Example 1:
// Input:
// n = 5
// arr[] = {1,2,3,4,5}
// Output: 2 1 4 3 5
// Explanation: Array elements after 
// sorting it in wave form are 
// 2 1 4 3 5.

// Example 2:
// Input:
// n = 6
// arr[] = {2,4,7,8,9,10}
// Output: 4 2 8 7 10 9
// Explanation: Array elements after 
// sorting it in wave form are 
// 4 2 8 7 10 9.

// Problem Solution:
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
         if(n&1){
            for(int i=0;i<n-2;){
                swap(arr[i],arr[i+1]);
                i+=2;
            }
        }
        else{
            for(int i=0;i<n;){
                swap(arr[i],arr[i+1]);
                i+=2;
            }
        }
    }
};
