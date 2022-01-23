// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    void nextPermutation(string &str){
        int index=0;
        for(int i=str.length()-2;i>=0;i--){
            int tmp=i;
            char curMin='A';
            // find smallest element > i
            for(int j=i;j<str.length();j++){
                if(str[i]<str[j] && curMin>str[j]){
                    tmp=j;
                    curMin=str[j];
                }
            }
            // swap ith with next greatest element
            if(tmp!=i){
                char curMax=str[tmp];
                str[tmp]=str[i];
                str[i]=curMax;
                index=i+1;
                break;
            }
        }
        sort(str.begin()+index,str.end());
    }
    
    string nextPalin(string N) { 
        //complete the function here
        if(N.length()<=3)
            return "-1";
        string half = N.substr(0,N.length()/2);
        nextPermutation(half);
        if(half<=N.substr(0,N.length()/2))
            return "-1";
        string res=half;
        if(N.length()%2!=0)
            res+=N[N.length()/2];
        reverse(half.begin(),half.end());
        res+=half;
        return res;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    void nextPermutation(string &str){
        int index=0;
        for(int i=str.length()-2;i>=0;i--){
            int tmp=i;
            char curMin='A';
            // find smallest element > i
            for(int j=i;j<str.length();j++){
                if(str[i]<str[j] && curMin>str[j]){
                    tmp=j;
                    curMin=str[j];
                }
            }
            // swap ith with next greatest element
            if(tmp!=i){
                char curMax=str[tmp];
                str[tmp]=str[i];
                str[i]=curMax;
                index=i+1;
                break;
            }
        }
        sort(str.begin()+index,str.end());
    }
    
    string nextPalin(string N) { 
        if(N.length()<=3)
            return "-1";
        string half = N.substr(0,N.length()/2);
        nextPermutation(half);
        // if next does not exists
        if(half<=N.substr(0,N.length()/2))
            return "-1";
        string res=half;
        // if odd length, then add the mid ele
        if(N.length()%2!=0)
            res+=N[N.length()/2];
        reverse(half.begin(),half.end());
        res+=half;
        return res;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends