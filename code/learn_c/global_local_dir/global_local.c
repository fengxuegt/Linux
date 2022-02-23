/*
 * Created 2022-01-23 14:04:56
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>
int i = 0;
void print_star()
{
    for (i = 0; i < 5; i++) {
        printf("*");
    }
    printf("\n");
    printf("[%s]i = %d\n", __FUNCTION__, i);
}

int main()
{
    for (i = 0; i < 5; i++) {
        print_star();
    }
    printf("[%s]i = %d\n", __FUNCTION__, i);
    return 0;
}
// 只打印出了一行星号，因为i时全局变量，所有模块都使用了同一个i;这就是全局变量的问题



#if 0
#include<stdlib.h>
#include<stdio.h>
int i = 100;
void func(int i)
{
    printf("i = %d\n", i);
}

int main()
{
    int i = 3;
    func(i);
    {
        int i = 5;
        printf("i = %d\n", i);
    }
    return 0;
}

// 对于作用域来讲，永远是内部作用域屏蔽外部作用域；全局变量的作用域范围是从值被定义开始，到当前块结束
#endif