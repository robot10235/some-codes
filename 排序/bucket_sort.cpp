#include <iostream> 
#include <vector>
#define inf -1000

using namespace std;

int min(vector<int> a, int n)
{
	int m = -inf;
	for(int i = 0; i < n; i++)
	{
		if(m > a[i])
		{
			m = a[i];
		}
	}
	return m;
}

int max(vector<int> a, int n)
{
	int m = inf;
	for(int i = 0; i < n; i++)
	{
		if(m < a[i])
		{
			m = a[i];
		}
	}
	return m;
}

void quick_sort(vector<int> &a, int start, int end)
{
	if(start >= end)
	{
		return;
	}
	int pivot = a[end-1];
	int b = start;
	
	for(int i = start; i < end-1; i++)
	{
		if(a[i] <= pivot)
		{
			int temp = a[i];
			a[i] = a[b];
			a[b] = temp;
			b++;
		}
	}
	int temp = a[b];
	a[b] = a[end-1];
	a[end-1] = temp;
	
	//cout<<a[0]<<endl;
	quick_sort(a, start, b);
	quick_sort(a, b+1, end);
}

void bucket_sort(vector<int> &a, int n)
{
	int bucket_num = 2;
	vector< vector<int> > bucket(bucket_num);
	for(int i = 0; i < n; i++)
	{
		int no = (a[i] - min(a, n)) / double(((max(a, n)-min(a, n))/bucket_num));
		if(no == 0)
			no = 1;
		bucket[no-1].push_back(a[i]);
	}
	
	int ai = 0;
	for(int i = 0; i < bucket_num; i++)
	{
		quick_sort(bucket[i], 0, bucket[i].size());
		for(int j = 0; j < bucket[i].size(); j++)
		{
			a[ai] = bucket[i][j];
			ai++;
		}
	}	
}

int main()
{
	vector<int> a;
	a.push_back(2);
	a.push_back(1);
	a.push_back(12);
	a.push_back(1);
	a.push_back(3);
	a.push_back(3);
	a.push_back(4);
	a.push_back(1);
	a.push_back(7);
	a.push_back(23);
	a.push_back(9);
	a.push_back(8);
	a.push_back(0);
	a.push_back(1);
	a.push_back(23);
	a.push_back(9);
	
	bucket_sort(a, 16);
	
	for(int i = 0; i < 16; i++)
	{
		cout<<a[i]<<endl;
	}
}
