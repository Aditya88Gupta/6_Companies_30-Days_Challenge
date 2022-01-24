class Solution {
public:
    int mountEle(MountainArray &mountainArr, int Len){
        int low = 0;
        int high = Len-1;
        int mountIdx=-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int midEle = mountainArr.get(mid);
            // cuz peak is always present
           if(mid==0){
               mountIdx=1;
               break;
           }
            // cuz peak is always present
            if(mid==Len-1){
                mountIdx=Len-2;
                break;
            }
            int midNext = mountainArr.get(mid+1);
            int midPrev = mountainArr.get(mid-1);
            if(midEle>midPrev && midEle>midNext){
                mountIdx = mid;
                break;
            }
            if(midEle<midNext)
                low=mid+1;
            else 
                high=mid-1;
        }
        return mountIdx;
    }
    
    int binarySearch(MountainArray &mountainArr, int Len, int target){
        int low=0;
        int high=Len-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int midEle = mountainArr.get(mid);
            if(midEle==target){
               return mid;
            }
            if(midEle<target)
                low=mid+1;
            else 
                high=mid-1;
        }
        return -1;
    }
    
    int bSearch(MountainArray &mountainArr, int mountIdx, int Len, int target){
        int low=mountIdx+1;
        int high=Len-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int midEle = mountainArr.get(mid);
            if(midEle==target){
               return mid;
            }
            if(midEle>target)
                low=mid+1;
            else 
                high=mid-1;
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int Len = mountainArr.length();
        int mountIdx = mountEle(mountainArr,Len);
        // If target==mountEle
        if(mountainArr.get(mountIdx)==target)
            return mountIdx;
        // Search in 1st half
        int Idx = binarySearch(mountainArr,mountIdx,target);
        // Search in 2nd half
        if(Idx==-1)
            Idx = bSearch(mountainArr,mountIdx,Len,target);
        return Idx;
    }
};