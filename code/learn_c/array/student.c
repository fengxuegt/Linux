/*
 * Created 2022-01-25 23:01:54
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
typedef struct Student {
    char name[10];
    char stu_num[10];
    int score;
} Student;
int main()
{
    int num;
    int min_index;
    int max_index;
    int min_score = 200;
    int max_score = -1;
    printf("begin\n");
    scanf("%d", &num);
    Student temp[num];
    printf("before loop]n");
    for (int i = 0; i < num; i++) {
        scanf("%s", temp[i].name);
        scanf("%s", temp[i].stu_num);
        scanf("%d", &temp[i].score);
        if (temp[i].score >= max_score) {
            max_score = temp[i].score;
            max_index = i;
        }
        if (temp[i].score <= min_score) {
            min_score = temp[i].score;
            min_index = i;
        }
    }
    printf("%s %s\n", temp[max_index].name, temp[max_index].stu_num);
    printf("%s %s\n", temp[min_index].name, temp[min_index].stu_num);
    return 0;
}