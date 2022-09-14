#include<stdio.h>

void bin_search(int* a, int l, int h, int key)
{
	int m; 
	if(l <= h)
	{
		m = (l+h)/2;
		if(a[m] == key)
		{
			printf("%d\n",m);
		}
		if(a[m] > key)
		{
			bin_search(a, l, m-1, key);
		}
		if(a[m] < key)
		{
			bin_search(a, m+1, h, key);
		}
	}	
}

void iter_bs(int* a, int l, int h, int key)
{
	int low = l;
	int high = h;
	int mid;
	
	while(low <= high)
	{
		mid = (low+high)/2;
		if(a[mid]==key)
		{
			printf("%d\n",mid);
			break;
		}
		else if(a[mid] > key)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
}

int main()
{
	int a[8]={1,2,3,4,5,6,7,8};
	int k = 6;
	bin_search(a,0,5,k);
	iter_bs(a,0,6,k);
} 
