// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    // int countWays(int n, int x, int num, long long count)
    // {
    //     // code here
    //     if(n==0)
    //         return 1;
    //     if(pow(num,x)>n)
    //         return 0;
    //     long long tmp=countWays(n,x,num+1,count)%1000000007;
    //     tmp+=countWays(n-pow(num,x),x,num+1,count)%1000000007;
    //     return tmp;
    // }
    long long numOfWays(int n, int x)
    {
        // code here
        vector<long long>dpTable(n+1,0);
        int i=2;
        dpTable[0]=1;
        dpTable[1]=1;
        while(pow(i,x)<=n){
            int cur = pow(i,x);
            for(int j=n;j>=cur;j--){
                dpTable[j]+=dpTable[j-cur]%1000000007;
            }
            i++;
        }
        return dpTable[n]%1000000007;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends