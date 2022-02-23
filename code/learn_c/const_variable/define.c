#include<stdio.h>
#include<stdlib.h>
#define PI 3.14
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int main()
{
    int i = 5, j = 3;
    printf("%d, %d\n", i, j); // 5, 3
    printf("%d\n", MAX(i++, j++)); // 6
    printf("%d, %d\n", i, j); // 7, 4
    return 0;
}
