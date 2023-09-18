// Problem Statement:
// Quick Sort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot.
// Given an array arr[], its starting position is low (the index of the array) and its ending position is high(the index of the array).
// Note: The low and high are inclusive.
// Implement the partition() and quickSort() functions to sort the array.

// Example 1:
// Input: 
// N = 5 
// arr[] = { 4, 1, 3, 9, 7}
// Output:
// 1 3 4 7 9

// Example 2:
// Input: 
// N = 9
// arr[] = { 2, 1, 6, 10, 4, 1, 3, 9, 7}
// Output:
// 1 1 2 3 4 6 7 9 10

// Problem Solution:
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
         if(low<high){
            int p=partition(arr, low, high);
            quickSort(arr, low, p-1);
            quickSort(arr, p+1, high);
    }
        }
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
        int pivot = low;
        int i=low;
        int j=high;
        
        while(i<j){
            while(arr[i]<=arr[pivot]){
                i++;
            }
            while(arr[j]>arr[pivot]){
                j--;
            }
            if(i<j){
                swap(arr[j], arr[i]);
            }
        }
        swap(arr[j], arr[pivot]);
        return j;
    }
};
