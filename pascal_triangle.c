#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	printf("\n1\n");
	for(int i = 1, c = 1; i <= n; i++, c = 1)
	{
		printf("1\t");
		for(int r = 1; r < i; r++)
		{
			c = c*(i-r+1)/r;
			printf("%d\t", c);
		}
		printf("1\n");
	}
	return 0;
}
