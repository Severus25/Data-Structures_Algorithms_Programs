// Problem Statement:
// Find the first non-repeating element in a given array arr of N integers.
// Note: Array consists of only positive and negative integers and not zero.

// Example 1:
// Input : arr[] = {-1, 2, -1, 3, 2}
// Output : 3
// Explanation:
// -1 and 2 are repeating whereas 3 is 
// the only number occuring once.
// Hence, the output is 3. 
 
// Example 2:
// Input : arr[] = {1, 1, 1}
// Output : 0

// Problem Solution:
class Solution{
    public:
    int firstNonRepeating(int arr[], int n) 
    { 
        unordered_map<int, int> umap;
        for(int i = 0; i<n; i++){
            int key = arr[i];
            umap[key]++;
        }
        for(int i = 0; i<n; i++){
            int key = arr[i];
            auto temp = umap.find(key);
            if(temp->second == 1){
                return key;
            }
        }
        return 0;
    } 
  
};
