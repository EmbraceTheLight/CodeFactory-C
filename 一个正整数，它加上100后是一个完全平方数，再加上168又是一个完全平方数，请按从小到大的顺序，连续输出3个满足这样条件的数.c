//)题目：一个正整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请按从小到大的顺序，连续输出3个满足这样条件的数？
程序分析：使用穷举法，如果找到三个这样的数据，就停止。
提示：判断一个数是否为完全平方数，可以先将该数开方，在平方，如果结果与原数相等，即该数为完全平方数。
要求输出，每行一个满足条件的数，例如：

此题输出结果为：
21
***
***





#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long int i,x,y;
    int count = 0;
    for (i = 1;; i++)
    {
        x = sqrt(i + 100);
        y = sqrt(i + 268);
        if ((i + 100) == x*x &&(i+100+168)==y*y)
        {
            count++;
            //printf("%f ", j);
            //printf("%f ", j * j);
                printf("%ld\n", i);
                if (count == 3)
                    break;
        }
    }
    return 0;
}
