/*
 * Created 2022-01-25 23:20:55
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// strlen  strcpy  strncpy  
int main()
{
    char arr[] = "hello";
    char arr1[] = "hel\0lo";

    strcpy(arr1,arr);
    printf("%d\n", strlen(arr1));
    printf("%d\n", sizeof(arr1));
    return 0;
}