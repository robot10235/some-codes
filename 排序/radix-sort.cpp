#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

int * cnt_sort(int * a, int n, int di)
{
	int * b, size, i;
	int c[10] = {0};
	size = 10;
	b = (int *)malloc(sizeof(int)*n);
	di = pow(10, di);
	
	for(i = 0; i < n; i++)
	{
		c[(a[i]/di)%10]++;
	}
	
	for(i = 1; i < size; i++)
	{
		c[i] = c[i] + c[i-1];
	}
	for(i = n-1; i >= 0; i--)
	{
		b[c[(a[i]/di)%10]-1] = a[i];
		c[(a[i]/di)%10]--;
	}
	return b;
}

int * radix_sort(int * a, int n, int d)
{
	int i;
	int *b = a;
	for(i = 0; i < d; i++)
	{
		b = cnt_sort(b, n, i);
	}
	return b;
}

int main()
{
	int a[7] = {329, 457, 657, 839, 436, 720, 355};
	int * b = radix_sort(a, 7, 3);
	int i;
	for(i = 0; i < 7; i++)
	{
		printf("%d\n", b[i]);
	}
}
