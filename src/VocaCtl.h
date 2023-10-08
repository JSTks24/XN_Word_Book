#ifndef FST_INC
#define FST_INC

#include "MsgDef.h"

typedef struct Vocabulary{
    char* word;
    char* meaning;
} voca;

extern voca* VocaList;
extern int voca_num;

void voca_init();

//void voca_close();        //清空所有内存，准备退出

int search_voca(char* in_word);       //查找单词

int add_voca(char* in_word, char* in_meaning);     // 添加单词

//int del_voca();        // 删除单词

int rand_voca();       // 随机取词

#endif