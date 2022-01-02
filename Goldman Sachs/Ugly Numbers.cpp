// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    vector<ull> uglyNumbers;
	    uglyNumbers.push_back(1);
	    int marker_2 = 0;
	    int marker_3 = 0;
	    int marker_5 = 0;
	    while(uglyNumbers.size()<n){
	        ull num1 = uglyNumbers[marker_2] * 2;
	        ull num2 = uglyNumbers[marker_3] * 3;
	        ull num3 = uglyNumbers[marker_5] * 5;
	        ull Min = min(min(num1,num2),num3);
	        if(uglyNumbers[uglyNumbers.size()-1]<Min)
	            uglyNumbers.push_back(Min);
	        if(Min == num1)
	            marker_2++;
	        else if(Min == num2)
	            marker_3++;
	        else
	            marker_5++;
	    }
	    return uglyNumbers[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends