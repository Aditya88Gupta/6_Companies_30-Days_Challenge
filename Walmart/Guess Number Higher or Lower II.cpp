class Solution {
    vector<vector<int>> dpTable;
public:
    int minCost(int low, int high){
        
        if(low>=high)
            return 0;
        
        if(low+2==high){
            return low+1;
        }
        if(low+1==high)
            return low;
        
        if(dpTable[low][high]!=-1)
            return dpTable[low][high];
        
        int curMin = INT_MAX;
        for(int i=low+1;i<high;i++){
            int tmp1 = max(minCost(i+1,high),minCost(low,i-1))+i;
            if(curMin>tmp1)
                curMin=tmp1;
        }
        dpTable[low][high]=curMin;
        return curMin;
    }
    
    int getMoneyAmount(int n) {
        for(int i=0;i<=n;i++){
            dpTable.push_back(vector<int>(n+1,-1));
        }
        return minCost(1,n);
    }
};