//wap to perfrom BST Operation
#include<bits/stdc++.h>
using namespace std;

struct node		//Structure of node
{
	int data;
	node*left;
	node*right;
};
node* create(int data)	//Creating node
{
	node*ptr=new node;
	ptr->data=data;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}
node* insert(node*root,int data)	//inserting node in bst
{
	if(root==NULL)
		root=create(data);
	else if(data<=root->data)
		root->left=insert(root->left,data);
	else if(data>root->data)
		root->right=insert(root->right,data);
	
	return root;		
			
}
bool search(node*root,int data)	//Searching element in the BST
{
	if(root==NULL)	return false;
	else if(root->data==data)	return true;
	else if(data<root->data)	search(root->left,data);
	else if(data>root->data)	search(root->right,data);
}

int findMin(node*root)	//Finding the minimum element in the BST
{
	if(root==NULL)
	{
		cout<<"\nTree is Empty";
		return -1;
	}
	else if(root->left==NULL)
		return root->data;
	else 
		return findMin(root->left);	
}
int findMax(node*root)	//Finding the maximun element in the BST
{
	if(root==NULL)
	{
		cout<<"\nTree is Empty";
		return -1;
	}
	else if(root->right==NULL)
		return root->data;
	else 
		return findMax(root->right);	
}

int height(node*root)	//Finding the height of the BST
{	
	int leftHeight,rightHeight;
	if(root==NULL)
		return -1;
	leftHeight=height(root->left);
	rightHeight=height(root->right);
	return max(leftHeight,rightHeight)+1;	
		
}
int main()	//Driver function
{
	node*root=NULL;
	root=insert(root,20);
	root=insert(root,3);
	root=insert(root,10);
	root=insert(root,45);
	root=insert(root,5);
	int data;
	cout<<"\nEnter the data to be searched in BST:";
	cin>>data;
	if(search(root,data))
		cout<<"\nData Found";
	else
		cout<<"\nData not found"; 
	
	int min=findMin(root);
	cout<<"\nMinimum VAlue in MST is:"<<min;
	
	int max=findMax(root);
	cout<<"\nMAximum Value in BST is:"<<max;
	cout<<"\nHeight Of the Tree:"<<height(root);	
	return 0;		
}
