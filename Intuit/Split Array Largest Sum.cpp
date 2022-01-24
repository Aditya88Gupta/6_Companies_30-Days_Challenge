class Solution {
public:
    
    int subCount(vector<int> nums, int limit){
        int subArrs(1);
        int curSum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(curSum+nums[i]<=limit)
                curSum+=nums[i];
            else{
                subArrs++;
                curSum=nums[i];
            }
        }
        return subArrs;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int low,high(0);
        // Max in array is the best solution if possible
        // totalSum is the worst solution
        low=INT_MIN;
        for(int i=0;i<nums.size();i++){
            high+=nums[i];
            low=max(low,nums[i]);
        }
        
        while(low<high){
            int mid = low + (high-low)/2;
            int subArrs = subCount(nums,mid);
            // Try for better
            if(subArrs<=m){
                high=mid;
            }
            else
                low=mid+1;
        }
        return low;
    }
};