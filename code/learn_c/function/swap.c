/*
 * Created 2022-01-28 19:28:25
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>

void print_value(int i, int j)
{
    printf("%d %d\n", i, j);
}

void swap(int *i, int *j)
{
    int t = *i;
    *i = *j;
    *j = t;
}

int main()
{
    int a = 3, b = 5;
    print_value(a, b);
    swap(&a, &b);
    print_value(a, b);
    return 0;
}