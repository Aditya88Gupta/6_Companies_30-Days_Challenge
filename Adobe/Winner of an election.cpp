// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        vector<string> res;
        unordered_map<string,int> Map;
        int maxCount(0);
        for(int i=0;i<n;i++){
            if(Map.find(arr[i])!=Map.end())
                Map[arr[i]]+=1;
            else 
                Map[arr[i]]=1;
            if(Map[arr[i]]>maxCount)
                maxCount=Map[arr[i]];
        }
        for(auto item = Map.begin(); item != Map.end(); ++item){
            if(item->second==maxCount){
                if(res.size()==0)
                    res.push_back(item->first);
                else if(item->first<res[0])
                    res[0]=item->first;
            }
        }
        res.push_back(to_string(maxCount));
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends