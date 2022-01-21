// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
    vector<vector<int>> dpTable;
public:

    int optimalCoins(int i, int j, vector<int>&A){
        if(i>j)
            return 0;
        if(i==j)
            return A[i];
        if(i+1==j)
            return max(A[i],A[j]);
        if(dpTable[i][j]==0){
            // cuz opponent will also choose optimally, we have to 
            // choose the optimal path in which the opponent will score minimum
            int tmp1= A[i]+min(optimalCoins(i+2,j,A),optimalCoins(i+1,j-1,A));
            int tmp2= A[j]+min(optimalCoins(i+1,j-1,A),optimalCoins(i,j-2,A));
            dpTable[i][j]=max(tmp1,tmp2);
        }   
        return dpTable[i][j];
    }
    
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    for(int i=0;i<n;i++){
	        dpTable.push_back(vector<int>());
	        for(int j=0;j<n;j++){
	            dpTable[i].push_back(0);
	        }
	    }
	    
	    return optimalCoins(0,n-1,A);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends