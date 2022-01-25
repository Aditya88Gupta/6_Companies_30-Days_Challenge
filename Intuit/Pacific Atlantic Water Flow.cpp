vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size() , m = heights[0].size() ; 
        int dx[4] = {-1 , 0 , 1 , 0} ;
        int dy[4] = {0 , -1 , 0 , 1} ;
        vector<vector<bool>> atlantic(n , vector<bool>(m , 0)) , pacific(n , vector<bool>(m , 0)) ;
        vector<vector<int>> ans ; 
        
        auto isValid = [&](int x , int y , int from , vector<vector<bool>> &vis){
            if(x < 0 || x >= n || y < 0 || y >= m || from > heights[x][y] || vis[x][y])  return false ; 
            else    return true ;
        };
        
        function<void(int x , int y , vector<vector<bool>> &vis)> dfs = [&](int x , int y , vector<vector<bool>> &vis){
            vis[x][y] = 1 ;
            for(int i = 0 ; i < 4 ; i++){
                if(isValid(x + dx[i] , y + dy[i] , heights[x][y] , vis)){
                    dfs(x + dx[i] , y + dy[i] , vis) ;
                }
            }
            if(atlantic[x][y] && pacific[x][y]) ans.push_back(vector<int>{x , y}) ;
        };
        
        for(int i = 0 ; i < n ; i++){
            if(!atlantic[i][m -1])  dfs(i , m - 1 , atlantic) ;
            if(!pacific[i][0])  dfs(i , 0 , pacific) ;
        }
        for(int i = 0 ; i < m ; i++){
            if(!atlantic[n - 1][i]) dfs(n - 1 , i , atlantic) ;
            if(!pacific[0][i])  dfs(0 , i , pacific) ;
        }
        return ans ; 
    }