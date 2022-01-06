//(10分)二维数组实验题：利用矩阵相乘公式，编程计算M*N阶矩阵A和N*M阶矩阵B之积C(M*M阶矩阵)。
要求如下：
1.用宏定义形式分别定义M、N的值为3、4。
2.函数原型分别定义成：
void MultiplyMatrix(int a[M][N], int b[N][M], int c[M][M]);/* 函数功能：计算矩阵相乘之积，结果存于二维数组c中 */
void InputMatrixA(int a[M][N]);/* 函数功能：输入矩阵a中的元素 */
void InputMatrixB(int b[N][M]);/* 函数功能：输入矩阵b中的元素 */
void OutputMatrix(int a[M][M]);/* 函数功能：输出矩阵a中的元素 */
3.主函数定义成：
int main()
{
	int a[M][N], b[N][M], c[M][M];
	InputMatrixA(a);
	InputMatrixB(b);
	MultiplyMatrix(a,b,c);
	OutputMatrix(c);
	return 0;
}
4.输入输出格式：
输入矩阵A的提示："Input %d*%d matrix a:\n"
输入矩阵A中元素的提示："a[%d,%d]:"
输入矩阵A中元素的格式："%d"
输入矩阵B的提示："Input %d*%d matrix b:\n"
输入矩阵B中元素的提示："b[%d,%d]:"
输入矩阵B中元素的格式："%d"
输出结果提示："Results:\n"
输出元素格式："%6d"(注：每行末有printf("\n");)
程序运行示例：
Input 3*4 matrix a:↙
a[0,0]:1
a[0,1]:2
a[0,2]:3
a[0,3]:4
a[1,0]:1
a[1,1]:2
a[1,2]:3
a[1,3]:4
a[2,0]:1
a[2,1]:2
a[2,2]:3
a[2,3]:4
Input 4*3 matrix b:↙
b[0,0]:1
b[0,1]:2
b[0,2]:1
b[1,0]:2
b[1,1]:1
b[1,2]:2
b[2,0]:1
b[2,1]:2
b[2,2]:1
b[3,0]:2
b[3,1]:1
b[3,2]:2
Results:
    16    14    16
    16    14    16
    16    14    16






#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 3
#define N 4
void MultiplyMatrix(int a[M][N], int b[N][M], int c[M][M]);/* 函数功能：计算矩阵相乘之积，结果存于二维数组c中 */
void InputMatrixA(int a[M][N]);/* 函数功能：输入矩阵a中的元素 */
void InputMatrixB(int b[N][M]);/* 函数功能：输入矩阵b中的元素 */
void OutputMatrix(int a[M][M]);/* 函数功能：输出矩阵a中的元素 */
int main()
{
    int a[M][N], b[N][M], c[M][M];
    InputMatrixA(a);
    InputMatrixB(b);
    MultiplyMatrix(a, b, c);
    OutputMatrix(c);
    return 0;
}
void MultiplyMatrix(int a[M][N], int b[N][M], int c[M][M])/* 函数功能：计算矩阵相乘之积，结果存于二维数组c中 */
{
    int row,col,j;
    int i = 0;
    int sum = 0;
    for (row = 0; row < M; row++)
    {
        i = 0;
        for (j = 0; j < M; j++)
        {
            sum = 0;
            for (col = 0; col < N; col++)
            {
                sum += a[row][col] * b[col][j];
            }
            c[row][i] = sum;
            i++;
        }
    }
}
void InputMatrixA(int a[M][N])/* 函数功能：输入矩阵a中的元素 */
{
    int row = 0,col=0;
    printf("Input %d*%d matrix a:\n", M, N);
    for (row = 0; row < M; row++)
    {
        for (col = 0; col < N; col++)
        {
            printf("a[%d,%d]:",row,col);
            scanf("%d", &a[row][col]);
        }
    }
}
void InputMatrixB(int b[N][M])/* 函数功能：输入矩阵b中的元素 */
{
    int row = 0, col = 0;
    printf("Input %d*%d matrix b:\n", N, M);
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < M; col++)
        {
            printf("b[%d,%d]:", row, col);
            scanf("%d", &b[row][col]);
        }
    }
}
void OutputMatrix(int a[M][M])/* 函数功能：输出矩阵a中的元素 */
{
    int i,j;
    printf("Results:\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }
}
