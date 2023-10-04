// Problem Statement:
// The cost of stock on each day is given in an array A[] of size N. Find all the segments of days 
// on which you buy and sell the stock so that in between those days for which profit can be generated.
// Note: Since there can be multiple solutions, the driver code will print 1 if your answer is correct, 
// otherwise, it will return 0. In case there's no profit the driver code will print the string "No Profit" for a correct solution.

// Example 1:
// Input:
// N = 7
// A[] = {100,180,260,310,40,535,695}
// Output:
// 1
// Explanation:
// One possible solution is (0 3) (4 6)
// We can buy stock on day 0,
// and sell it on 3rd day, which will 
// give us maximum profit. Now, we buy 
// stock on day 4 and sell it on day 6.

// Example 2:
// Input:
// N = 5
// A[] = {4,2,2,2,4}
// Output:
// 1
// Explanation:
// There are multiple possible solutions.
// one of them is (3 4)
// We can buy stock on day 3,
// and sell it on 4th day, which will 
// give us maximum profit.

// Problem Solution:
class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        int first=0;
        int maxi=0;
        vector<vector<int>>ans;
        for(int i=1;i<n;i++){
            int ans1=A[i]-A[first];
            if(maxi<ans1){
                maxi=ans1;
                if(i==n-1){
                    vector<int>res;
                    res.push_back(first);
                    res.push_back(i);
                    ans.push_back(res);
                    maxi=0;
                }
            }
            else{
                if(maxi>=1){
                vector<int>res;
                res.push_back(first);
                res.push_back(i-1);
                ans.push_back(res);
                maxi=0;
                }
               
                first=i;
            }
        }
        return ans;
    }
};
