class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<int>>adj(n,vector<int>());
        vector<vector<double>>cost(n,vector<double>());
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            cost[edges[i][0]].push_back(succProb[i]);
            cost[edges[i][1]].push_back(succProb[i]);
        }

        priority_queue<pair<double,int>> pq;
        vector<double> prob(n,0);
        vector<bool> found(n,false);
        prob[start]=1;
        for(int i=0;i<n;i++)
            pq.push(make_pair(prob[i],i));
            
        while(!pq.empty()){
            int vertex = pq.top().second;
            if(found[vertex]){
                pq.pop();
                continue;
            }
            found[vertex]=true;
            pq.pop();
            for(int i=0;i<adj[vertex].size();i++){
                if(!found[adj[vertex][i]]){
                    double tmp = prob[adj[vertex][i]];
                    prob[adj[vertex][i]]=max(prob[vertex]*cost[vertex][i],tmp);
                    if(tmp!=prob[adj[vertex][i]])
                        pq.push(make_pair(prob[adj[vertex][i]],adj[vertex][i]));
                }
            }
        }
        return prob[end];
    }
};