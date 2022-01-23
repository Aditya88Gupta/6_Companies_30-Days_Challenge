// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string res="";
        int i=0;
        s[0]=toupper(s[0]);
        while(i<s.length()){
            if(isupper(s[i])){
                res+=tolower(s[i]);
                i++;
                while(i<s.length() && !isupper(s[i])){
                    res+=s[i];
                    i++;
                }
                if(i!=s.length())
                    res+=" ";    
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends