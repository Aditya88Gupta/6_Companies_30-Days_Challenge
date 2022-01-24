// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool found = false;
public:
    void checkWord(int i, int j, int Idx, vector<vector<char>>& board, string word){
        
        if(i<0 || j<0 || i>=board.size() || j>=board[i].size())
            return;
        
        if(word.length()==Idx){
            found = true;
            return;
        }
    
        if(found)
            return;
        
        if(board[i][j]==word[Idx]){
            char tmp = board[i][j];
            // cuz each letter can be used once
            board[i][j] = '-';
            // Left
            checkWord(i,j-1,Idx+1,board,word);
            // Right
            checkWord(i,j+1,Idx+1,board,word);
            // Up
            checkWord(i-1,j,Idx+1,board,word);
            // Down
            checkWord(i+1,j,Idx+1,board,word);
            board[i][j]=tmp;
        }    
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        
        for(int x=0;x<board.size();x++){
            for(int y=0;y<board[x].size();y++){
                if(board[x][y]==word[0]){
                    // diff start points are possible
                    checkWord(x,y,0,board,word);
                }
            }
        }
        return found;    
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends