// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  int calDays(int weights[], int N, int limit){
        
        int curCap=weights[0];
        int days=1;
        for(int i=1;i<N;i++){
            if(curCap+weights[i]<=limit)
                curCap+=weights[i];
            else{
                curCap=weights[i];
                days++;
            }
        }
        return days;
    }
    
    int leastWeightCapacity(int weights[], int N, int days) {
        int low=INT_MIN;
        int high=0;
        for(int i=0;i<N;i++){
            high+=weights[i];
            low=max(low,weights[i]);
        }
        
        while(low<high){
            int mid = low+(high-low)/2;
            int reqDays = calDays(weights,N,mid);
            if(reqDays<=days)
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends