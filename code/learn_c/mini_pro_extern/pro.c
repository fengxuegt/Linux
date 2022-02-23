/*
 * Created 2022-01-23 14:21:55
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdlib.h>
#include<stdio.h>
#include"pro.h"
extern int i; // extern时甚至可以省略数据类型，但是不能改变变量的值或者数据类型
void func()
{
    printf("[%s]i = %d\n",__FUNCTION__, i);
}