// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<string> sorted_words;
        vector<vector<string>> res;
        for(int i=0;i<string_list.size();i++){
            string sorted_word = string_list[i];
            sort(sorted_word.begin(),sorted_word.end());
            bool flag = false;
            for(int k=0;k<sorted_words.size();k++){
                if(sorted_word==sorted_words[k]){
                    res[k].push_back(string_list[i]);
                    flag=true;
                    break;
                }
            }
            if(!flag){
                vector<string> vect;
                vect.push_back(string_list[i]);
                res.push_back(vect);
                sorted_words.push_back(sorted_word);
            }
        }
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
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends