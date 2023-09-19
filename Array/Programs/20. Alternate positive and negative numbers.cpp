// Problem Statement:
// Given an unsorted array Arr of N positive and negative numbers. 
// Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
// Note: Array should start with a positive number and 0 (zero) should be considered a positive element.
 
// Example 1:
// Input: 
// N = 9
// Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
// Output:
// 9 -2 4 -1 5 -5 0 -3 2
// Explanation : Positive elements : 9,4,5,0,2
// Negative elements : -2,-1,-5,-3
// As we need to maintain the relative order of
// postive elements and negative elements we will pick
// each element from the positive and negative and will
// store them. If any of the positive and negative numbers
// are completed. we will continue with the remaining signed
// elements.The output is 9,-2,4,-1,5,-5,0,-3,2.

// Example 2:
// Input:
// N = 10
// Arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
// Output:
// 5 -5 2 -2 4 -8 7 1 8 0
// Explanation : Positive elements : 5,2,4,7,1,8,0
// Negative elements : -5,-2,-8
// As we need to maintain the relative order of
// postive elements and negative elements we will pick
// each element from the positive and negative and will
// store them. If any of the positive and negative numbers
// are completed. we will continue with the remaining signed
// elements.The output is 5,-5,2,-2,4,-8,7,1,8,0.

// Problem Solution:
class Solution{
public:

	void rearrange(int arr[], int n) {
	    int start=0;
        int end=n-1;
        int nums[n];
        for(int i=0; i<n; i++){
            if(arr[i]>=0) nums[start++]=arr[i];
            else if(arr[i]<0) nums[end--]=arr[i];          
        }
        int s=0;
        int e=n-1;
        for(int i=0;i<n;){
	        if(s<start){
	            arr[i]=nums[s++];
	            i++;
	        }
	        if(e>end){
	            arr[i]=nums[e--];
	            i++;
	        }
	    }
	}
};
