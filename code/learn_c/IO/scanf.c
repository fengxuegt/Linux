/*
 * Created 2022-01-23 19:35:51
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

/*
int scanf(const char *format, 地址表);

*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 32
int main()
{
    int i;
    float f;
    char ch, str[SIZE];
    printf("please input:\n");

    scanf("%d", &i);
    scanf("%*c%c", &ch); // 抑制符，可以把字符吃掉，或者用getchar吃掉
    // ch = getchar(); // 空白字符也会读入
    printf("i = %d, ch = %d\n", i, ch);


    // 输入a时会死循环，解决方法是校验scanf的返回值
    // while (1) {
    //     scanf("%d", &i);
    //     printf("i = %d\n", i);
    // }

    // scanf("%s", str); // 非常危险
    // printf("%s\n", str);


    // scanf("%d,%f", &i, &f);
    // printf("i = %d\n", i);
    // printf("f = %f\n", f);
    return 0;
}