# Linux嵌入式编程

## C语言学习

### 发展史：

1960 原型A语言——ALGOL语言

1963 CPL语言

1970 B语言

1973 C语言

### C语言特点：

-   基础性的语言
-   语法简洁、紧凑、灵活、方便
-   运算符、数据结构丰富
-   结构化、模块化编程
-   移植性好，执行效率高
-   允许直接对硬件操作

### 学习建议：

-   概念的正确性
-   写代码
-   阅读优秀的代码
-   大量的练习、面试题

### 讲解思路

-   基本概念
-   数据类型、运算符、表达式
-   输入输出专题
-   流程控制
-   数组
-   指针
-   函数
-   构造类型
-   动态内存管理
-   调试工具和调试技巧（gdb、make）
-   常用库函数

Hello.c:

预处理、编译、汇编、了解

使用gcc可以编译文件，但是容易出错。

```
容易写成gcc -c hello.c -o hello.c，这样的话源文件就会被覆盖；
所以应该使用make： make hello（生成的可执行文件叫做hello）
如果使用make hello.c的话，就会报错：make: Nothing to be done for 'hello.c'
```

编辑器：熟练使用vim



## 一、基本概念

### 以helloworld程序为例对写程序的思路提出如下要求

-   头文件正确包含的重要性

```
gcc hello.c -Wall
```

Include 头文件的影响

```c
int *p = NULL:
p = malloc(sizeof(int));
```

以上代码在编译时会报错：

```shell
error: implicitly declaring library function 'malloc' with type 'void *(unsigned long)' [-Werror,-Wimplicit-function-declaration]
```

以前的认知是觉得malloc返回的是void *类型，然后赋值给p会有类型转换的错误；所以加上强制类型转换，就不会报错；实际上确实不再报错，但是根本原因在于是没有引入stdlib.h，所以没有函数原型的函数，编译器会默认认为函数返回int。

段错误程序

```c
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main()
{
	FILE * fp = NULL:
	fp = fopen("tmp", "r");
	if (fp == NULL) {
		fprintf(stderr, "fopen failed %s", strerror(errno));
		exit(1);
	}
	puts("ok");
	exit(0);
}
```

在以上代码中，如果不包含string.h，那么程序就算通过编译，也会报core dump，因此程序执行遇到问题时，可以先把编译问题全部打印出来（加-Wall参数），解决之后可能段错误就自动解决了；

-   以函数为单位编写程序

-   声明部分和实现部分分开

-   return 0的问题
    return 0的0最终是给程序的父进程看的，当hello world程序没有return 0时，程序最终的状态码是printf的返回值，printf的返回值的话是打印的字符的长度，包含回车，但是不包含'\0'，打印状态码的方式为：

```
echo $?
```

-   多用空格和空行

-   适当添加注释

```
单行注释
//
多行注释
/**/
大段注释
# if 0
# endif
```

### 算法：解决问题的方法。（流程图、NS图、有限状态机FSM）

### 程序：用某种语言实现算法

### 进程：防止写越界、防止内存泄露、谁申请谁释放

## 二、数据类型、运算符和表达式

### 数据类型

-   基本类型

    -   数值类型
    -   字符类型

-   构造类型

    -   数组

    -   结构体

    -   共用体

    -   枚举类型

-   指针类型

-   空类型

1、所占字节数

2、存储区别

3、不同类型的转换（显式——强制类型转换、隐式）

4、特殊性

-   bool类型，要引入stdbool.h；然后bool a = false;
-   float类型，不是准确性的类型，因此float无法判断==0；只能fabs(f - 0) <= 1e-6;;判断f和0的差足够小
-   char类型是有符号还是无符号C标准是未定义的
-   注意不同形式的0值；0, '0',"0",'\0'
-   NULL 和\0的ascall码都是0
-   注意程序的前后一致性，例如定义了变量是unsigned，那么打印的时候就不能用%d

### 常量和变量

**常量：**在程序执行过程中值不会发生变化的量

