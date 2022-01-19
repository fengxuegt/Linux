/*
 * Created 2022-01-19 21:54:44
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFF_SIZE 4096
void oops(char *s1, char *s2);
int main(int argc, char **argv)
{
    char buf[BUFF_SIZE];
    int in_no, out_no, n_chars;
    if (argc != 3) {
        oops("userage: %s", *argv);
        exit(1);
    }
    if ((in_no = open(*++argv, O_RDONLY)) == -1) {
        oops("can not open", *argv);
        exit(1);
    }
    if ((out_no = creat(*++argv, 0644)) == -1) {
        oops("can not creat", *argv);
        exit(1);
    }
    while ((n_chars = read(in_no, buf, BUFF_SIZE)) > 0) {
        if (write(out_no, buf, n_chars) != n_chars) {
            oops("write error", *argv);
        }
    }
    if (n_chars == -1) {
        oops("read error from ", *--argv);
    }
    if (close(in_no) == -1 || close(out_no) == -1) { // 最后关闭
        oops("Error close files", "");
    }
    return 0;
}

void oops(char *s1, char *s2) // 输出错误信息
{
    fprintf(stderr, "%s", s1);
    perror(s2);
    exit(1);
}