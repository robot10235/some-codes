#include<stdio.h> 
#include<stdlib.h>

typedef struct Link{
	int val;
	struct Link *next;
} link;

link * list_search(link * root, int v)
{
	link * cur = root;
	while(cur != NULL && cur->val != v)
	{
		cur = cur->next;
	}
	return cur;
}

//给定一个值插入到链表的前端 
void list_insert(link * root, int v)
{
	link * p = (link *)malloc(sizeof(link));
	p->val = v;
	p->next = root;
	root = p;
}

void list_delete(link * root, link * p)
{
	if(p != NULL)
	{
		link * cur = root;
		link * pre = NULL;
		while(cur != NULL && cur != p)
		{
			pre = cur;
			cur = cur->next;
		}
		if(pre != NULL)
		{
			pre->next = cur->next;
			free(p);
		}
		else
		{
			root = root->next;
			free(cur);
		}
	}
}
