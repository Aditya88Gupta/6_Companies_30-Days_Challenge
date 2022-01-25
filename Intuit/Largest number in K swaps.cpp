class Solution
{
    public:
    void match(string& str, string& res)
    {
        for(int i=0; i<str.size(); i++)
        {
            if( res[i] > str[i] )
                return;
            if( res[i] < str[i] )
            {
                res = str;
                return;
            }
        }
    }

    public:
    void setDigit(string& str, int index, string& res, int k)
    {
        // base case
        if(k==0 || index==str.size()-1)
        {
            match(str,res);
            return;
        }
        
        int maxDigit = 0;
        for(int i=index; i<str.size(); i++)
            maxDigit = max( maxDigit, str[i]-'0' );
        if( str[index]-'0' == maxDigit )
        {
            setDigit(str, index+1, res, k);
            return;
        }
        
        for(int i=index+1; i<str.size(); i++)
        {
            if( str[i]-'0' == maxDigit ){
                swap( str[index] , str[i] );
                setDigit(str, index+1, res, k-1);
                swap( str[index] , str[i] );
            }
        }
    }

    public:
    string findMaximumNum(string str, int k)
    {
        string res = str;
        setDigit(str, 0, res, k);
        return res;
    }

};