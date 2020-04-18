//wap to perfrom Level Order Traversal in Binary Search Tree
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

void levelOrder(node*root)
{
	if(root==NULL)
		{
			cout<<"\nTree is empty";
			return;
		}
	queue<node*>q;
	q.push(root);
	cout<<"\nLevel Order Traversal of the BST:";
	while(!q.empty())
	{
		node*current=q.front();
		cout<<current->data<<"->";
		if(current->left!=NULL)	q.push(current->left);
		if(current->right!=NULL)	q.push(current->right);
		q.pop();
		
	}
	
}
int main()	//Driver function
{
	node*root=NULL;
	root=insert(root,20);
	root=insert(root,3);
	root=insert(root,10);
	root=insert(root,45);
	root=insert(root,5);
	levelOrder(root);	
	return 0;		
}
