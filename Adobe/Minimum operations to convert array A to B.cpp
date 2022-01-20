// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        vector<int> tmp;
        sort(A,A+N);
        tmp.push_back(A[0]);
        int i=1;
        while(i<N){
            if(A[i-1]!=A[i])
                tmp.push_back(A[i]);
            i+=1;    
        }
        int opCount = N - tmp.size();
        i = 0;
        int j = 0;
        while(i<M && j<tmp.size()){
            if(tmp[j]==B[i]){
                j++;
                i++;
            }else if(tmp[j]<B[i]){
                opCount+=1;
                j++;
            }else{
                opCount+=1;
                i++;
            }
        }
        opCount+=(M-i);
        opCount+=tmp.size()-j;
        return opCount;
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