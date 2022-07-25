#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 34
void hwss(int n, int count);
int main()
{
	int n; int count = 0;
	printf("Input n:\n");
	scanf("%d", &n);
	hwss(n,count);
	return 0;
}
void hwss(int n, int count)
{
	int i, j, a=0,b, flag = 1,flag2=1; int arr[N];
	for(i=2;i<=n;i++)
	{
		for (j = 2; j <= sqrt(i); j++)
		{
			flag = 1;
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			a = 0;
			int i2 = i;
			while (i2 != 0)
			{
				
				arr[a] = i2 % 10;
				i2 = i2 / 10;
				a++;
			}
			for (b = 0; b < a; b++)
			{
				flag2 = 1;
				if (arr[b] != arr[a -1-b]||a<2)
				{
					flag2 = 0;
					break;
				}
				if (b > a-b - 1) break;
			}
			if (flag2)
			{
				count++;
				printf("%4d  ", i);
			}
		}
	}
	printf("\ncount=%d\n",count);
}
