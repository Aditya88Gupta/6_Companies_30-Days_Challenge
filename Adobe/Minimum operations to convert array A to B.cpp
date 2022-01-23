// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    // void printMat(vector<vector<int>> dpTable){
    //     for(int i=0;i<dpTable.size();i++){
    //         for(int j=0;j<dpTable[i].size();j++)
    //             cout<<dpTable[i][j]<<" ";
    //         cout<<endl;    
    //     }
    // }
    
    // bool search(int ele, int B[], int M){
    //     int low=0;
    //     int high=M-1;
    //     while(low<=high){
    //         int mid = low + (high-low);
    //         if(B[mid]==ele)
    //             return true;
    //         if(B[mid]>ele)
    //             high=mid-1;
    //         else
    //             low=mid+1;
    //     }
    //     return false;
    // }
    
    int longestSubsequence(int n, vector<int> a)
    {
        if(n==0)
            return 0;
       // last element of active subsquences
       vector<int> tailEle(n,0);
       // next empty slot
       int length=1;
       tailEle[0]=a[0];
       for(int i=1;i<n;i++){
           if(a[i]>tailEle[length-1])
               // Extend the longest active subsquence
               tailEle[length++]=a[i];
           else if(a[i]<tailEle[0])
               // new smallest element can kick off a subsquence
               tailEle[0]=a[i];
           else{
               // iter will point towards the subsquence which can be extended using a[i]
               auto iter = lower_bound(tailEle.begin(),tailEle.begin()+length,a[i]);
               *iter = a[i];
           }   
       }
       return length;
    }
    
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        vector<int> A_updated;
        unordered_set<int> B_set;
        int minOp(0);
        for(int i = 0; i < M; i++) 
            B_set.insert(B[i]);
            
        for(int i=0;i<N;i++){
            // O(1) search
            if(B_set.find(A[i])!=B_set.end())
                A_updated.push_back(A[i]);
            else
                minOp+=1;
        }
        
        int length = longestSubsequence(A_updated.size(),A_updated);
        //cout<<tmp.size()<<endl;
        
        minOp+= (M-length) + (A_updated.size()-length);
        return minOp;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends