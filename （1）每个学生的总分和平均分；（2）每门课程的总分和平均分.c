//某班期末考试科目为数学（MT）、英语（EN）和物理（PH），有最多不超过40人参加考试。请编程计算：（1）每个学生的总分和平均分；（2）每门课程的总分和平均分。
//**输入格式要求："%d" "%ld"(学号) 提示信息："Input the total number of the students(n<=40):" "Input student’s ID and score as: MT  EN  PH:\n"
//**输出格式要求："Counting Result:\n" "Student’s ID\t  MT \t  EN \t  PH \t SUM \t AVER\n" "%12ld\t"(打印学号) "%4d\t"（打印每门课成绩）"%4d\t%5.1f\n"（打印总分和平均分） "SumofCourse \t" "%4d\t"(打印每门课的总分) "\nAverofCourse\t" "%4.1f\t"(每门课的平均分) 
//程序的运行示例如下：
//Input the total number of the students(n<=40):4
//Input student’s ID and score as: MT  EN  PH:
//070310122  97  87  92
//070310123  92  91  90
//070310124  90  81  82
//070310125  73  65  80
//Counting Result:
//Student’s ID    MT	EN	PH	SUM	AVER
//070310122	97	87	92	276	92.0
//070310123	92	91	90	273	91.0
//070310124	90	81	82	253	84.3
//070310125	73	65	80	218	72.7
//SumofCourse	352	324	344		
//AverofCourse	88.0	81.0	86.0




#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 40
void Sum(int M[],int E[],int P[],int n);
int sum(int M[], int E[], int P[], int n);
void Ave(int M[], int E[], int P[], int n);
float ave(int M[], int E[], int P[], int p);
int main()
{
    int n, ID[N], M[N],E[N],P[N];
    int i, j;
    printf("Input the total number of the students(n<40):");
    scanf("%d", &n);
    printf("Input student’s ID and score as: MT  EN  PH:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%ld%d%d%d", &ID[i],&M[i],&E[i],&P[i]);
    }
    printf("Counting Result:\n");
    printf("Student’s ID\t  MT \t  EN \t  PH \t SUM \t AVER\n");
    for (j = 0; j < n; j++)
    {
        printf("%12ld\t%4d\t%4d\t%4d\t%4d\t%5.1f\n", ID[j], M[j], E[j], P[j], sum(M, E, P, j), ave(M, E, P,j));
    }
    printf("SumofCourse \t");
    Sum(M, E, P, n);
    printf("\nAverofCourse\t");
    Ave(M, E, P, n);
    return 0;
}
void Sum(int M[], int E[], int P[], int n)
{
    int i; int sum1=0,sum2=0,sum3=0;
    for(i = 0; i < n; i++)
    {
        sum1 += M[i];
        sum2 += E[i];
        sum3 += P[i];
    }
    printf("%4d\t%4d\t%4d\t", sum1, sum2, sum3);
}
void Ave(int M[], int E[], int P[], int n)
{
 
    int i; float sum1 = 0, sum2 = 0, sum3 = 0;
    float ave1, ave2, ave3;
    for (i = 0; i < n; i++)
    {
        sum1 += M[i];
        sum2 += E[i];
        sum3 += P[i];
    }
    ave1 = sum1 / (float)n;
    ave2 = sum2 / (float)n;
    ave3 = sum3 / (float)n;
    printf("%4.1f\t%4.1f\t%4.1f\t", ave1, ave2, ave3);
}
int sum(int M[], int E[], int P[], int p)
{
    int i; int sum = 0;
    sum = M[p] + E[p] + P[p];
    return sum;
}
float ave(int M[], int E[], int P[], int p)
{
    float ave;
    float sum = (float)(M[p] + E[p] + P[p]);
    ave = sum / 3.0;
    return ave;
}
