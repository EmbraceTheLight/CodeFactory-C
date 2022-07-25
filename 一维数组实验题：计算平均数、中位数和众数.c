//Q3106.(10分)一维数组实验题：计算平均数、中位数和众数
//在调查数据分析（Survey data analysis）中经常需要计算平均数、中位数和众数。用函数编程计算40个输入数据（是取值1—10之间的任意整数）的平均数（Mean）、中位数（Median）和众数（Mode）。中位数指的是排列在数组中间的数。众数是数组中出现次数最多的那个数（不考虑两个或两个以上的输入数据出现次数相同的情况）。
//提示：计算中位数时，首先要调用排序函数对数组按升序进行排序，然后取出排序后数组中间位置的元素answer[n/2] ，就得到了中位数。如果数组元素的个数是偶数，那么中位数就等于数组中间那两个元素的算术平均值。众数就是40个输入数据中出现次数最多的那个数。计算众数时，首先要统计不同取值的输入数据出现的次数，然后找出出现次数最多的那个数据，这个数据就是众数（这里没有考虑两个或者两个以上的输入数据出现次数相同的情况）。
//
//程序运行结果示例：
//Input the feedbacks of 40 students:
//10 9 10 8 7 6 5 10 9 8↙
//8 9 7 6 10 9 8 8 7 7↙
//6 6 8 8 9 9 10 8 7 7↙
//9 8 7 9 7 6 5 9 8 7↙
//Mean value=7
//Median value=8
//Mode value=8
//
//输入格式:  "%d"
//输出格式：
//输入数据的提示信息："Input the feedbacks of 40 students:\n"
//平均数输出："Mean value=%d\n"
//中位数输出："Median value=%d\n"
//众数输出： "Mode value=%d\n"







#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 40
void Mean(int arr[]);
void Median(int arr[]);
void Mode(int arr[]);
int main()
{
    int arr[N];
    int i;
    printf("Input the feedbacks of 40 students:\n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    Mean(arr);
    Median(arr);
    Mode(arr);
    return 0;
}
void Mean(int arr[])
{
    int i,Mean;
    int sum = 0;
    for(i=0;i<N;i++)
    {
        sum += arr[i];
    }
    Mean = sum / 40;
    printf("Mean value=%d\n",Mean);
}
void Median(int arr[])
{
    int temp;
    int i,j;
    for (i = 0; i <= N-1; i++)
    {
        for(j=0;j<N-1-i;j++)
        if (arr[j] >= arr[j + 1])
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }   
    }
    printf("Median value=%d\n", (arr[19] + arr[20]) / 2);
}
void Mode(int arr[])
{
    int count1=0, count2=0;     
    int i,j=1; int a;
    for (a = 1; a < 10; a++)
    {
        for (i = 0; i < N; i++)
        {
            if (a == arr[i])
            {
                if (a == 1)
                {
                    count1++;
                }
                else
                    count2++;
                 
            }   
        }
        if (count1 < count2)
                {
                    count1 = count2;
                    count2 = 0;
                    j = a;
                }
        count2 = 0;
    }
    if (count1 > count2)
        printf("Mode value=%d\n", j);
 
}
