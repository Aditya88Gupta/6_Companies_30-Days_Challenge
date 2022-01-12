// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> boundaryTraversal(vector<vector<int>> matrix, int n, int m, int row, int col) 
    {
        // Only 1 row
        if(n==1){
            vector<int> vect;
            for(int i=0;i<m;i++)
                    vect.push_back(matrix[row][col+i]);
            return vect;
        }
        // Only 1 col
        if(m==1){
            vector<int> vect;
            for(int i=0;i<n;i++)
                    vect.push_back(matrix[row+i][col]);
            return vect;        
        }
        vector<int> vect(2*m+2*(n-2),0);
        int front=0;
        int back=vect.size()-1;
        for(int i=0;i<n;i++){
            if(i==0){
                for(int j=0;j<m;j++)
                    vect[front++]=matrix[row+i][col+j];
            }else if(i==n-1){
                for(int j=0;j<m;j++)
                    vect[front++]=matrix[row+i][col+m-1-j];
            }
            else{
                vect[back--]=matrix[row+i][col+0];
                vect[front++]=matrix[row+i][col+m-1];
            }
        }
        return vect;
        
    }
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {

        vector<int> vect;
        // from which row/col boundary traversal should start
        int row=0;
        int col=0;
        while(r>0 && c>0){
            vector<int> tmp = boundaryTraversal(matrix,r,c,row,col);
            vect.insert(vect.end(), tmp.begin(), tmp.end());
            // deleting rows/cols which have been covered in boundary traversal
            r=r-2;
            c=c-2;
            row+=1;
            col+=1;
        }
        return vect;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends