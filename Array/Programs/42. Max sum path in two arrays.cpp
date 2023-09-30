// Problem Statement:
// Given two sorted arrays A and B of size M and N respectively. Each array may have some 
// elements in common with the other array. Find the maximum sum of a path from the beginning 
// of any array to the end of any of the two arrays. We can switch from one array to another array 
// only at the common elements.Both the arrays are sorted.
// Note: Only one repeated value is considered in the valid path sum.

// Example 1:
// Input:
// M = 5, N = 4
// A[] = {2,3,7,10,12}
// B[] = {1,5,7,8}
// Output: 35
// Explanation: The path will be 1+5+7+10+12
// = 35.

// Example 2:
// Input:
// M = 3, N = 3
// A[] = {1,2,3}
// B[] = {3,4,5}
// Output: 15
// Explanation: The path will be 1+2+3+4+5=15.

// Problem Solution:
class Solution{
    public:
    /*You are required to complete this method*/
     int max_path_sum(int A[], int B[], int l1, int l2)
    {
    
        //Your code here
        int sum1=0,sum2=0,ans=0,i=0,j=0;
        while(i<l1 && j<l2)
        {
            if(A[i]<B[j])
            {
                sum1+=A[i];
                i++;
            }
            else if(A[i]>B[j])
            {
                sum2+=B[j];
                j++;
            }
            else
            {
                ans+=max(sum1,sum2);
                sum1=0,sum2=0;
                ans+=A[i];
                i++;
                j++;
            }
        }
        while(i<l1)
         sum1+=A[i++];
        while(j<l2)
         sum2+=B[j++];
        ans+=max(sum1,sum2);
        return ans;
        
    }
};
