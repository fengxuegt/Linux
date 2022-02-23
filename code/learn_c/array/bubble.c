/*
 * Created 2022-01-24 23:39:38
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>

void bubble(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t; 
            }
        }
    }  
}

int main()
{
    int arr[7] = {1, 3, 4, 2, 9, 7, 5};
    bubble(arr, 7);
    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}