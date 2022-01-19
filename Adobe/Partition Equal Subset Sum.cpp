// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void printMat(vector<vector<bool>> possibleSums){
        for(int i=0;i<possibleSums.size();i++){
            for(int j=0;j<possibleSums[i].size();j++)
                cout<<possibleSums[i][j]<<" ";
            cout<<endl;    
        }
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        if(N==1)
            return true;
        int target = accumulate(arr, arr+N, 0);
        if(target%2!=0)
            return false;
        target=target/2;    
        vector<vector<bool>> possibleSums(N+1,vector<bool>(target+1,false));
        for(int i=1;i<=N;i++){
            for(int j=1;j<=target;j++){
                possibleSums[i][j]=possibleSums[i-1][j];
                if(j==arr[i-1])
                    possibleSums[i][j]=true;
                else if(j>arr[i-1])
                    possibleSums[i][j]=possibleSums[i-1][j-arr[i-1]];
                if(possibleSums[i][j]==false)
                    possibleSums[i][j]=possibleSums[i-1][j];
            }
        }
        //printMat(possibleSums);
        return possibleSums[N][target];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends