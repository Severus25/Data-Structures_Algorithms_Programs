// Problem Statement:
// A sequence {x1, x2, .. xn} is alternating sequence if its elements satisfy one of the following relations :
// x1 < x2 > x3 < x4 > x5..... or  x1 >x2 < x3 > x4 < x5.....
// Your task is to find the longest such sequence.

// Example 1:
// Input: nums = {1,5,4}
// Output: 3
// Explanation: The entire sequenece is a 
// alternating sequence.

// Example 2:
// Input: nums = {1,17,5,10,13,15,10,5,16,8}
// Output: 7
// Explanation: There are several subsequences
// that achieve this length. 
// One is {1,17,10,13,10,16,8}.

// Problem Solution:
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		     int incr=1;
            int decr=1;
            int pre=nums[0];
            int n=nums.size();
            
            int count=1;
            int i=1;
            
            if(n==1)return 1;
            
            while(i<n-1)
            {
                if(nums[i]<pre && nums[i]<nums[i+1])
                {
                    pre=nums[i];
                    count++;
                }
                else if(nums[i] > pre && nums[i] > nums[i+1])
                {
                    pre=nums[i];
                    count++;
                }
                
                i++;
            }
            
            return count+1;
		}

};
