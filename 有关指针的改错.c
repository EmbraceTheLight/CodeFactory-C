//title：
//编程输入10个数，找出其中的最大值及其所在的数组下标位置。找出其中错误并改正之。 
#include <stdio.h>
 
int FindMax(int num[], int n, int *pMaxPos);
 
main()
{
    int num[10], maxValue, maxPos, minValue, minPos, i; 
 
    printf("Input 10 numbers:\n ");
    for (i=0; i<10; i++)
    {
        scanf("%d", num[i]);                 
    }                        
    maxValue = FindMax(num, 10, *maxPos);  
    printf("Max=%d, Position=%d\n",maxValue, maxPos);
}
int FindMax(int num[], int n, int *pMaxPos)  
{
    int i, max;
     
    max = num[0];               
     
    for (i = 1, i < n, i++)
    {
        if (num[i] > max)
        {
            max = num[i];
            *pMaxPos = i;
        }
    }   
    return max;
}





solution：
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int FindMax(int num[], int n, int* pMaxPos);
main()
{
    int num[10], maxValue, maxPos = 0, i;

    printf("Input 10 numbers:\n ");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
    }
    maxValue = FindMax(num, 10, &maxPos);          //*maxPos->&maxPos
    printf("Max=%d, Position=%d\n", maxValue, maxPos);
}
int FindMax(int num[], int n, int* pMaxPos)
{
    int i, max;
    max = num[0];

    for (i = 1; i < n; i++)
    {
        if (num[i] > max)
        {
            max = num[i];
            *pMaxPos = i;
        }
    }
    return max;
}
