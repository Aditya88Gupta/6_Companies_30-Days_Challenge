// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    string Max;
    public:
    
    void swap(string &str, int i, int j){
        char ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }
    
    void findMax(string str,int k,int pos){
        
        if(str>Max)
            Max=str;
        
        if(k==0)
            return;
            
        // find maximum number > pos    
        char curMax = str[pos];    
        for(int i=pos+1;i<str.length();i++){
            if(curMax<str[i])
                curMax=str[i];
        }
        
        if(curMax!=str[pos])
            k--;
        
        // which idx swap would result in max
        for(int j=str.length()-1;j>=pos;j--){
            if(str[j]==curMax){ 
                swap(str,pos,j);
                findMax(str,k,pos+1);
                // back track
                swap(str,pos,j);
            }
        }
    }
    
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       findMax(str,k,0);
       return Max;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends