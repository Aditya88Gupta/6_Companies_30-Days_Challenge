// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    void printMat(vector<vector<bool>> possibleSum){
    for(int i=0;i<possibleSum.size();i++){
        for(int j=0;j<possibleSum[0].size();j++)
            cout<<possibleSum[i][j]<<" ";
    cout<<endl;
    }
}
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int totalSum(0);
	    for(int i=0;i<n;i++)
	        totalSum+=arr[i];
	    vector<vector<bool>> possibleSum(n+1,vector<bool>((totalSum/2)+1,0));
	    sort(arr,arr+n);
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=(totalSum/2)+1;j++){
	            if(arr[i-1]==j)
	                possibleSum[i][j]=true;
	            else if(j>arr[i-1] && possibleSum[i-1][j-arr[i-1]])
	                possibleSum[i][j]=true;
	            else
	                possibleSum[i][j]=possibleSum[i-1][j];
	        }
	    }
	    int Sum1=0;
	    for(int j=(totalSum/2);j>=1;j--){
	        if(possibleSum[n][j]){
	            Sum1=j;
	            break;
	        }
	    }
	    //printMat(possibleSum);
	    return abs(totalSum-2*Sum1);
	    
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends