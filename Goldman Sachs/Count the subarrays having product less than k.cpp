/ { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int count = 0;
        long long prd = 1;
        int len = 0;
        int index = -1;
        // O(n)
        for(int i=0;i<n;i++){
            // if element is >=k, then fresh start
            if(a[i]>=k){
                prd=1;
                len=0;
                index=-1;
            }
            else if(prd*a[i]<k){
                len++;
                count+=len;
                prd=prd*a[i];
                if(index==-1)
                    index=i;
            }else{
                // if product > k, then remove elements from the start 
                prd=prd*a[i];
                while(prd>=k){
                    prd=prd/a[index];
                    index++;
                    len--;
                }
                len++;
                count+=len;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends