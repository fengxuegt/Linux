/*
 * Created 2022-01-23 14:21:48
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdlib.h>
#include<stdio.h>
#include"pro.h"

static int i = 10;


int main()
{
    printf("[%s]i = %d\n", __FUNCTION__, i);
    call_func(); // 
    return 0;
}