// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
    
    unordered_map<Node*,Node*> Parent;
    unordered_map<Node*,bool> Burning;
    Node* start;
  public:
  
    int bfs(){
        queue<Node*> q;
        q.push(start);
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            bool flag = false;
            // process the neighbors of the nodes burned in the previous second
            while(n--){
                Node* track = q.front();
                q.pop();
                if(Parent[track] && !Burning[Parent[track]]){
                    q.push(Parent[track]);
                    flag=true;
                    Burning[Parent[track]]=true;
                }
                if(track->left && !Burning[track->left]){
                    q.push(track->left);
                    flag=true;
                    Burning[track->left]=true;
                }
                if(track->right && !Burning[track->right]){
                    q.push(track->right);
                    flag=true;
                    Burning[track->right]=true;
                }
            }
            if(flag)
                ans+=1;
        }
        return ans;
    }
    
    // Create back pointer so that parent is reachable from child
    // find target node
    void findParent(Node* root, int target){
        Burning[root]=false;
        if(root->data==target)
            start=root;
        if(root->left){
            Parent[root->left] = root;
            findParent(root->left,target);
        }if(root->right){
            Parent[root->right] = root;
            findParent(root->right,target);
        }
    }
    
    int minTime(Node* root, int target) 
    {
        Parent[root] = NULL;
        findParent(root,target);
        return bfs();
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends