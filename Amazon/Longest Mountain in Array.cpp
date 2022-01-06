// Modified Sliding-Window


class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3)
            return 0;
        int mountain=-1;
        int front=0;
        int maxSize=0;
        int curSize=0;
        int i=1;
        while(i<arr.size()){
            // mountain==-1 -> currently we do not have a mountain element
            // if we do not have a mountain element uptil ith element, then
            // elements from front till i-1 are in increasing order
            if(mountain==-1){
                if(i!=arr.size()-1 && arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                    mountain=i;
                    curSize=i+1-front;
                }
                else if(arr[i]<=arr[i-1])
                    front=i;
                i++;
            }else{
                // Checking if we can extend the existing subarray
              if(arr[mountain]>arr[i] && arr[i-1]>arr[i]){
                  curSize++;
                  i++;
              }
              else{
                  // fresh start
                  mountain=-1;
                  front=i-1;
              }  
            }
            if(maxSize<curSize)
                maxSize=curSize;
        }
        return maxSize;
    }
};