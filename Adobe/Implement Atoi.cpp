// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        bool negv=false;
        int num=0;
        int tmp=1;
        for(int i=str.length()-1;i>=0;i--){
            if(isdigit(str[i])){
                num = num + (str[i]-'0')*tmp;
                tmp=tmp*10;
            }else if(i==0 && str[i]=='-')
                negv=true;
            else
                return -1;
        }
        if(negv)
            return -num;
        return num;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends