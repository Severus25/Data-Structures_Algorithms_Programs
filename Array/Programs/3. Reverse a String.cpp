// Problem Statement:
// You are given a string s. You need to reverse the string.

// Example 1:
// Input:
// s = Geeks
// Output: skeeG

// Example 2:
// Input:
// s = for
// Output: rof

// Problem Solution:
class Solution
{
    public:
    string reverseWord(string str)
    {
        int left = 0;
        int right = str.length() - 1;
    
        while (left < right) {
            swap(str[left], str[right]);
            left++;
            right--;
        }
        return str;
    }
};
