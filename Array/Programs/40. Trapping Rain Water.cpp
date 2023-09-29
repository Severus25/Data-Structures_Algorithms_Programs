// Problem Statement:
// Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, 
// compute how much water can be trapped between the blocks during the rainy season. 

// Example 1:
// Input:
// N = 6
// arr[] = {3,0,0,2,0,4}
// Output:
// 10

// Example 2:
// Input:
// N = 4
// arr[] = {7,4,0,9}
// Output:
// 10
// Explanation:
// Water trapped by above 
// block of height 4 is 3 units and above 
// block of height 0 is 7 units. So, the 
// total unit of water trapped is 10 units.

// Example 3:
// Input:
// N = 3
// arr[] = {6,9,9}
// Output:
// 0
// Explanation:
// No water will be trapped.

// Problem Solution:
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int maxl[n];
        int maxr[n];
         maxl[0]=arr[0];
         maxr[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            maxl[i]=max(maxl[i-1],arr[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            maxr[i]=max(maxr[i+1],arr[i]);
        }
        
        int water[n];
        
        for(int i=0;i<n;i++){
            water[i]=min(maxl[i],maxr[i])-arr[i];
        }
       long long sum=0;
         for(int i=0;i<n;i++){
           sum=sum+water[i];
        }
        return sum;
    }
};
