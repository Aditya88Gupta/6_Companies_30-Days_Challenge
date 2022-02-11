// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    void dfs(int vertex, vector<int> adj[], int c, int d, vector<bool>& Visited){
        Visited[vertex]=true;
        for(int i=0;i<adj[vertex].size();i++){
            if(Visited[adj[vertex][i]]==false){
                if((vertex!=c || adj[vertex][i]!=d))
                    dfs(adj[vertex][i],adj,c,d,Visited);    
            }
        }
    }
    
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool> Visited(V,false);
        dfs(c,adj,c,d,Visited);
        return !Visited[d];        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends