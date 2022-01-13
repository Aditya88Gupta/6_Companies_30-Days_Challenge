// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    vector<vector<int>> adj;

public:

    void Explore(int idx, 
    vector<bool> &Visited, bool &flag, unordered_set<int> &track){
        Visited[idx]=true;
        track.insert(idx);
        for(int i=0;i<adj[idx].size();i++){
            if(Visited[adj[idx][i]]!=true){
                Explore(adj[idx][i],Visited,flag,track);
            }else if(track.find(adj[idx][i])!=track.end())
                flag=true;
        }
        track.erase(track.find(idx));
    }

    bool acyclic(vector<bool> &Visited){
        
        for(int i=0;i<adj.size();i++){
            if(Visited[i]!=true){
                unordered_set<int> track;
                bool flag=false;
                Explore(i,Visited,flag,track);
                if(flag)
                    return 1;
            }
        }
        return 0;
    }
    
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    ;
	    vector<bool> Visited(N,false);
	    for(int i=0;i<N;i++)
	        adj.push_back(vector<int>());
	    for(int i=0;i<prerequisites.size();i++){
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
	    }
	    return !acyclic(Visited);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends