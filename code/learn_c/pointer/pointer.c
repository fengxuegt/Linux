/*
 * Created 2022-01-26 18:37:41
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i = 1;
    int *p;
    p = &i;
    printf("i = %d\n", i);
    printf("&i = %p\n", &i);
    printf("p = %p\n", p);
    printf("&p = %p\n", &p);
    printf("*p = %d\n", *p);
    return 0;
}