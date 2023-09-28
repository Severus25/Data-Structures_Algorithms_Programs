// Problem Statement:
// Given a matrix of size r*c. Traverse the matrix in spiral form.

// Example 1:
// Input:
// r = 4, c = 4
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12},
//            {13, 14, 15,16}}
// Output: 
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
  
// Example 2:
// Input:
// r = 3, c = 4  
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12}}
// Output: 
// 1 2 3 4 8 12 11 10 9 5 6 7
// Explanation:
// Applying same technique as shown above, 
// output for the 2nd testcase will be 
// 1 2 3 4 8 12 11 10 9 5 6 7.

// Problem Solution:
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> v;
        int top=0,bottom=r-1;
        int left=0,right=c-1;
        while(top<=bottom && left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                v.push_back(matrix[top][i]);
                
            }
            top++;
            
            for(int i=top;i<=bottom;i++)
            {
                v.push_back(matrix[i][right]);
            }
            right--;
            
            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                {
                    v.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    v.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return v;
    }
};
