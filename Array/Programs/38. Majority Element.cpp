// Problem Statement:
// Given an array A of N elements. Find the majority element in the array. A majority element in an array A of 
// size N is an element that appears strictly more than N/2 times in the array.

// Example 1:
// Input:
// N = 3 
// A[] = {1,2,3} 
// Output:
// -1
// Explanation:
// Since, each element in 
// {1,2,3} appears only once so there 
// is no majority element.

// Example 2:
// Input:
// N = 5 
// A[] = {3,1,3,3,2} 
// Output:
// 3
// Explanation:
// Since, 3 is present more
// than N/2 times, so it is 
// the majority element.

// Problem Solution:
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        int count = 0 , el;
        for(int i = 0 ; i < size ; i++){
            if(count == 0){
                count++;
                el = a[i] ;
            }
            else if(el == a[i]){
                count++;
            }
            else{
                count--;
            }
        }
        
        int count1 = 0 ;
        for(int i = 0 ; i < size ; i++){
            if(a[i] == el){
                count1++;
            }
        }
        
        if(count1 > (size/2)){
            return el ;
        }
        
        return -1 ;
    }
};
