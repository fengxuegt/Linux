/*
 * Created 2022-01-22 19:49:40
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>
#define PI 3.14
#if 0
#define MAX(a, b) \
        ({int A = a, B = b;((A) > (B) ? (A) : (B));})
// 新建参数代替a和b
#endif
#define MAX(a, b) \
        ({typeof(a) A = a, B = b;((A) > (B) ? (A) : (B));})
// 新建参数代替a和b
int main()
{
    int i = 5, j = 3;
    printf("%d, %d\n", i, j); // 5, 3
    printf("%d\n", MAX(i++, j++)); // 5
    printf("%d, %d\n", i, j); // 6, 4
    return 0;
}