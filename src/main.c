#include "VocaCtl.h"

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void XN_gets(char* input, int max) {
    fgets(input, max, stdin);
    if(input[strlen(input) - 1] != '\n') {
        printf("You have input much more, extra data will be deleted.\n");
        fflush(stdin);
    }
}

int call_menu() {
    char input_1[MAX_INPUT] = {0}, input_2[MAX_INPUT] = {0};
    int input_0 = 0, exit = 0, rec = 0;
    printf("Welcome to the SC balabala!\n1.add word\n2.search for word\n3.delete word\n4.test\n5.exit\n");
    for(;exit == 0;) {
        printf("Input the number:\n");
        scanf("%d", &input_0);      // 不考虑strtol，至少现在是
        while (getchar() != '\n');        // 一个很有意思的清空缓冲区的技巧，不然的话下面的fgets会读取一个换行符。顺带一提，我有想过在scanf里使用%d\n这种写法，却出现了奇怪的问题，所以换这个方式。
        switch (input_0) {
            case 1:
                printf("Enter the words and definitions in sequence, with a line break in the middle\n");
                XN_gets(input_1, MAX_INPUT);
                XN_gets(input_2, MAX_INPUT);
                rec = add_voca(input_1, input_2);
                if (rec != -1 && rec != -2)
                    printf("You have saved it! Meaning : %s", VocaList[rec].meaning);
                else rec == -1 ? printf("%s\n", STR_SUCCESS) : printf("%s\n", STR_FAILURE);
                break;
            case 2:
                printf("Input the word which you want to search for!\n");
                XN_gets(input_1, MAX_INPUT);
                rec = search_voca(input_1);
                rec == -1 ? printf("%s\n", STR_NO_FOUND) : printf("%s", VocaList[rec].meaning);
                break;
            case 3:
                printf("Let's explore the area ahead in the future!\n");        // 前面的区域以后再来探索吧！
                break;
            case 4:
                printf("Test Start!");
                if(voca_num == 0)
                    printf("......But you did not add vocabulary just now!\n");     // 如果在这之前没有存储单词的话，就实话实说，main里的函数也不会触发
                else {
                    for (;;) {
                        rec = rand_voca();
                        printf("\nWhat's the meaning of %s\n", VocaList[rec].word);
                        XN_gets(input_1, MAX_INPUT);
                        if (strcmp(input_1, "exit\n") == 0)
                            break;
                        else if (strcmp(input_1, VocaList[rec].meaning) == 0)
                            printf("Nice Job!\n");
                        else
                            printf("The true meaning is %s", VocaList[rec].meaning);
                    }
                }
                break;
            case 5:
                exit = 1;
                break;
            default:
                printf("?\n");
                break;
        }
    }
    printf("See you\n");
}

int main() {
    VocaList = (voca*) malloc(sizeof(voca));    // 先弄一个结构体的空间
    srand(time(NULL));        // 用时间做种，但是返回的类型可能会大于int，在考虑用不用(unsigned int)一下
    call_menu();
    // free(VocaList);     感觉这里没必要free就删掉了，毕竟没什么比程序结束了释放更快了。而且就算这里free了一个Vocalist，还有很多结构体内的动态内存没有free。
    return 0;
}
