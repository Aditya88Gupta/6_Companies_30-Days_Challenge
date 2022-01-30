class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor) return INT_MAX;
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend == INT_MIN) {return INT_MAX;}
            else {return -dividend;}
        }
        int q=0;
        int num = abs(dividend);
        int div = abs(divisor);
        while(num-div>=0){
            num-=div;
            q++;    
        }
        if(dividend<0 && divisor<0 || dividend>0 && divisor>0)
            return q;
        else
            return -q;
    }
};