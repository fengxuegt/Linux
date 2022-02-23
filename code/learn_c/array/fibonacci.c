/*
 * Created 2022-01-24 23:39:24
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>

void fibonacci()
{
    int arr[10];
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < 10; i++) { // sizeof(arr) / sizeof(arr[0])
        arr[i] = arr[i-1] + arr[i-2];
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int i = 0;
    int j = sizeof(arr) / sizeof(arr[0]) - 1;
    while (i < j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
        j--;
        i++;
    }
    for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    fibonacci();
    return 0;
}