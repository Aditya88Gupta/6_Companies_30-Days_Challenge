// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
   
	public:
	
// 	int totalWays(string str, vector<int> &table){
// 	    if(str.length()==1 || str.length()==0)
// 		        return 1;
// 		    if(table[str.length()-1]==0)
// 		        table[str.length()] += totalWays(str.substr(1,str.length()),table);
// 		    else
// 		        table[str.length()] += table[str.length()-1];
// 		    if(str.length()>=2){
// 		        int num = (int)(str[0]-'0')*10+(int)(str[1]-'0');
// 		        if(num<=26){
// 		            if(table[str.length()-2]==0)
// 		                table[str.length()] += totalWays(str.substr(2,str.length()),table);
// 		            else
// 		                table[str.length()] += table[str.length()-2];
// 		        }
// 		    }
// 		  //  for(int i=0;i<str.length();i++)
// 		  //      cout<<table[i]<<endl;
// 		    return table[str.length()]%1000000007;
// 		}
		
		int CountWays(string str){
		     if(str[0]=='0')
		         return 0;
		  //   for(int i=1;i<str.length();i++){
		  //       if(str[i]=='0'){
		  //           int num = (int)(str[i-1]-'0')*10+(int)(str[i]-'0');
		  //           if(num>26 || num<=0)
		  //           return 0;
		  //       }
		  //   }
		     if(str.length()==1 )
 		        return 1;
		     vector<int> table(str.length()+1,0);
		     table[0]=1;
		     table[1]=1;
		     int len = str.length();
		     int mod = 1000000007;
		     for(int i=2;i<=len;i++){
		         if(str[i-1]>'0')
		             table[i]=table[i-1];
		         if(str[i-2]=='1' || str[i-2]=='2' && str[i-1]<'7')
		             table[i] = (table[i]+table[i-2])%mod;       
		     }
		     return table[str.length()];
		}
		    // Code here
		    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends