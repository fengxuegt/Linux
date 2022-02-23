/*
 * Created 2022-01-25 23:43:53
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>
int main()
{
    char str[128];
    int count = 0;
    int last = 0;
    gets(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            last = 0;
        } else {
            if (!last) {
                count++;
                last = 1;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}