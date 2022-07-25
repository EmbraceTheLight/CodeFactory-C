#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
#include<assert.h>
struct S {
	char name[20];
	int age;
};
typedef struct S stu;
void* my_memcpy(void* dest,const void* src, size_t size);
void* my_memmove(void* dest, const void* src, size_t size);

int main(void)
{ 
	stu test = { "dfd",12 };
	stu d;
	int arr1[] = {1,2,3,4,5,6,7,8,9,10};
	my_memcpy(arr1+2, arr1, sizeof(int)*4);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", arr1[i]);
	}
	my_memcpy(&d, &test, sizeof(test));
	return 0;
}
void* my_memcpy(void* dest,const void* src, size_t size)
{
	assert(dest && src);
	char* d = (char*)dest;
	char* s = (char*)src;
	int i = 0;
	for (i = 0; i < size; i++,d++,s++)
	{
		*d = *s;
	}
	return dest;
}
void* my_memcpy(void* dest, const void* src, size_t size)
{

}