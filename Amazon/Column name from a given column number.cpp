// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // Extract alphabets recursively, much like we extract digits
        string res="";
        while(n!=0){
            // zero based idx for when n%26==0
            n--;
            int tmp = n%26;
            res=char(tmp+65)+res;
            n=n/26;    
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
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends