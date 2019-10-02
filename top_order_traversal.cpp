#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define elements second

class TreeNode
{
public:

	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
	
};



void createNode(int parent[], int i, TreeNode* created[], TreeNode*& root){
	if(created[i] != NULL) return;		//node has already been created

	created[i] = new TreeNode(i);

	if(parent[i] == -1){
		root = created[i];
		return;
	}

	if(created[parent[i]] == NULL){
		createNode(parent,parent[i],created,root);
	}

	TreeNode* curr = created[parent[i]];

	if(curr->left == NULL){
		curr->left = created[i];
	}
	else{
		curr->right = created[i];
	}



}

TreeNode* createTree(int parent[],int n){
	TreeNode* root = NULL;
	TreeNode* created[n];
	for (int i = 0; i < n; ++i)
	{
		created[i] = NULL;
	}

	for (int i = 0; i < n; ++i)
	{
		createNode(parent,i,created,root);
	}

	return root;
}

void verticalOrder(TreeNode* root,int d, map<int,vector<int> >& m){
	if(root == NULL) return;

	m[d].push_back(root->data);
	verticalOrder(root->left,d-1,m);
	verticalOrder(root->right,d+1,m);
}

void topTraversal(TreeNode* root){
	map<int,vector<int> > m;
	int d = 0;
	verticalOrder(root,d,m);		//prepare map

	map<int,vector<int> >:: iterator it;

	for (it = m.begin(); it != m.end(); ++it)
	{
		for (int i = 0; i < it->second.size(); ++i)
		{
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
	}
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int* parent = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>parent[i];
		}
		// cout<<endl;
		TreeNode* root = createTree(parent,n);
		topTraversal(root);



		delete[] parent;
	}
}