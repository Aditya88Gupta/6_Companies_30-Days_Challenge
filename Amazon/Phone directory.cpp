// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> res;
        vector<string> vect;
        sort(contact,contact+n);
        int x=1;
        vect.push_back(contact[0]);
        while(x<n){
            if(contact[x]!=contact[x-1])
                vect.push_back(contact[x]);
            x++;    
        }
        vector<string> prefixes;
        string prefix="";
        prefix+=s[0];
        prefixes.push_back(prefix);
        for(int i=1;i<s.length();i++){
            prefix+=s[i];
            prefixes.push_back(prefix);
        }
        
        for(int i=0;i<prefixes.size();i++){
            res.push_back(vector<string>());
            for(int k=0;k<vect.size();k++){
                string tmp = vect[k].substr(0,prefixes[i].length()); 
                if(prefixes[i]==tmp)
                    res[i].push_back(vect[k]);
            }
            if(res[i].size()==0)
                res[i].push_back("0");
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends