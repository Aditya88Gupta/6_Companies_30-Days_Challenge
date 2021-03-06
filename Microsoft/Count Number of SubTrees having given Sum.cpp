int countSubtreesWithSumXUtil(Node* root, int& count, int x){
	if (!root)
	return 0;
	int ls = countSubtreesWithSumXUtil(root->left, count, x);
	int rs = countSubtreesWithSumXUtil(root->right, count, x);
	int sum = ls + rs + root->data;
	if (sum == x)
	count++;
	return sum;
}

int countSubtreesWithSumX(Node* root, int x)
{ 
	if (!root)
	return 0;
	int count = 0;
	int ls = countSubtreesWithSumXUtil(root->left, count, x);
	int rs = countSubtreesWithSumXUtil(root->right, count, x);
	if ((ls + rs + root->data) == x)
	count++;
	return count;
}