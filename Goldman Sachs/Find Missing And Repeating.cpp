// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // Use arr as hash map
        // static cuz local array cannot be returned
        static int res[2]={-1,-1};
        for(int i=0;i<n;i++)
            arr[arr[i]%(n+1)-1]+=(n+1);
        for(int i=0;i<n;i++){
            // Missing number will have sum<n+1
            if(arr[i]<(n+1))
                res[1]=i+1;
            // repeated number will have sum>2(n+1)     
            if(arr[i]>2*(n+1))
                res[0]=i+1;
            //cout<<arr[i]<<" ";
        }    
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends