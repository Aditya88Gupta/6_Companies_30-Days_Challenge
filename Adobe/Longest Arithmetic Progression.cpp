// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int arr[], int n) {
        if(n<=2)
            return n;
        int maxLen=2;  
        // dpTable[i]-> AP's ending at arr[i]
        // dpTable[i][diff] -> AP ending at arr[i] with d==diff
        vector<unordered_map<int,int>> dpTable(n,unordered_map<int,int>());
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = arr[i]-arr[j];
                // If there is an AP with arr[j] as it's last element, and diff as common diff
                if(dpTable[j].find(diff)!=dpTable[j].end()){
                    // Update that AP
                    dpTable[i][diff]=dpTable[j][diff]+1;
                }else{
                    dpTable[i][diff]=2;
                }
                maxLen = max(dpTable[i][diff],maxLen);
            }
        }
        return maxLen;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends