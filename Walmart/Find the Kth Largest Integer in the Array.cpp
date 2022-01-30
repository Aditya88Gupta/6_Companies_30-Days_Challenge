class Solution {
public:
    
    static bool comp(string& str1, string& str2){
        if(str1.length() == str2.length()) return str1 > str2;
        return str1.length() > str2.length();
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),comp);
        return nums[k-1];
    }
};