#include <stdio.h> 
#include <stdlib.h> 
#define inf -1000

int min(int *a, int n)
{
	int i, min;
	min = -inf;
	for(i = 0; i < n; i++)
	{
		if(a[i] < min)
			min = a[i];
	}
	return min;
}

int max(int *a, int n)
{
	int i, max;
	max = inf;
	for(i = 0; i < n; i++)
	{
		if(a[i] > max)
			max = a[i];
	}
	return max;
}

int * cnt_sort(int * a, int n)
{
	int * b, *c, size, i;
	int amax, amin;
	amax = max(a, n);
	amin = min(a, n);
	size = amax - amin + 1;
	b = (int *)malloc(sizeof(int)*n);
	c = (int *)malloc(sizeof(int)*size);
	
	for(i = 0; i < size; i++)
	{
		c[i] = 0;
	}
	
	for(i = 0; i < n; i++)
	{
		c[a[i]-amin]++;
	}
	
	
	for(i = 1; i < size; i++)
	{
		c[i] = c[i] + c[i-1];
	}
	for(i = 0; i < n; i++)
	{
		b[c[a[i]-amin]-1] = a[i];
		c[a[i]-amin]--;
	}
	/*
	int bi = 0;
	for(i = 0; i < size; i++)
	{
		while(c[i] > 0)
		{
			b[bi] = i + amin;
			c[i]--;
			bi++;
		}	 
	}
	*/
	return b;
}

int main()
{
	int a[10] = {2,7,3,6,2,10,4,7,9,2};
	int *b = cnt_sort(a, 10);
	int i;
	for(i = 0; i < 10; i++)
	{
		printf("%d\n", b[i]);
	}
}
