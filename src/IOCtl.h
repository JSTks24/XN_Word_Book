#ifndef IOCTL
#define IOCTL

#define MAX_INPUT 50
#define MAX_FILELINESTR 100

//int voca_save();      //将单词表存储成文件，还没写

//int voca_read();      //将单词表从文件中读取，还没写

//int lang_read();      //想尝试一下把所有可能需要输出或者传递的字符信息存到一个文件里。虽然单词本没有外语化的必要，但是对于这个功能的实现抱着好奇心，想试一下。

int auto_print(int renum);      //自动化输出各种函数正常或异常状态的函数

int XN_gets(char* input, int max);      //读取一个不超过max的字符串，处理好并存储

void call_menu();       //召唤目录交互列表

#endif