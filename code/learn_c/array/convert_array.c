/*
 * Created 2022-01-25 21:21:33
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>
#define M 2
#define N 3
int main()
{
    int a[M][N] = {{1, 2, 3}, {4, 5, 6}};
    int b[N][M];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            b[j][i] = a[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}