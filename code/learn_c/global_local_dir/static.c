/*
 * Created 2022-01-23 13:54:16
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */
#include<stdlib.h>
#include<stdio.h>

void func(void)
{
    static int x = 0;
    x = x + 1;
    printf("%p->%d\n", &x, x);
}

int main()
{
    func();
    func();
    func();

    return 0;
}
/*
0x100620000->1
0x100620000->2
0x100620000->3

这里的地址一定是相同的，因为static数据只有一块
*/


#if 0 // x is not static
#include<stdlib.h>
#include<stdio.h>

void func(void)
{
    int x = 0;
    x = x + 1;
    printf("%p->%d\n", &x, x);
}

int main()
{
    func();
    func();
    func();

    return 0;
}

/*
0x16d22745c->1
0x16d22745c->1
0x16d22745c->1
这里的地址不一定是相同的
*/
#endif