-   分类：整型常量、实型、字符、字符串、标识常量

    整型：1，20，45

    实型：3.14

    字符型：单引号引起的单个字符或者转义字符，'a', '\n', '\015', '\x7f'

    ```
    '\018'是错误的，因为八进制不能有8
    ```

    字符串常量：双引号引起来的一个或者多个字符组成的序列（空串），"", "a", "abXyz", "abc\n\021\018";最后一个字符串非常特殊，因为\018的存在是要当成\0, 1, 8三个字符来处理的，理由如上；但是当字符串中出现\0时如何处理后续课程讲了再补上吧

    标识常量：#define，并不作类型检查，也不做语法检查，只进行文本替换。所以替换宏的时候要加括号

    宏和函数：宏占用编译时间，节省运行时间；函数占用运行时间，效率低但是更稳定；

    常量不能作为左值来使用

**变量：**程序执行过程中值随时会发生变化的量

定义：【存储类型】数据类型 标识符 = 值 ：TYPE NAME = VALUE；

```
标识符：字母、数字、下划线组成的不能以数字开头的一个标识序列；标识符最好做到见名生义
数据类型：基本类型+构造类型
值：注意匹配
存储类型：auto static register extern（声明型关键字）
	auto：默认（不指定时），自动分配空间，自动回收空间
	register：寄存器类型（建议型关键字）：register int i; //只是建议编译器放入寄存器，实际上由编译器决定；只能定义局部变量，不能定义全局变量，大小有限制，只能定义32位大小的数据类型，如double就不可以；寄存器没有地址，因此无法打印出对应变量的地址（另外一个建议型关键字是inline）
	static：静态类型，自动初始化为0值或空值，并且此种类型变量的值有继承性，另外，常用于修饰变量和函数；
	extern（说明性）：意味着不能改变被说明的变量的值或类型
```

#### 变量的生命周期和作用范围

-   全局变量和局部变量
-   局部变量和局部变量

见同工程cpp

### 运算符和表达式

#### 表达式与语句的区别

加分号的表达式就是语句

#### 运算符部分：

```
每个运算符所需要的参与运算的操作数个数
结合性
优先级
运算符的特殊用法
	例如 %、=与==
位运算的重要意义
```

算数运算符

```c
5 / 2 = 2；
5 % 2 = 1；
5.0 / 2 = 2.5；
5.0 % 2； // error， % 运算必须要求操作数是整型
```

自增运算符

```c
i++ -> i = i + 1;
3++ -> 3 = 3 + 1; // error
int i = 1;
i++; // 表达式的值为1， i的值为2；
++i; // 表达式的值为2， i的值为2；
int i = 1, j = 2, value;
value = i++ + ++j; // value = 3, i = 2, j = 3;
value = i++ + ++i + i-- + --i; // undefined,运算结果取决于编译器，因为并没有规定操作数的求值顺序（同一个值i）
```

逻辑运算符

```
有短路特性，当第一个表达式为0的时候才会计算第二个表达式的值
```

逗号运算符

```
逗号运算符表达式的值是最后一个表达式的值
```

位运算

```
以二进制为单位进行计算
将某个操作数中的第n位置1，其他位不变：num = num | 1 << n;
将某个操作数中的第n位置0，其他位不变：num = num & ~(1 << n);
测试第n位：if (num & 1 << n)
从一个指定宽度的数中取出其中的某几位：
```

## 三、输入、输出专题

### Input & output -> I/O (标准IO 文件IO)

#### 格式化输入输出函数：scanf printf

```
int printf(const char *format, ...);
format: "%[修饰符]格式字符"，参照图片

修饰符：
	m：字符宽度， m < len,原样输出，否则左边补空格，小数的话算一位
	.n：%f，默认是6位小数，（四舍五入）;同样也可作用于字符串，输入特定个数的字符
	-：默认右对齐，-号表示左对齐
	0:自动补0而不是空格（flag '0' is ignored when flag '-' is present [-Wformat]）
	#：八进制或者十六进制输出时前面显示0或者0X
	l：d o x u前面，指定精度为long类型；e f g前面，指定精度为double（函数参数传递12L，否则会报错）
		#define SEC_YEAR (60LL * 60LL * 24LL * 365LL) //防止溢出
	输入数据时最好加上\n，这不仅仅是为了格式好看，是因为加上\n之后可以将缓存区刷新；
	printf("[%s:%d]\n", __FUNCTION__, __LINE__);

int scanf(const char *format, ...);
format: 基本同printf
	%s：非常危险，因为不知道存储空间的大小
	while中使用scanf，需要校验scanf的返回值。
	format:抑制符（吃掉字符）或者getchar吃掉字符
```

#### 字符输入输出函数：getchar putchar

```
返回值错误时都返回EOF
```

#### 字符串输入输出函数：gets puts

```
gets
	非常危险，因为并不确定输入的长度几何；推荐使用fget(char *s, size, FILE* fp);或者get_line；
```



## 四、流程控制



## 五、数组

### 一维数组

```
定义：【存储类型】数据类型 标识符【下标】
初始化：
	不初始化
	全部初始化
	部分初始化
	static(static不能修饰变长数组)
元素引用
	数组名【下标】
数组名
	数组名是一个地址常量，也是整个数组的起始位置
数组越界
	
```

### 二维数组

```
定义、初始化：
	【存储类型】数据类型 标识符【行下标】【列下标】
元素引用：
	数组名【行下标】【列下标】
存储形式：
	顺序存储、按照行存储
深入理解二维数组
```

### 字符数组

```
定义、初始化：
	【存储类型】数据类型 标识符【下标】
	单个字符初始化
	字符串初始化
输入、输出：
	gets函数获取
	scanf("%s", str); // 不能获得空白字符
字符串函数：
	strlen() vs sizeof()
	strcpy(dst, src);
	strncpy(dst, src, size(dst_size));
	strcat(dst, src);
	strncat(dst, src, size());
	strcmp(str, str);
	strcmp(str, str);
```

## 六、指针

### 变量与地址

### 指针与指针变量

### 直接访问与间接访问

### 空指针与野指针

### 空类型

### 定义与初始化的书写规则

### 指针运算

### 指针与数组

#### 指针与一维数组

#### 指针与二维数组

#### 指针与字符数组

```c
//使用方式具体在strcpy时的区别
char * str = "hello";
str = "world"; // 直接改变指针的指向来改变指针指向的内容
char str[] = "hello";
strcpy(str, "world"); // 需要使用strcpy来改变字符数组的内容；
//上述就是在使用字符数组和字符指针时需要注意的地方；
```

### const 与指针

```c
const int pi = 3.14; // 与# define相比，会进行语法检测，并且在符号表中是可以找到符号的; 必须在定义时就进行初始化，因为后续赋值是不合法的；在c语言中，const是一个假的const，可以通过指针间接修改
// 常量指针
const int *p; // 可以直接根据名字区分，比如先看到const ，所以就是常量在前面，就是常量指针
// 指针常量
int * const p; // 先看到* ，所以是指针常量

// const只是限定不能通过当前名字来修改而已 
// const通常应用于函数参数
```

### 指针数组与数组指针

```
数组指针：【存储类型】 数据类型 （*指针名） 【下标】 = 值
	例如： int (*arr)[10];  -->  typename name;   -->  int[3]  *p; 
	
指针数组：【存储类型】 数据类型 *（数组名）【下标】 = 值
	例如： int * arr[10];
```

### 多级指针

## 七、函数

### 函数的定义

数据类型 函数名(【数据类型 形参名， 数据类型 形参名...】)

### 函数的传参

值传递

地址传递

全局变量传递

### 函数的调用



### 函数与数组



### 函数与指针



## 八、构造类型

### 结构体

产生和意义

```
数据封装
成员同时存在
```

类型描述

```c++
struct Birthday {
	int year;
    int month;
    int day;
};

struct Student {
	char name [32];
	int age;
	Birthday birte;
};

// 以上是将结构体定义在外面，同样可以将结构体定义在结构体内部，如下：
struct Student {
  	char name[32];
    int age;
    struct Birthday {
        int year;
        int month;
        int day;
    } birth;
};

struct Student s = {.math = 23, .chinese = 31}; // 部分内容赋值
```

嵌套定义

定义变量（变量、数组、指针），初始化及成员引用

```
成员引用：
    变量名.成员名
    指针名->成员名
    (*指针名).成员名
```

结构体占用内存大小

```
编译器能够更方便的进行取值
网络传输的时候不能使用对齐，就需要在声明结构体的时候做处理；
struct  simp_st {
	int i;
	char ch;
}__attribute__((packed)); // 这样的话结构体就不会再对齐了
```

结构体作为函数参数（值、地址）

```
一般使用地址传参，可以节省内存；
```



### 共用体

产生及意义

```
多个成员只有一个存在，多个选项只能选择一个
```

类型描述

```
union 共用体名
{
	数据类型 成员名；
	数据类型 成员名；
};
```

嵌套定义

```c++
struct {
	int i;
    char ch;
    union {
      int a;
      float b;
    }un;
    float f;
};

union {
    struct {
        int a;
        char b;
    } stu;
    int q;
};

union tmp
{
    struct
    {
        short a; // uint16_t a;
        short b; // uint16_t b;
    }num;
    int i; // uint32_t i;

};

unsigned int i = 0x11223344; // uint32_t i = 0x11223344;
printf("%x\n", (i >> 16) + i & 0xFFFF);
union tmp t;
t.i = 0x11223344;
printf("%x\n", t.num.a + t.num.b);
```

定义变量

```
成员引用：
    变量名.成员名
    指针名->成员名
    (*指针名).成员名
```

占用内存大小

```
内存最大的成员
```

函数传参

```
一般使用地址
```

位域

```c++
union
{
    struct 
    {
        char a:1;
        char b:2;
        char c:1;
    }x;
    char y;
}w;
// 使用情况比较少
```

### 枚举

```
enum 标识符
{
	成员 1；
	成员2；
};
```



```c
enum day {
    MON = 1,
    TUE, // 2
    WED, // 3
    THU = 1, // 允许重复，并且从上一个值开始++
    FRI, // 2
    SAT = -1, // 3
    SUN
};
// 在预处理时，enum不会被替换，但是define会被替换；因此使用enum当作一连串的宏来使用就可以
// 一般在switch中使用
```



## 九、动态内存管理

原则：谁申请，谁释放；

### malloc(size_t size);

### calloc(size_t ele_num, size_t ele_size);

### realloc(void *ptr, size_t size);

### free(void * ptr);

```
free掉之后最好把指针置空
```

### typedef

为已有的数据类型改名

```
typedef 类型名 新名字
```

#define和typedef的区别

```c
#define INT int
typedef int TNT
INT i --> int i;

#define IP int *
typedef int *IP

IP p, q; --> int *p, q;
IP p, q; --> int *p, *q;


typedef int ARR[6] --> int[6] -> ARR
ARR a; --> int a[6];

typedef struct {
    int i;
    int j;
} NODE, *NODEP; // 这样的struct叫NODE，这样的struct *叫NODEP

typedef int FUN(int);  -->  int(int) -> FUN;
FUN f; --> int f(int);

typedef int *FUNC(int);
FUNC p; --->  int *p(int);

typedef int* (*FUNC)(int);
FUNC p; ---> int*(*p)(int);
```



## 十、makefile

工程管理make时默认使用小写m开头的makefile，但是发布的工程中都是发布的Makefile，这是为了使用户自定义makefile。

makefile典型例子：

```makefile
OBJS=main.o tool1.o tool2.o
CC=gcc
CFLAGS+=-c -g -Wall
mytool:$(OBJS)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@
clean:
	$(RM) *.o mytool -r
```



# 数据结构



## 树

```
基本概念：
    深度
    度
    叶子
    孩子
    兄弟
    堂兄弟
二叉树：
	满二叉树
	完全二叉树
存储：
	顺序存储，非常直观，左孩子：2 * i， 右孩子：2 * i + 1
	链式存储
遍历：
	按行
	前序
	中序
	后序
```



# Linux_c 系统开发笔记

## 标准IO

```
I/O : input & output 是一切实现的基础
stdio 标准IO
sysio 系统调用IO（文件IO）

stdio： APUE（第五章） FILE 类型贯穿始终
fopen();
fclose();
fgetc();
fputc();
fgets();
fputs();
fread();
fwrite();
printf();
scanf();
fseek();
ftell();
rewind();
fflush();
```

