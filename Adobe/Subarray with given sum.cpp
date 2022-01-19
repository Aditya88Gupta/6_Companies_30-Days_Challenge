// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector<int> res;
        long long Sum=0;
        int start=-1;
        for(int i=0;i<n;i++){
            if(start==-1)
                start=i;
            Sum+=arr[i];
            if(Sum>s){
                while(Sum>s){
                    Sum-=arr[start];
                    start++;
                }
            }
            if(Sum==s){
                res.push_back(start+1);
                res.push_back(i+1);
                break;
            }
        }
        if(res.size()==0)
            res.push_back(-1);
        return res;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends