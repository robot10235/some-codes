#include<stdio.h>

int Partition(int* A, int p, int r)
{
	int pivot = A[r];
	int i, b, temp;
	
	b = p;
	for(i = p; i < r; i++)
	{
		// 找到小于等于枢轴值的就放左边 
		if(A[i] <= A[r])
		{
			temp = A[i];
			A[i] = A[b];
			A[b] = temp;
			b++;
		}
	}
	for(i = r; i > b; i--)
	{
		A[i] = A[i-1];
	}
	A[b] = pivot;
	
	return b;
}

void QuickSort(int* A, int p, int r)
{
	int b;
	if(p < r)
	{
		b = Partition(A, p, r);
		QuickSort(A, p, b-1);
		QuickSort(A, b+1, r);
	}
}

void QuickSortIteration(int* A, int r)


int main()
{
	int a[10] = {4,2,1,3,5,7,10,8,9,6};
	QuickSort(a, 0 ,9);
	
	int i;
	for(i = 0;i < 10;i++)
	{
		printf("%d\n", a[i]);
	}
} 
