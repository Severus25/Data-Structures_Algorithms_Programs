// Problem Statement:
// Given a vector of N positive integers and an integer X. The task is to find the frequency of X in vector.

// Example 1:
// Input:
// N = 5
// vector = {1, 1, 1, 1, 1}
// X = 1
// Output: 
// 5
// Explanation: Frequency of 1 is 5.

// Problem Solution:
int findFrequency(vector<int> v, int x){
    // Your code here
    int frequency = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == x) {
            frequency++;
        }
    }
    return frequency;
}
