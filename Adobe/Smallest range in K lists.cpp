// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range

// ele, list, idx
typedef pair<int,pair<int,int>> pi;

class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k){
        
        // Min Heap, will contain one element from each list
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        int curMax = INT_MIN;
        for(int i=0;i<k;i++){
            if(arr[i][0]>curMax)
                curMax=arr[i][0];
            pq.push(make_pair(arr[i][0],make_pair(i,0)));
        }
        
        // lower&upper bound
        int Min = 0;
        int Max = 100000;
        
        
        // curMin && curMax are the min and max elements currently in the pq
        while(!pq.empty()){
            int curMin = pq.top().first;
            // if we have a better range
            if(curMax-curMin<Max-Min){
                Max = curMax;
                Min = curMin;
            }
            // next element of the list from which curMin was extracted
            int x = pq.top().second.first;
            int y = pq.top().second.second+1;
            pq.pop();
            // if a list has been completed processed then exit
            if(y==n)
                break;
            if(curMax<arr[x][y])
                curMax=arr[x][y];
            pq.push(make_pair(arr[x][y],make_pair(x,y)));    
        }
        
        return make_pair(Min,Max);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends