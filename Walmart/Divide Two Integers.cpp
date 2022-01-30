class Solution {
public:
    int divide(int dividend, int divisor) {
        int divide(int dividend, int divisor) {
        int q=0;
        int Sum = 0;
        if(divisor==1)
            return dividend;
        if(divisor==-1){
            if(dividend==INT_MIN)
                return INT_MAX;
            return -dividend;
        }
        while(Sum<=abs(dividend)-abs(divisor)){
            Sum+=abs(divisor);
            q++;    
        }
        if(dividend<0 && divisor<0 || dividend>0 && divisor>0)
            return q;
        else
            return -q;
    }
    }
};