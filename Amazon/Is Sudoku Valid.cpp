// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void printMat(vector<vector<int>> mat){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    int isValid(vector<vector<int>> mat){
        
        int rowCount[9][9]={0},colCount[9][9]={0},gridCount[9][9]={0};
        // RowCheck & ColCheck & GridCheck
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                if(mat[i][j]!=0){
                    rowCount[i][mat[i][j]-1]+=1;
                    colCount[j][mat[i][j]-1]+=1;
                    gridCount[(i/3)*3+(j/3)][mat[i][j]-1]+=1;
                    if(rowCount[i][mat[i][j]-1]>1 || colCount[j][mat[i][j]-1]>1 
                       || gridCount[(i/3)*3+(j/3)][mat[i][j]-1]>1)
                        return 0;
                }
            }
        }
        //printMat(mat);
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends