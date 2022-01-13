// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Starting idx of span of i
       vector<int> start(n,0);
       vector<int> res;
       res.push_back(1);
       start[0]=0;
       for(int i=1;i<n;i++){
           if(price[i]<price[i-1]){
               start[i]=i;
               res.push_back(1);
           }else{
               int count = 1;
               int j = start[i-1];
               while(j>0){
                   //cout<<j<<" ";
                   if(price[j-1]<=price[i])
                       j=start[j-1];
                   else
                       break;
               }
               count+=i-j;
               start[i]=j;
               res.push_back(count);
               //cout<<endl;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends