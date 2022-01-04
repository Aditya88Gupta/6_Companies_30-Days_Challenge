// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    long long numberOfSquares(int n){
        // code here 
        return (n * (n + 1) / 2) * (2 * n + 1) / 3;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int n;
    cin>>n;
    Solution ob;
    cout<<ob.numberOfSquares(n)<<endl;
    return 0; 
} 
  // } Driver Code Ends