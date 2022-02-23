/*
 * Created 2022-01-24 23:21:30
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n = 3;
    static int arr[3];
    printf("%ld\n", sizeof(arr));
    printf("%p\n", arr);
    for (int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 3; i ++) {
        printf("%p -> %d\n", &arr[i], arr[i]);
    }
    return 0;
}