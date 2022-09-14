#include <stdio.h>

void merge(int* a, int p, int q, int r)
{
	int m[r-p] = {0};
	int left = p;
	int right = q;
	int mi = 0;
	int ai = p;
	int i;
	while(left < q && right < r)
	{
		if(a[left] > a[right])
		{
			m[mi++] = a[right++];
		}
		else
		{
			m[mi++] = a[left++];
		}
	}
	while(left < q)
	{
		m[mi++] = a[left++];
	}
	while(right < r)
	{
		m[mi++] = a[right++];
	}
	
	for(i = 0; i < r-p; i++)
	{
		a[ai++] = m[i];
	}
}

void merge_sort(int* a, int p, int q)
{
	int mid = (p+q)/2;
	if(p < q)
	{
		merge_sort(a,p,mid);
		merge_sort(a,mid+1,q);
		merge(a,p,mid+1,q+1);
	}
}

int main()
{
	int a[11] = {3,9,7,1,4,3,2,1,7,9,6};
	int i;
	merge_sort(a, 0, 10);
	
	//merge(a,0,0,1);
	for(i = 0; i < 11; i++)
	{
		printf("%d\n",a[i]);
	}
}
