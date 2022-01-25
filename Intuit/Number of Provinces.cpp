class Solution {
public:
    vector <int> parent;
    int findCircleNum(vector<vector<int>>& is) {
        int v=is.size();
        parent.resize(v, -1);
        
        for(int i=0; i<v; i++)
            for(int j=i+1; j<v; j++)
                if(is[i][j]==1)
                    unionn(i, j);
        
        int count=0;
        for(auto it: parent){
            if(it == -1)
                count++;
        }
        return count;
    }
    
    void unionn(int i, int j){
        i = find(i);
        j = find(j);
        if(i != j)
            parent[i]=j;
    }
    
    int find(int v){
        if(parent[v]==-1)
            return v;
        else
            return find(parent[v]);
    }
};