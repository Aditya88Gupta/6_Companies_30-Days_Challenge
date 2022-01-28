class Solution {
    
    int n,m;
public:
    
    // void printMat(){
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++)
    //             cout<<pTable[i][j]<<" ";
    //         cout<<endl;    
    //     }
    // }
        
    void findPath(int i, int j, vector<vector<int>>& dpTable, vector<vector<int>> heights, int prev){
        
        if( i<0|| i>=n || j<0 || j>=m || dpTable[i][j]!=-1 || heights[i][j]<prev)
            return;
        
        dpTable[i][j]=1;
        findPath(i-1,j,dpTable,heights,heights[i][j]);
        findPath(i+1,j,dpTable,heights,heights[i][j]);
        findPath(i,j-1,dpTable,heights,heights[i][j]);
        findPath(i,j+1,dpTable,heights,heights[i][j]);
    }
    
//     void altlantic(int i, int j, vector<vector<int>> heights, int prev){
        
//         if(i<0||i>=n || j<0||j>=m || aTable[i][j]!=0 || heights[i][j]<prev)
//             return;
        
//         aTable[i][j]=1;
//         altlantic(i-1,j,heights,heights[i][j]);
//         altlantic(i+1,j,heights,heights[i][j]);
//         altlantic(i,j-1,heights,heights[i][j]);
//         altlantic(i,j+1,heights,heights[i][j]);
      
//     }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        
        vector<vector<int>> pacific(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
            findPath(i,0,pacific,heights,-1);
        
        for(int j=0;j<m;j++)
            findPath(0,j,pacific,heights,-1);
        
        vector<vector<int>> atlantic(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
            findPath(i,m-1,atlantic,heights,-1);

        for(int j=0;j<m;j++)
            findPath(n-1,j,atlantic,heights,-1);
        
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){   
               if(atlantic[i][j]==1 && pacific[i][j]==1)
                   res.push_back({i,j});
            }
        }
        return res;
    }
};