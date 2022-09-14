#include <stdio.h> 

void han(int start, int spare, int end, int n)
{
	if(n > 0)
	{
		// move n-1 from start to spare
		han(start,end,spare,n-1);
		// move 1 from start to end
		printf("%d%d\n",start,end);
		// move n-1 from spare to end
		han(spare,start,end,n-1);
	}
	
}

int main()
{
	han(1,2,3,2);
}
