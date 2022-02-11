// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

#define mod 1000000007;

class Solution
{
  public:
    
    void printMat(vector<vector<long long>> dpTable){
        for(int i=0;i<dpTable.size();i++){
            for(int j=0;j<dpTable[i].size();j++)
                cout<<dpTable[i][j]<<" ";
            cout<<endl;    
        }
    }
    
    int kvowelwords(int N, int K) {
        // total vowels in a word can be > K
        vector<vector<long long>> dpTable(N+1,vector<long long>(K+1,0));
        for(int i=0;i<=N;i++){
            for(int j=0;j<=K;j++){
                // no places available
                if(i==0){
                    dpTable[i][j]=1;
                }
                else{
                    // Add a consonant at the new place
                    dpTable[i][j] = (dpTable[i-1][K]*21)%mod;
                    // dpTable[i-1][K] = distinct words of len i-1 with K max contiguous vowels
                    if(j>0){
                        // Add a vowel at the new place
                        // j-1 cuz if new vowel is added to a section of contiguous vowels
                        // total wil still be <= j
                        long long tmp = (dpTable[i-1][j-1]*5)%mod;
                        dpTable[i][j] = (dpTable[i][j]+tmp)%mod;
                    }
                }
            }
        }
        printMat(dpTable);
        return dpTable[N][K];
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends