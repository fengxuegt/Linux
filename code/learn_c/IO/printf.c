/*
 * Created 2022-01-23 17:56:50
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define STRSIZE 32
int main()
{
    int j = 255;
    int i = 123;
    float f = 123.456;
    char str[STRSIZE] = "helloworld";
    printf("j = %#o; j = %#x\n", j, j);
    printf("f = %8.1f\n", f);
    printf("i = %05d\n", i);
    printf("%-10.5s[s]\n", str);


    printf("%d %e\n", i, f); // 参数太少或者参数太多，编译是可以通过的，也可以正常运行，但是输出的内容不确定（栈中的数据）
    // 区分是函数重载实现的还是变参实现的方法就是传递进入不同个数的参数；编译出现错误那就是重载，否则是变参数

    printf("[%s:%d] Before sleep.\n", __FUNCTION__, __LINE__);
    sleep(2);
    printf("[%s:%d] After sleep.\n", __FUNCTION__, __LINE__);
    return 0;
}
