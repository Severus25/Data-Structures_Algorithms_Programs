// Problem Statement:
// Given an unsorted array Arr of size N of positive integers. One number 'A' from 
// set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.

// Example 1:
// Input:
// N = 2
// Arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and 
// smallest positive missing number is 1.

// Example 2:
// Input:
// N = 3
// Arr[] = {1, 3, 3}
// Output: 3 2
// Explanation: Repeating number is 3 and 
// smallest positive missing number is 2.

// Problem Solution:
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> ans;
        int x,y;
        sort(arr.begin(),arr.end());
        for(int i=0; i<n-1; i++){
            if(arr[i]==arr[i+1]){
                x = arr[i];
            }
            else if(arr[i+1] == arr[i]+2){
                y = arr[i]+1;
            }
        }
        if(arr[0]!=1){
            y = 1;
        }
        else if(arr[n-1]!=n){
            y = n;
        }
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};
