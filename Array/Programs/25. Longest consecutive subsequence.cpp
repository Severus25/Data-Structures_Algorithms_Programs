// Problem Statement:
// Given an array of positive integers. 
// Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, 
// the consecutive numbers can be in any order.
 
// Example 1:
// Input:
// N = 7
// a[] = {2,6,1,9,4,5,3}
// Output:
// 6
// Explanation:
// The consecutive numbers here
// are 1, 2, 3, 4, 5, 6. These 6 
// numbers form the longest consecutive
// subsquence.

// Example 2:
// Input:
// N = 7
// a[] = {1,9,3,10,4,20,2}
// Output:
// 4
// Explanation:
// 1, 2, 3, 4 is the longest
// consecutive subsequence.

// Problem Solution:
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int mp[1000000]={0};
      int maxi=-1e9;
      int mini=1e9;
      
      for(int i=0;i<N;i++)
      {
          mp[arr[i]]=1;
          mini=min(arr[i],mini);
          maxi=max(arr[i],maxi);
      }
      
      int ans=0;
      int cnt=0;
      
      for(int i=mini;i<=maxi;i++)
      {
          if(mp[i]==0)
          {
              ans=max(cnt,ans);
              cnt=0;
          }
          else
          cnt++;
      }
      ans=max(cnt,ans);
      return ans;
    }
};
