#include <stdio.h>

int a[100][100];

void YHT(int n)
{
	if(n==0)
	{
		a[0][0] = 1;
		printf("%d\n", a[0][0]);
		return;
	}
	YHT(n-1);
	a[n][0] = 1, a[n][n] = 1;
	for(int i = 1; i < n; i++)
	{
		a[n][i] = a[n-1][i-1] + a[n-1][i];
	}
	for(i = 0; i <= n; i++)
		printf("%d\t", a[n][i]);
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("\n");
	YHT(n);
	return 0;
}
