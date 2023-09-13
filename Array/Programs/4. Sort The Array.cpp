// Problem Statement:
// Given a random set of numbers, Print them in sorted order.

// Example 1:
// Input:
// N = 4
// arr[] = {1, 5, 3, 2}
// Output: {1, 2, 3, 5}
// Explanation: After sorting array will 
// be like {1, 2, 3, 5}.

// Example 2:
// Input:
// N = 2
// arr[] = {3, 1}
// Output: {1, 3}
// Explanation: After sorting array will
// be like {1, 3}.

// Problem Solution:
class Solution{
    public:
    vector<int> sortArr(vector<int>arr, int n){
    sort(arr.begin(), arr.end());
    return arr;
    }
};
