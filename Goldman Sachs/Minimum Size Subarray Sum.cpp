class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int Min = INT_MAX;
        int Sum = nums[0];
        int subSize = 1;
        int startIndex = 0;
        if(Sum>=target)
            return 1;
        for(int i=1;i<nums.size();i++){
            if(Sum+nums[i]<target){
                Sum+=nums[i];
                subSize+=1;
            }
            else{
                Sum=Sum+nums[i];
                subSize+=1;
                while(Sum>=target){
                    Sum-=nums[startIndex];
                    startIndex++;
                    subSize--;
                }
                if(subSize+1<Min)
                    Min=subSize+1;
            }
        }
        if(Min>nums.size())
            Min=0;
        return Min;
    }
};