```c++
FILE *fopen(const char *pathname, const char *mode); // Linux b是被忽略的
/*
    char *ptr = "abc";
    ptr[0] = 'x';
	// Segmentation fault (core dumped)
*/
errno: 在未定义的情况下是一个全局变量
    // vim /usr/include/asm-generic/errno-base.h, 现在是一个全局变量
// mode只认识字符串的开头一个或者两个字符，例如如果填写 “readwrite”，会认为是“r”，因为后面的不认识
// int *ptr = malloc(sizeof(int));
// 上述语句会报类型不匹配的警告，有人会将右侧的表达式强转为（int*），这样警告确实会消失，但是这不是真正的原因。
// 真正的原因是没有包含<stdlib.h>，没有包含此头文件，那么编译器不认识malloc函数，就会默认malloc函数返回int类型，因此会报类型不匹配的警告，其实void*类型赋值给任何类型都是合法的，并不会报警告
perror("fopen"); // 打印出fopen，然后加上异常的原因，主要作用是将errno转换为错误信息
strerror(errno); // 将errno转化为错误信息
// 返回的FILE * 是分配在堆上的
int fclose(FILE *stream); // succ return 0; fail return EOF
// stream -> stdin stdout stderr
// 当利用w创建文件时，文件的权限是664，这个权限是通过 0666 & ~umask 来计算出来的
// umask 是0002，因此计算之后为664
```

```c
fgetc() getc() fgetc()
fputc() putc() fputc()
// 见cpp学习
```

```c
fgets();
gets();
fgets(char *, size, stream);
	size - 1; // 
	'\n' // 
#define SIZE 5
char buf[SIZE];
fgets(buf, SIZE, stream);
// 使用getcs读取文件，一定要记得文件最后有一个多余的\n字符。例如：
// 使用上述程序读取abcd，size为5，需要读取几次。
// 答案是两次，第一次读取size - 1 个字符，为abcd\0; 第二次读取\n\0;因此是读取两次；
while (fgets(buf, 1024, fps) != NULL) {
    fputs(buf, fpd);
}
fputs();
puts();
```

```c
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t nmemb,
                     FILE *stream);
// fread(buf, size, num, fp); 返回读取成功的对象的个数
// 数据量足够
fread(buf, 1, 10, fp); // return 10
fread(buf, 10, 1, fp); // return 1
// 数据量不够，例如只有5个字节
fread(buf, 1, 10, fp); // return 5 ，返回读取成功的对象个数
fread(buf, 10, 1, fp); // return 0 ，但是不知道还剩多少字节
while ((n = fread(buf, 1, 1024, fps)) > 0) {
    fwrite(buf, 1, n, fpd);
}
```

```c
int printf(const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);
int dprintf(int fd, const char *format, ...);
int sprintf(char *str, const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);
// char str[] = "1234567";
// printf("%d\n", atoi(str)); // 1234567;
// char str[] = "1234a567";
// printf("%d\n", atoi(str)); // 1234;

char buf[1024];
int year = 2014, month = 5, day = 3;
sprintf(buf, "%d-%d-%d", year, month, day);
puts(buf); // 会自动添加换行
```

```c



int fseek(FILE *stream, long offset, int whence); // 定位
// whence SEEK_SET SEEK_CUR SEEK_END
long ftell(FILE *stream); // 返回当前指针位置
rewind(FILE *stream); // 将指针放到文件首
int fseeko(FILE *stream, off_t offset, int whence);
off_t ftello(FILE *stream);

// makefile
// CFLAGS+=-D_FILE_OFFSET_BITS=64 // 加上这个宏之后，off_t 就是64位的
// fseek可以用于下载文件
```

```c
fflush(FILE *stream);
// 强制刷新流，如果stream == NULL， 那么就会刷新所有的流
/* 缓存区的作用：
	大多数情况下是好事，可以合并系统调用
	行缓冲：换行时刷新，满了的时候刷新，强制刷新
	全缓冲：满刷新、强制刷新
	无缓冲：stderr，需要立即输出的内容
	setvbuf()
*/
```

