// Problem Statement:
// Given an array arr[] and an integer K where K is smaller than size of array, 
// the task is to find the Kth smallest element in the given array. 
// It is given that all array elements are distinct.
// Note :-  l and r denotes the starting and ending index of the array.

// Example 1:
// Input:
// N = 6
// arr[] = 7 10 4 3 20 15
// K = 3
// Output : 7
// Explanation :
// 3rd smallest element in the given 
// array is 7.

// Example 2:
// Input:
// N = 5
// arr[] = 7 10 4 20 15
// K = 4
// Output : 15
// Explanation :
// 4th smallest element in the given 
// array is 15.

// Problem Solution:
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        sort(arr + l, arr + r + 1);
        return arr[l + k - 1];
    }
};
