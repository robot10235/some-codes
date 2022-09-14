#include <stdio.h> 

void max_heapify(int * a, int root, int n)
{
	int temp = a[root], flag = 0;
	
	// ������������ 
	if(2*root + 2 < n)
	{
		if(a[2*root+1] > a[root] && a[2*root+1] >= a[2*root+2])
		{
			a[root] = a[2*root+1];
			a[2*root+1] = temp;
			max_heapify(a, 2*root+1, n);
		}
		else if(a[2*root+2] > a[root] && a[2*root+2] >= a[2*root+1])
		{
			a[root] = a[2*root+2];
			a[2*root+2] = temp;		
			max_heapify(a, 2*root+2, n);
		}
	}
	
	//ֻ�������� 
	if(2*root + 1 < n && 2*root + 2 >= n && a[2*root+1] > a[root])
	{
		a[root] = a[2*root+1];
		a[2*root+1] = temp;
		max_heapify(a, 2*root+1, n);
	}
}

void build_max_heap(int * a, int n)
{
	int i;
	for(i = n/2 - 1;i >= 0; i--)
	{
		max_heapify(a, i, n);
	}
}

void heap_sort(int * a, int n)
{
	int i, temp, j;
	build_max_heap(a, n);
	for(i = n; i > 1; i--)
	{
		temp = a[i-1];
		a[i-1] = a[0];
		a[0] = temp;
		max_heapify(a, 0, i-1);
	}
}

int main()
{
	int a[10] = {3,2,1,5,4,0,16,-7,-9,32};
	int i;
	//max_heap(a, 2);
	heap_sort(a, 10);
	for(i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}
}
