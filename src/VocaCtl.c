#include "VocaCtl.h"

#include <stdlib.h>
#include <string.h>

voca* VocaList = NULL;     // 定义了一个结构体指针，用来存放单词的列表
int voca_num = 0;       // 存入单词的个数，方便单词列表依次写入

int search_voca(char* in_word){
    for (int i = 0; i < voca_num; i++)
        if(strcmp(VocaList[i].word, in_word) == 0)
            return i;
    return -1;
}

int add_voca(char* in_word, char* in_meaning) {
    int search = search_voca(in_word);        // 首先准备看一下这个单词是否存在，存在的话返回一下存在的意思
    if(search == -1) {
        voca *a_word = (voca *) malloc(sizeof(voca));
        a_word->word = (char *) malloc((strlen(in_word) + 1) * sizeof(char));
        a_word->meaning = (char *) malloc((strlen(in_meaning) + 1) * sizeof(char));
        if(a_word->word == NULL && a_word->meaning == NULL)     // 检测分配内存是否有问题
            return -2;
        strcpy(a_word->word, in_word);
        strcpy(a_word->meaning, in_meaning);
        VocaList = (voca *) realloc(VocaList, sizeof(voca) * (voca_num + 1));       // 边用边扩容，这个表述总觉得第一次扩容扩了个寂寞
        if (VocaList == NULL) {      // realloc是有可能fail的，这里稍微检测一下realloc有没有问题
            free(a_word);        // 释放自我！
            return -2;
        } else {
            VocaList[voca_num] = *a_word;       // 动态数组，但是有点好奇这里能否用指针的写法重构
            voca_num++;
            free(a_word);        // 释放自我！
            return -1;
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

int rand_voca(){
    int random = 0;
    random = rand() % voca_num;
    return random;
}