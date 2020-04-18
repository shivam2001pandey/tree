//wap to perfrom Depth First Traversal in Binary Search Tree
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
void preorder(node*root)
{
	if(root==NULL)
		return;	
		
	cout<<root->data<<"->";
	preorder(root->left);
	preorder(root->right);
}
 void inorder(node*root)
 {
 	if(root==NULL)	return;
 	inorder(root->left);
 	cout<<" "<<root->data<<"->";
	inorder(root->right);
 }
 
 void postorder(node*root)
 {
 	if(root==NULL)	return ;
 	postorder(root->left);
 	postorder(root->right);
 	cout<<" "<<root->data<<"->";
 }
int main()	//Driver function
{
	node*root=NULL;
	root=insert(root,1);
	root=insert(root,2);
	root=insert(root,3);
	root=insert(root,4);
	root=insert(root,5);
	cout<<"\nInORDER T raversal\n";
	inorder(root);
	cout<<"\nPreOrder Traversal\n";
	preorder(root);
	cout<<"\nPostOrder Traversal\n";
	postorder(root);
	return 0;		
}
