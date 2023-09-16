// Problem Statement:
// Given an array, rotate the array by one position in clock-wise direction.

// Example 1:
// Input:
// N = 5
// A[] = {1, 2, 3, 4, 5}
// Output:
// 5 1 2 3 4
 
// Example 2:
// Input:
// N = 8
// A[] = {9, 8, 7, 6, 4, 2, 1, 3}
// Output:
// 3 9 8 7 6 4 2 1

// Problem Solution:
void rotate(int arr[], int n)
{
    int a =arr[n-1];
    
    for(int i =n-1 ;i>0;i--)
    {
        swap(arr[i] , arr[i-1]);
    }
}