```c
getline()
// -D_GNU_SOURCE, 写在makefile中
/* 临时文件
	如何不冲突的创建
	尽快释放
FILE *tmpfile(void);
	创建一个文件，占用空间，但是ls看不到；返回给用户FILE*，用户使用之后调用fclose()；
*/
```

## 系统IO

```
文件描述符是在文件IO/系统调用IO贯穿始终的类型fd
文件描述符的概念（是一个整型数，是一个结构体数组的下标）
文件IO的操作：open close read write lseek
文件IO和标准IO的区别
举例：传达室大爷跑邮局
区别：响应速度&吞吐量
面试：如何使一个程序变快？（其实是吞吐量如何变大）
提醒：文件IO和标准IO不可混用
转换：fileno、fdopen
IO的效率问题
文件共享
	面试题：删除文件的第十行
	补充函数：truncate/ftruncate
原子操作：不可分割的操作
	原子：不可分割的最小单位
	原子操作的作用：解决竞争和冲突
程序中的重定向：dup、dup2
	见dup.cpp
同步：sync fsync fdatasync 
	void sync(void); // 关机的时候
	int fsync(int fd); // 同步一个文件的cache
	int fdatasync(int fd); // 只刷数据，不刷亚数据（文件属性等）
int fcntl(int fd, int cmd, .../* arg */): 文件描述符相关的魔术几乎都来自于该函数
ioctl(); // 设备相关的内容
/dev/fd/目录：是一个虚目录，显示的是当前进程的文件描述符信息
```

```
stdin stdout stderr 对应的文件描述符是012
fd优先使用可用范围内最小的数字；
每个进程中都有一个结构体数组；
一个进程中多次打开一个文件，会产生多个结构体；
结构体中会有一个计数器，来计算指向它的指针的个数；
```

```c
文件IO相关操作函数
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
```



## 文件系统

类似ls的实现，如myls，-a -l -i -n

### 目录和文件

-   获取文件属性

    ```c
    #include<sys/types.h>
    #include<sys/stat.h>
    #include<unistd.h>
    int stat(const char *pathname, struct stat *statbuf);
    int fstat(int fd, struct stat *statbuf);
    int lstat(const char *pathname, struct stat *statbuf);
    struct stat {
                   dev_t     st_dev;         /* ID of device containing file */
                   ino_t     st_ino;         /* Inode number */
                   mode_t    st_mode;        /* File type and mode //16 bit*/
                   nlink_t   st_nlink;       /* Number of hard links */
                   uid_t     st_uid;         /* User ID of owner */
                   gid_t     st_gid;         /* Group ID of owner */
                   dev_t     st_rdev;        /* Device ID (if special file) */
                   off_t     st_size;        /* Total size, in bytes */
                   blksize_t st_blksize;     /* Block size for filesystem I/O */
                   blkcnt_t  st_blocks;      /* Number of 512B blocks allocated */
    };
    // 见stat.c;那就是使用stat函数获得文件的属性
    // 空洞文件，见big.cpp ./big /tmp/bigfile
    // 查看st_mode的宏
    ```

-   文件访问权限

    ```
    st_mode是一个16位的位图，用于表示文件类型，文件访问权限，及特殊权限位
    ```

-   umask

    ```
    0666 & ～umask
    可以使用umask命令改变umask的值
    作用：防止产生权限过松的文件
    chmod（）函数，用于更改文件权限
    ```

-   文件权限的更改/管理

    ```
    chmod
    fchmod
    不只是命令，也是函数
    ```

-   沾住位

    ```
    t位：最初的使用方式是给一个二进制的可执行命令加上t位，可以将其放入到缓存当中（保留执行的痕迹）下次执行的时候可以更快的执行，但是现在都有缓存的概念了，所以基本不怎么用了，但是/tmp的权限符还是t位的
    ```

-   文件系统：FAT、UFS

    ```
    文件系统：文件或数据的存储和管理
    ```

-   硬链接、符号链接

-   utime

-   目录的创建和销毁

-   更改当前工作路径

### 系统数据文件和信息



### 进程环境
