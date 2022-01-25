class Solution {
public:
    
    vector<bool> visited;
    vector<int> recStack;
    vector<int> ans;
    bool isCycle;
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adjlist(numCourses);
        
        for(int i=0;i<prerequisites.size();i++){
            adjlist[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        visited.resize(numCourses, false);
        recStack.resize(numCourses, 0);
        
       for(int i=0;i<numCourses;i++){
           dfs(i, adjlist);
           if(isCycle){
               ans.clear();
               return ans;
           }
       }
        
        return ans;
        
    }
    
    void dfs(int curr, vector<vector<int>> &adjlist) {
        if(!visited[curr]) {
            
            recStack[curr] = 1;
            
            for(int j=0;j<adjlist[curr].size();j++){
                if(!recStack[adjlist[curr][j]]) 
                    dfs(adjlist[curr][j], adjlist);
                else {
                    isCycle = true;
                    return;
                }
            }
            
            ans.push_back(curr);
            visited[curr] = true;
            recStack[curr] = 0;
        }   
    }
    
};