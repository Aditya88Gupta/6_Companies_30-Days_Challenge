// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    vector<string> res;
    public:
    
    // bool checkBalance(string str){
    //     stack<char> st;
    //     for(int i=0;i<str.length();i++){
    //         if(str[i]==')'){
    //             if(st.empty())
    //                 return false;
    //             st.pop();
    //         }else
    //             st.push(str[i]);
    //     }
    //     if(st.empty())
    //         return true;
    //     return false;    
    // }
    
    void possibleComb(string str, int openCount, int closeCount){
        if(openCount==0 && closeCount==0){
            //cout<<str<<endl;
            res.push_back(str);
        }else{
            if(openCount!=0){
                possibleComb(str+'(',openCount-1,closeCount);
            }
            if(closeCount>openCount){
                possibleComb(str+')',openCount,closeCount-1);
            }
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        possibleComb("",n,n);
        return res;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends