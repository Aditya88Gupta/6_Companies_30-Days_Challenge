class Solution {
    
    int dpTable[501][501];
public:
    
    int optimalPath(int i, int j, vector<int> piles){
        if(i>j)
            dpTable[i][j]=0;
        if(i==j)
            dpTable[i][j]=piles[i];
        if(i+1==j)
            dpTable[i][j]=max(piles[i],piles[j]);
        if(dpTable[i][j]==-1){
            int front = piles[i]+min(optimalPath(i+2,j,piles),optimalPath(i+1,j-1,piles));
            int back =  piles[j]+min(optimalPath(i+1,j-1,piles),optimalPath(i,j-2,piles));
            dpTable[i][j] = max(front,back);
        }
        return dpTable[i][j];
    }
    
    bool stoneGame(vector<int>& piles) {
        
        memset(dpTable,-1,sizeof dpTable);
        int Alice = optimalPath(0,piles.size()-1,piles);
        int Bob = 0;
        accumulate(piles.begin(),piles.end(),Bob);
        Bob-=Alice;
        if(Alice>Bob)
            return true;
        return true;
    }
};