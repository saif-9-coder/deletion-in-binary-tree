#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node * left;
	struct node * right;
};
void inorder(struct node * root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
node * newnode(int x)
{
	struct node * temp = new node ();
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct node * insert (struct node * root , int x)
{
	if(root==NULL)
	{
		return newnode(x);
	}
	if (x< root->data)
	{
        root->left = insert(root->left, x);
    }
    else
    {
	
        root->right = insert(root->right,x);
    }
    return root;
}
struct node * minvalue(node * p)
{
	struct node * temp =p;
	while(temp && temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}
struct node * deletenode(node * root , int x)
{
	if(root==NULL)
	{
		return root;
	}
	if (x<root->data)
	{
		root->left=deletenode(root->left,x);
	}
	else if (x>root->data)
	{
		root->right=deletenode(root->right,x);
	}
	else
	{
		if(root->left==NULL && root->right==NULL )
		{
			return NULL;
		}
		else if (root->left==NULL)
		{
			struct node * temp = root->right;
			delete(root->right);
			return temp;
		}
		else if (root->right==NULL)
		{
			struct node * temp = root->left;
			delete(root->left);
			return temp;
		}
		else
		{
//			successer
			struct node * temp = minvalue(root->right);
			root->data=temp->data;
			root->right=deletenode(root->right,temp->data);
		}
	}
	return root;
}
main()
{
	struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    cout<<"The values of a trees>>>>"<<endl;
    inorder(root);
    deletenode(root,60);
    cout<<endl<<"The values of a trees after deletion>>>>"<<endl;
    inorder(root);
}

