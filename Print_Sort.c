//给若干个数字，其中奇数从小到大输出，偶数从小到大输出

#include <stdio.h>

void PrintOdd(int a[], int N);
void PrintEven(int a[], int N);
void Sort(int a[], int N);

void main()
{
	int a[100];
	printf("要处理的数据个数为：");
	int n;
	scanf("%d", &n);
	printf("请输入这%d个数字：", n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	PrintOdd(a,n);
	PrintEven(a,n);
	printf("\n");
}

void PrintOdd(int a[], int N)
{
	int b[100], j = 0;
	for(int i = 0; i < N; i++)
		if(a[i]%2 != 0)
			b[j++] = a[i];
	Sort(b, j);
	for(i = 0; i < j; i++)
		printf("%d ", b[i]);
}

void PrintEven(int a[], int N)
{
	int b[100], j = 0;
	for(int i = 0; i < N; i++)
		if(a[i]%2 == 0)
			b[j++] = a[i];
	Sort(b, j);
	for(i = 0; i < j; i++)
		printf("%d ", b[i]);
}

void Sort(int a[], int N)
{
	for(int i = 0; i < N-1; i++)
	{
		for(int j = 0; j < N-1-i; j++)
		{
			if(a[j] > a[j+1])
			{
				int tem = a[j];
				a[j] = a[j+1];
				a[j+1] = tem;
			}
		}
	}
}
