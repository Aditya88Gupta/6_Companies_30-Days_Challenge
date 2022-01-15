void DFS(vector<int> adj[], int v, bool visited[])
	{
        visited[v] = true;
        vector<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i]) 
                DFS(adj, *i, visited);
    }
    bool isConnected(vector<int> adj[], int V, int one, int two) 
    {
        bool visited[V] = {0};
        memset(visited, false, sizeof(visited));
        DFS(adj, one, visited);
        if (visited[two] == false) 
            return false;
        return true;
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        if (!isConnected(adj, V, c, d))
            return 0;
        else
        {
            adj[c].erase(remove(adj[c].begin(), adj[c].end(), d), adj[c].end());
            adj[d].erase(remove(adj[d].begin(), adj[d].end(), c), adj[d].end());
            if (isConnected(adj, V, c, d))
                return 0;
            else
                return 1;
        }
    }
};