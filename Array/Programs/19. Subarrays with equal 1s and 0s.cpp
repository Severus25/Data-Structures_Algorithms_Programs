// Problem Statement:
// Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.

// Example 1:
// Input:
// n = 7
// A[] = {1,0,0,1,0,1,1}
// Output: 8
// Explanation: The index range for the 8 
// sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), 
// (4, 5) ,(2, 5), (0, 5), (1, 6)

// Example 2:
// Input:
// n = 5
// A[] = {1,1,1,1,0}
// Output: 1
// Explanation: The index range for the 
// subarray is (3,4).

// Problem Solution:
class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        long long int ans = 0;
        unordered_map<int,int>map; int count = 0; map[0]=1;
        for(int i=0;i<n;i++){
           count += (arr[i]==0)?-1:1;
           if(map.find(count)!=map.end()) ans+=map[count];
           map[count]++;
    }
        return ans;
    }
};
