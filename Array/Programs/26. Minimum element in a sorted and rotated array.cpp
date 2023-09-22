// Problem Statement:
// A sorted(in ascending order) array A[ ] with distinct elements is rotated at some unknown point, 
// the task is to find the minimum element in it.

// Example 1
// Input:
// N = 5
// arr[] = {4 ,5 ,1 ,2 ,3}
// Output: 1
// Explanation: 1 is the minimum element in the array.

// Example 2
// Input:
// N = 7
// arr[] = {10, 20, 30, 40, 50, 5, 7}
// Output: 5
// Explanation: Here 5 is the minimum element.

// Problem Solution:
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        int s=0,e=n-1;
        
        while(s<e){
            int m=s+(e-s)/2;
            if(arr[s]<=arr[m] && arr[s]>=arr[e]){
                s=m+1;
            }
            else{
                e=m;
            }
        }
        return arr[s];
    }
};
