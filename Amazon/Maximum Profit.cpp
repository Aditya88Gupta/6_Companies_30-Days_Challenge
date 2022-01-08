// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void printMat(vector<vector<int>> dpTable, int k, int n){
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++)
                cout<<dpTable[i][j]<<" ";
            cout<<endl;    
        }
    }
    
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<int>> dpTable(K+1,vector<int>(N,0));
        
        for(int i=1;i<=K;i++){
            int Max=INT_MIN;
            for(int j=1;j<N;j++){
                Max=max(Max,dpTable[i-1][j-1]-A[j-1]);
                dpTable[i][j]=max(dpTable[i][j-1],Max+A[j]);
            }
        }
        
        //printMat(dpTable,K+1,N);
        return dpTable[K][N-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends