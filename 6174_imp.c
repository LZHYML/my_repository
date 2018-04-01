#include <stdio.h>

void Sort(int a[], int end);
int Max(int a[]);
int Min(int a[]);

void main()
{
	int n, a[4] = {0}, cnt = 1;
	printf("输入一个各位不相同的10000以内的整数：");
	scanf("%d", &n);
	int end = n;
	while(end != 6174)
	{
		Sort(a, end);
		end = Max(a) - Min(a);
		printf("第%d次：\t%04d - %04d = %04d\n", cnt++, Max(a), Min(a), end);
	}
}

void Sort(int a[], int end)
{
	int i = 0, j;
	while(end!=0)
	{
		a[i++] = end%10;
		end /= 10;
	}
	for(i = 0; i < 4-1; i++)
	{
		for(j = 0; j < 4-1-i; j++)
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

int Max(int a[])
{
	int max = 0;
	for(int i = 3; i >= 0; i--)
		max = max*10 + a[i];
	return max;
}

int Min(int a[])
{
	int min = 0;
	for(int i = 0; i <= 3; i++)
		min = min*10 + a[i];
	return min;
}
