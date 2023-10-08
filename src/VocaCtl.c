#include "VocaCtl.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

voca* VocaList = NULL;     // 定义了一个结构体指针，用来存放单词的列表
int voca_num = 0;       // 存入单词的个数，方便单词列表依次写入

void voca_init() {
    VocaList = (voca*) malloc(sizeof(voca));    // 先弄一个结构体的空间
    srand((unsigned int)time(NULL));        // 用时间做种
}

int search_voca(char* in_word){
    for (int i = 0; i < voca_num; i++)
        if(strcmp(VocaList[i].word, in_word) == 0)
            return i;
    return INT_ERROR_WORD_NO_FOUND;
}

int add_voca(char* in_word, char* in_meaning) {
    int search = search_voca(in_word);        // 首先准备看一下这个单词是否存在，存在的话返回一下存在的意思
    if(search == INT_ERROR_WORD_NO_FOUND) {
        VocaList = (voca *) realloc(VocaList, sizeof(voca) * (voca_num + 1));       // 边用边扩容，这个表述总觉得第一次扩容扩了个寂寞
        if (VocaList == NULL)      // realloc是有可能fail的，这里稍微检测一下realloc有没有问题
            return INT_FUC_FAIL;
        else {
            VocaList[voca_num].word = (char *) malloc((strlen(in_word) + 1) * sizeof(char));
            VocaList[voca_num].meaning = (char *) malloc((strlen(in_meaning) + 1) * sizeof(char));
            if(VocaList[voca_num].word == NULL || VocaList[voca_num].meaning == NULL)     // 检测分配内存是否有问题
                return INT_FUC_FAIL;
            strcpy(VocaList[voca_num].word, in_word);
            strcpy(VocaList[voca_num].meaning, in_meaning);
            voca_num++;
            return INT_FUC_SUCCESS;
        }
    } else {
        return INT_ERROR_MULTIPLE_INPUT;      // 这里返回的时候注意一下
    }
}

/*
 int del_voca(){}
 这里重新思考了一下，似乎没有那么复杂，因为结构体指针拿来做结构体数组使用的时候，可以按照大小分块，直接去掉对应的区块然后后面往前拉就好了。
 不过分配空间大小这个是我来决定的，我想知道如果分配一个1.5倍结构体的空间，那对于第一个结构体区块，是肯定可以用来储存的。后面是否会视为一个结构体？
 如果视为未定义的区域，那平常直接把结构体指针当数组用的做法不本来就是错的？那刚才那个c文件就有重大失误了。这里还要想办法找找资料或者了解一下。
 如果Neboer或者别人看到了这条注释，可以帮我解答一下。
*/

int rand_voca(){
    int random = 0;
    random = rand() % voca_num;
    return random;
}