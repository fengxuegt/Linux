/*
 * Created 2022-01-23 21:37:04
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>
#define WEIGHT 3.0E-23
#define KQ 950

static void water()
{
    printf("Please input a num:\n");
    float num;
    float sum;
    scanf("%f", &num);
    sum = num * KQ / WEIGHT;
    printf("%e\n", sum);
}




int main()
{
    // water();
    return 0;
}