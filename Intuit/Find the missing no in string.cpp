// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends

// Extract number with given digits
int extractNum(string str, int i, int digits){
    string tmp="";
    int count=0;
    while(i<str.length() && count!=digits){
        tmp+=str[i];
        i++;
        count++;
    }
    return stoi(tmp);
}

int missingNumber(const string& str)
{
    // Code here
    if(str.length()==1)
        return -1;
        
    for(int i=1;i<=6;i++){
        int num1 = extractNum(str,0,i);
        int x = i;
        // number before missing
        int before=-1;
        bool valid = true;
        //cout<<num1<<endl;
        while(x<str.length()){
            int num2 = extractNum(str,x,i);
            x+=i;
            if(num1>num2){
                // If on +1 digits increase
                num2 = extractNum(str,x-i,i+1);
                x+=1;
            }
            if(num1+1==num2){
                num1=num2;
                continue;
            }
            if(num1+2==num2){
                // Can be only 1 missing number
                if(before!=-1){
                    valid=false;
                    break;
                }
                before=num1;
                num1=num2;
                continue;
            }
            valid=false;
            //cout<<num2<<endl;
            break;
        }
        if(valid && before!=-1)
            return before+1;
    }    
        
    return -1;    
}