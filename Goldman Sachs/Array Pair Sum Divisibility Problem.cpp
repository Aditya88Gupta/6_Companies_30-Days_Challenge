// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Pairing not possible if odd number of elements
        if(nums.size()%2!=0)
            return false;
        vector<int> Map(k,0);
        // (num_1 + num_2)%k=0. if num_1%k + num_2%k = k
        // unless, num_1%k=num_2%k=0
        for(int i=0;i<nums.size();i++)
            Map[nums[i]%k]+=1;
        if(Map[0]%2!=0)
            return false;    
        for(int i=1;i<=k/2;i++){
            if(i!=k-i && Map[i]!=Map[k-i])
                return false;
            if(i==k-i && Map[i]%2!=0)
                return false;
        }    
        return true;
            
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends