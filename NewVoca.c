// 处理单词的输入和输出
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SAVE 66

int voca_num = 0;       // 存入单词的个数，方便单词列表依次写入

char* search_voca(char* in_word);       //查找单词
char* add_voca(char* in_word, char* in_meaning);     // 添加单词
//char* del_voca();        // 删除单词
char* rand_voca();       // 随机取词

typedef struct Vocabulary{
    char word[MAX_SAVE];
    char meaning[MAX_SAVE];
} voca;
voca* VocaList;     // 定义了一个结构体指针，用来存放单词的列表

char* search_voca(char* in_word){
    char* no_found = "No Found!\n";
    for (int i = 0; i < voca_num; i++)
        if(strcmp(VocaList[i].word, in_word) == 0)
            return VocaList[i].meaning;
    return no_found;
}

char* add_voca(char* in_word, char* in_meaning) {
    char* search = search_voca(in_word);        // 首先准备看一下这个单词是否存在，存在的话返回一下存在的意思
    if(strcmp(search, "No Found!\n") == 0) {
        char* success = "Success!\n";
        char* fail = "Failure!\n";
        voca *words = (voca *) malloc(sizeof(voca));
        strcpy(words->word, in_word);
        strcpy(words->meaning, in_meaning);
        VocaList = (voca *) realloc(VocaList, sizeof(voca) * (voca_num + 1));       // 边用边扩容，这个表述总觉得第一次扩容扩了个寂寞
        if (VocaList == NULL) {      //realloc是有可能fail的，这里稍微检测一下realloc有没有问题
            free(words);        // 释放自我！
            return fail;
        } else {
            VocaList[voca_num] = *words;       // 动态数组，但是有点好奇这里能否用指针的写法重构
            voca_num++;
            free(words);        // 释放自我！
            return success;
        }
    } else {
        return search;      // 这里返回的时候注意一下
    }
}

/*
 char* del_voca(){}
 关于删除代码的实现，其实我有一点想法。我想让检索到的代码，如上面search函数中的i。我将这个值存在一个专门的数组中，依次排序，每次删除就存入一个。
 这样当我想add的时候，函数会优先判断数组中是否含有i，有的话可以直接在i的位置写，写之后把数组中的i去掉。如果没有i，再正常申请内存写入。
 或许有更好的办法，但是目前我只能想到这个方法，而且这样实现略有麻烦，我在写下这段代码的时候恐怕已经没有空闲完成了。那就之后我找个时间完成后git一下吧。
*/

char* rand_voca(){
    int random = 0;
    if(voca_num == 0) {
        printf("......But you did not add vocabulary just now!\n");     // 如果在这之前没有存储单词的话，就实话实说，main里的函数也不会触发
        return "6";
    } else {
        random = rand() % voca_num;
        printf("\nWord : %sInput meaning plz!\n", VocaList[random].word);
        return VocaList[random].meaning;
    }
}