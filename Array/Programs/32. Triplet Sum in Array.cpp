// Problem Statement:
// Given an array arr of size n and an integer X. 
// Find if there's a triplet in the array which sums up to the given integer X.

// Example 1:
// Input:
// n = 6, X = 13
// arr[] = [1 4 45 6 10 8]
// Output:
// 1
// Explanation:
// The triplet {1, 4, 8} in 
// the array sums up to 13.

// Example 2:
// Input:
// n = 5, X = 10
// arr[] = [1 2 4 3 6]
// Output:
// 1
// Explanation:
// The triplet {1, 3, 6} in 
// the array sums up to 10.

// Problem Solution:
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
     bool find3Numbers(int a[], int n, int x)
    {
      sort(a,a+n);
      for(int i=0;i<n;i++)
      {
        int t=x-a[i];
        int j=i+1,k=n-1;
        while(j<k)
        {
            if(a[j]+a[k]==t)
            {
                return 1;
            }
            else if(a[j]+a[k]>t){
                k--;
            }
            else if(a[j]+a[k]<t)
            {
                j++;
            }
        }
      }
      return 0;
    }
};
