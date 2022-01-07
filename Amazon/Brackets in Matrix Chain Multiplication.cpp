// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    vector<vector<int> > dpTable;
    vector<vector<int> > bracket;
    // Vector storing indeces where backets should be inserted
    //vector<int> Start,End; 
    string res="";
public:

    void printMat(int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<dpTable[i][j]<<" ";
            cout<<endl;    
        }
    }
    
    // void Reconstruct(int p[], int i,int j){
    //     if (i>=j)
    //     return;
    //     for(int k=i;k<j;k++){
    //         long tmp = dpTable[i][k]+dpTable[k+1][j];
    //         tmp+=p[i]*p[k+1]*p[j+1];
    //         if(tmp==dpTable[i][j]){
    //             Start.push_back(i);End.push_back(k);
    //             Start.push_back(k+1);End.push_back(j);
    //             Reconstruct(p,i,k);
    //             Reconstruct(p,k+1,j);
    //         }       
    //     }   
    // }
    
    void printParenthesis(int i, int j, int n, char& name){
        
        
        if (i == j) {
            res+=name;
            name++;
            return;
        }
        res+="(";
        printParenthesis(i,bracket[i][j],n,name);
        printParenthesis(bracket[i][j]+1,j,n,name);
        res+=")";
    }
    
    string matrixChainOrder(int p[], int n){
        // code here
        for(int i=0;i<n;i++){
            dpTable.push_back(vector<int>(n,0));
            bracket.push_back(vector<int>(n,0));
        }
        
        // increasing order of j-i
        for(int s=2;s<n;s++){
            for(int i=1;i<n-s+1;i++){
                int j = s+i-1;
                    dpTable[i][j]=INT_MAX;
                    for(int k=i;k<j;k++){
                        // (Mi to Mk) * (Mk+1 to Mj)
                        long tmp = dpTable[i][k]+dpTable[k+1][j];
                        // Rowi*Colk*Colj
                        tmp+=p[i-1]*p[k]*p[j];
                        if(tmp<dpTable[i][j]){
                            dpTable[i][j]=tmp;
                            bracket[i][j]=k;
                    }
                }
            }    
        }
        //printMat(n-1);
        // BackTracking
        //Reconstruct(p,0,n-2);
        char name = 'A';
        printParenthesis(1,n-1,n,name);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends