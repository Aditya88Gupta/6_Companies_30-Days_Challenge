// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    vector<string> res;
    public:
    //Function to find list of all words possible by pressing given numbers.
    
    char alphabet(int n){
        switch(n){
            case 2: return 'a';
            case 3: return 'd';
            case 4: return 'g';
            case 5: return 'j';
            case 6: return 'm';
            case 7: return 'p';
            case 8: return 't';
            case 9: return 'w';
            default : return '-';
        }
    }
    
    void findWords(int a[], int N, int index, string str){
        if(index>=N){
            res.push_back(str);
            return;
        }
        int letters = 3;
        if(a[index]==7 || a[index]==9)
            letters++;
        for(int i=0;i<letters;i++)
            findWords(a,N,index+1,str+(char)(alphabet(a[index])+i));
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        findWords(a,N,0,"");
        return res;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends