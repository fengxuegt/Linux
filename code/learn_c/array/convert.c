/*
 * Created 2022-01-25 00:08:25
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>
void base_cover()
{
    int num, base;
    int i;
    int weight[32];
    printf("please input a number to convert: \n");
    scanf("%d", &num);
    printf("please input the base: \n");
    scanf("%d", &base);
    for (i = 0; num != 0; i++) {
        weight[i] = num % base;
        num /= base;
    }
    for (int j = i - 1; j >= 0; j--) {
        if (weight[j] >= 10) {
            printf("%c", weight[j] - 10 + 'A');
        } else {
            printf("%d", weight[j]);
        }

    }
    printf("\n");
}
int main()
{
    base_cover();
    return 0;
}