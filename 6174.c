#include <stdio.h>
int Kap(int n);
int Max(int n);
int Min(int n);
bool DifBit(int n);

void main()
{
	int n, i = 0;
	printf("请输入一个各位不完全的四位（含）以内整数：");
	scanf("%d", &n);
	if(!(n<10000 && DifBit(n)))
	{
		printf("非法数据！\n");
		return;
	}
	int a[100];
	a[i] = n;
	do{
		i++;
		a[i] = Kap(a[i-1]);
		printf("%04d\n", a[i]);
		printf("第%d次进行卡普尔变换得到%04d\n", i, a[i]);
//		getchar();
	}while(a[i-1] != a[i]);
	printf(" %d次卡普尔变换得到自我拷贝数：%d\n", i-1, a[i]);
}

bool DifBit(int n)
{
	int a[4] = {0}, i = 0;
	while(n!=0)
	{
		a[i++] = n%10;
		n /= 10;
	}
	if(a[0]==a[1] && a[1]==a[2] && a[2]==a[3])
		return false;
	else
		return true;
}

int Kap(int n)
{
	return Max(n)-Min(n);
}

int Max(int n)
{
	int a[4] = {0}, i = 0;
	while(n!=0)
	{
		a[i++] = n%10;
		n /= 10;
	}
	for(i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3-i; j++)
		{
			if(a[j] > a[j+1])
			{
				int tem = a[j];
				a[j] = a[j+1];
				a[j+1] = tem;
			}
		}
	}
	int num = 0;
	for(i = 3; i >= 0;i--)
	{
		num = num*10 + a[i];
	}
	printf("%04d - ", num);
	return num;
}

int Min(int n)
{
	int a[4] = {0}, i = 0;
	while(n!=0)
	{
		a[i++] = n%10;
		n /= 10;
	}
	for(i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3-i; j++)
		{
			if(a[j] < a[j+1])
			{
				int tem = a[j];
				a[j] = a[j+1];
				a[j+1] = tem;
			}
		}
	}
	int num = 0;
	for(i = 3; i >= 0;i--)
	{
		num = num*10 + a[i];
	}
	printf("%04d = ", num);
	return num;
}
