填表格
将1、2、3、4、5和6填入2行3列的表中，要使得每一个列右边的数字比左边的数字大，每一行下面的数字比上面的数字大。按此要求，可有几种填写方法？
**输出提示信息："The possible table satisfied above conditions are:\n"
**输出格式要求："\nNo.:%d" "\n%3d"  "%3d"



思路：遍历。首先，可以确定第一行第一列为1，第二行第三列为6；其次，第一行第二列只能为2或3。这样可以缩小遍历的次数。
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int i, j, count =0;
	int a[3]; int b[3],p,q,z;
	int k, o;
	a[0] = 1, b[2] = 6;
	int c[4] = { 2,3,4,5 };
	printf("The possible table satisfied above conditions are:\n");
	while (1)
	{
		i = 0, q = 0;
		for (i = 0; i <= 1; i++)
		{
			a[1] = c[i];
			for (j = i + 1; j <= 3; j++)
			{
				a[2] = c[j];
				for (p = 0; p <= 1; p++)
				{
					z = q;
					q = 0;
					while(q == j || q == i||q==z)
					{
						q++;					
					}
					b[p] = c[q];				
				}
				if (b[1] > a[1]&&b[2]>b[1])
				{
					count++;
					printf("\nNo.:%d\n",count);
					for (k = 0; k <= 2; k++)
					{
						printf("%3d",a[k]);
					}
					printf("\n");
					for (o = 0; o <= 2; o++)
					{
						printf("%3d", b[o]);
					}
				}
			}
		}
		if (i > 1) break;
	}
	return 0;
}
