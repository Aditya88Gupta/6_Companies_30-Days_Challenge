// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    int count;
    int n,m;
    public:
    //Function to find unit area of the largest region of 1s.
    
    void DFS(vector<vector<int>>& grid, int i, int j){
        if(i>=0 && j>=0 && i<n && j<m){
            if(grid[i][j]==0)
                return;
            count+=1;
            grid[i][j]=0;
            DFS(grid,i+1,j);
            DFS(grid,i-1,j);
            DFS(grid,i,j+1);
            DFS(grid,i,j-1);
            DFS(grid,i+1,j+1);
            DFS(grid,i-1,j-1);
            DFS(grid,i+1,j-1);
            DFS(grid,i-1,j+1);
        }
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        n=grid.size();
        m=grid[0].size();
        int res(0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    count=0;
                    DFS(grid,i,j);
                    res=max(res,count);
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends