// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<char> st;
        int p = 0;
        string ans;
        while(p<s.size()){
            // push into stack until ']' is encountered    
            if(s[p]==']'){  
                string temp="";
                string temp2="";
                string num = "";
                while(st.top() != '['){
                    temp=st.top()+temp;
                    st.pop();
                }
                // Pop '['
                 st.pop();
                // Extract number
                while(!st.empty() && isdigit(st.top())){    
                    num=st.top()+num;
                    st.pop();
                }
                int n=stoi(num);
                for(int i=1;i<=n;i++)
                    temp2=temp2+temp;
                if(st.empty()){   
                    ans=temp2;
                    break;
                }
                for(int i=0;i<temp2.size();i++)
                    st.push(temp2[i]);
            }
            else
                st.push(s[p]);
            p++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends