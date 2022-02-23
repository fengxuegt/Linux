/*
 * Created 2022-01-27 22:43:04
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[2][3] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%p -> %d\n", *(arr+i) + j, *(*(arr + i) + j));
        }
    }
    int *p = &arr[0][0]; // int *p = *arr;
    for (int i = 0; i < 6; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    

    int (*q)[3] = arr;
    printf("%p %p\n", arr, arr+1);
    printf("%p %p\n", q, q+1);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%p -> %d\n", *(q+i) + j, *(*(q + i) + j));
        }
    }
    return 0;
}