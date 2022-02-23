/*
 * Created 2022-01-23 21:26:49
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 32
int main()
{
    char str[SIZE];
    gets(str); // 推荐使用fgets代替， getline是只存在于gnu c的
    puts(str);
    return 0;
}