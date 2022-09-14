#include<malloc.h>
#include<vector>
#include<iostream>
using namespace std;

typedef struct TreeLink{
	int val;
	struct TreeLink * left;
	struct TreeLink * right;
} treelink;

void PreOrder(treelink * root)
{
	treelink * cur = root;
	if(cur != NULL)
	{
		cout<<cur->val<<endl;
		PreOrder(cur->left);
		PreOrder(cur->right);
	}
}

void FreeTree(treelink * root)
{
	if(root != NULL)
	{
		treelink * left = root->left;
		treelink * right = root->right;
		free(root);
		FreeTree(left);
		FreeTree(right);
	}
}

void pre_order(treelink * root)
{
	vector<treelink *> sta;
	
	treelink * cur = root;
	sta.push_back(cur);
	
	while(sta.size() > 0)
	{
		cur = sta[sta.size()-1];
		cout<<cur->val<<endl;
		sta.pop_back();
		if(cur->right != NULL)
		{
			sta.push_back(cur->right);
		}	
		if(cur->left != NULL)
		{
			sta.push_back(cur->left);
		}
	}
}

void Insert(treelink * parent, treelink * child)
{
	if(parent->left == NULL)
	{
		parent->left = child;
	}
	else if(parent->right == NULL)
	{
		parent->right = child;
	}
}

treelink * BuildTree()
{
	treelink * root = (treelink *)malloc(sizeof(treelink));
	root->val = 1;
	root->left = NULL;
	root->right = NULL;
	treelink * cur = root;
	
	for(int i = 2; i < 7; i++)
	{
		treelink * p = (treelink *)malloc(sizeof(treelink));
		p->val = i;
		p->left = NULL;
		p->right = NULL;
		if(cur->left != NULL && cur->right != NULL)
			cur = cur->left;
		Insert(cur, p);
	}
	return root;
}

int main()
{
	treelink * root = BuildTree();
	pre_order(root);
	FreeTree(root);
}
