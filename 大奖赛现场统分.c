#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000
void sort1(int a[], int n,int b);
void  CountAthleteScore(int sh[], float sf[], int n, float f[], int m);//参赛选手的得分
void Sort(int h[], float f[], int n);//对分数从高到低排序
void Print(int h[], float f[], int n);//打印名次表
void CountJudgeScore(int ph[], float pf[], int m, float sf[], float f[], int n);//统计评委得分
int main()
{
	int i,n, m;//n:Ath  m:Jud
	int sh[N],ph[N];
	float sf[N], f[N],pf[N];
	printf("How many Athletes?");
	scanf("%d", &n);
	printf("How many judges?");
	scanf("%d", &m);
	printf("Scores of Athletes:\n");
	CountAthleteScore(sh, sf, n, f, m);
	CountJudgeScore(ph, pf, m, sf, f, n);
	Sort(sh, sf, n);
	printf("Order of judges:\n");
	Sort(ph, pf, m);
	printf("Over!Thank you!");
	return 0;
}
void  CountAthleteScore(int sh[], float sf[], int n, float f[], int m)
{
	int i,j,d,c;
	float a,b,max, min, ave, sum;
	for (i = 1; i <= n; i++)
	{
		sum = 0,ave=0;
		printf("\nAthlete %d is playing.", i);
		printf("\nPlease enter his number code:");
		scanf("%d", &sh[i]);
		for (j = 1; j <= +m; j++)
		{
			printf("Judge %d gives score:", j);
	   		scanf("%f", &f[i*m+j]);//值得借鉴
		}
		c = i * m + 1;
		a = f[c]; b = f[c];
		for (c = i * m + 1; c < i * m + m; c++)
		{		
			if (f[c] < f[c + 1]) a = f[c + 1];
			if (f[c] > f[c + 1]) b = f[c + 1];
		}
		max = a;
		min = b;
		printf("Delete a maximum score:%.1f\n", max);
		printf("Delete a minimum score:%.1f\n", min);
		for (d = i*m+1; d <=i*m+m; d++)
		{
			sum += f[d];
		}
		ave = (sum-a-b) / (m - 2);
		sf[i] = ave;
		printf("The final score of Athlete %d is %.3f\n",sh[i],sf[i] );		
	}	
	printf("Order of Athletes:\n");
}
void Sort(int h[], float sf[], int n)//对分数从高到低排序
{
	int i, j;
	float tem1 = 0,tem2=0;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= n -1 - i; j++)
		{
			
			if (sf[j] < sf[j + 1])
			{
				tem1 = 0, tem2 = 0;
				tem1 = sf[j + 1];
				sf[j + 1] = sf[j];
				sf[j] = tem1;
				tem2 = h[j + 1];
				h[j + 1] = h[j];
				h[j] = tem2;
			}
		}
	}
	Print(h, sf, n);
}
void CountJudgeScore(int ph[], float pf[], int m, float sf[], float f[], int n)//统计评委评分
{
	int i, j;
	for (j = 1; j <= m; j++)
	{
		ph[j] = j; pf[j] = 0;
		float sum = 0;
		for (i = 1; i <= n; i++)
		{
			sum += (f[i*m+j] - sf[i])*(f[i*m+j]-sf[i]);
		}
		pf[j] = 10 - sum;
	}
	
}
void Print(int h[], float sf[], int n)//打印名次表
{
	int i;
	printf("order\tfinal score\tnumber code\n");
	for (i = 1; i <=n; i++)
	{
		printf("%5d\t%11.3f\t%6d\n", i, sf[i], h[i]);
	}
}
