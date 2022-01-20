class Solution
{
    public:
    vector<string> v;
    void rec(string s,int n,int opened)
    {
        if(n!=0)
            rec(s+"(",n-1,opened+1);
        if(opened!=0)
            rec(s+")",n,opened-1);
        if(n==0 && opened==0)
            v.push_back(s);
    }
    vector<string> AllParenthesis(int n) 
    {
        rec("",n,0);
        return v;
    }
};