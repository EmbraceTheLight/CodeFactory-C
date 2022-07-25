正确的：

#include <stdio.h>
int main ()
{
    int lines = 0;
    int chars = 0;
    char ch;
    while ((ch = getchar ()) != EOF)                  //这值得借鉴（输入CTRL+Z结束输入）
    {
        chars ++;
        if (ch == '\n')
        {
            lines ++;
        }
    }
    printf ("chars=%d, lines=%d\n", chars, lines);
    return 0;
}


我的：（可行，但习题系统不认）
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
int main()
{
	char a[10000] = { 0 };
	int i,j;
	int line = 0;
	for (i=0;; i++)
	{
		scanf("%s",&a[i]);
		i=strlen(a);
		if (a[i] == '\0')
		{
			a[i] = '\n';                        //手动制作‘\n’，确实抽象（scanf貌似不会读入'\n')
			line++;
		}
		i = strlen(a);
		j = i - 2;                           //字符个数（i-2：一个是减去输入CTRL+D生成的'\x4',另一个是减去输入CTRL+D进入if（a[i]=='\0')循环后产生的'\n'）
		i--;
		if (a[i-1] == '\x4') break;          //输入CTRL+D，结束输入并执行printf操作
	}
	printf("chars=%d, lines=%d\n",j,line-1);
	return 0;
}
