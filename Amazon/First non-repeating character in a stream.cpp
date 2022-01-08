// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<int> q;
		    vector<int> Count(26,0);
		    for(int i=0;i<A.size();i++){
		        Count[A[i]-'a']++;
		        if(Count[A[i]-'a']==1)
		            q.push(A[i]);
		        while(!q.empty() && Count[q.front()-'a']!=1)
		            q.pop();
		        if(q.empty())
		            A[i]='#';
		        else
		            A[i]=q.front();
		    }
		    return A;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends