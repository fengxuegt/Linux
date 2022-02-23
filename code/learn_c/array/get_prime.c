/*
 * Created 2022-01-25 00:22:31
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 * 
 * 删除法求素数
 */

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[1001] = {0};
    for (int i = 2; i < 1001; i++) {
        if (arr[i] != -1) {
            arr[i] = i;
        }
        for (int j = i + 1; j < 1001; j++) {

            if (arr[j] == 0) {
                if (j % i == 0) {
                    arr[j] = -1;
                }
            }

        }
    }
    for (int i = 2; i < 1001; i++) {
        if (arr[i] != 0 && arr[i] != -1) {
            printf("%d\n", arr[i]);
        }
    }
    return 0;
}