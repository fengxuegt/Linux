/*
 * Created 2022-01-23 14:21:55
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdlib.h>
#include<stdio.h>
#include"pro.h"

static int i = 100;
static void func()
{
    printf("[%s]i = %d\n",__FUNCTION__, i);
}

void call_func() // 需要用call_func包装一层，否则static函数无法在文件外使用
{
    func();
}