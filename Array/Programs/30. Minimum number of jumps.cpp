// Problem Statement:
// Given an array of N integers arr[] where each element represents the maximum length of the 
// jump that can be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x.
// Find the minimum number of jumps to reach the end of the array (starting from the first element). 
// If an element is 0, then you cannot move through that element.
// Note: Return -1 if you can't reach the end of the array.

// Example 1:
// Input:
// N = 11 
// arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
// Output: 3 
// Explanation: 
// First jump from 1st element to 2nd 
// element with value 3. Now, from here 
// we jump to 5th element with value 9, 
// and from here we will jump to the last. 

// Example 2:
// Input :
// N = 6
// arr = {1, 4, 3, 2, 6, 7}
// Output: 2 
// Explanation: 
// First we jump from the 1st to 2nd element 
// and then jump to the last element.

// Problem Solution:
class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        
        int jump=0,curr_jump=0,farthest=0;
        for(int i=0;i<n-1;i++)
        {
            farthest=max(farthest,i+arr[i]);// it calculates the maximum index 
                                             //at which frog can jump from index i
             if(i==farthest)// idx at which frog cannot jump further
             {
                 return -1;
             }
             //frog is at ith index which is his  curr pos jumping to maxm idx
             if(i==curr_jump)
             {
                 jump++;
                 curr_jump=farthest;
             }
        }
        return jump;     
    }
};
