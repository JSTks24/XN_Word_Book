#include "IOCtl.h"
#include "MsgDef.h"
#include "VocaCtl.h"

#include <stdio.h>
#include <string.h>

int auto_print(int renum) {
    switch (renum) {
        case INT_FUC_SUCCESS:
            printf("Success!\n");
            break;
        case INT_FUC_FAIL:
            printf("Failure!\n");
            break;
        case INT_ERROR_INPUT_OF:
            printf("Excessive input! Input again plz!\n");
            break;
        case INT_ERROR_INPUT_LOW:
            printf("Insufficient input! Input again plz!\n");
            break;
        case INT_ERROR_MULTIPLE_INPUT:
            printf("You have saved it! Don't save again!\n");
            break;
        case INT_ERROR_WORD_NO_FOUND:
            printf("No found!\n");
            break;
        case INT_ERROR_FILE_NO_FOUND:
            printf("No such file!\n");
            break;
        default:
            printf("Meaning : %s\n", VocaList[renum].meaning);
            break;
    }
    return renum;
}

int XN_gets(char* input, int max) {
    fgets(input, max, stdin);
    if (input[strlen(input) - 1] != '\n') {
        fflush(stdin);
        return INT_ERROR_INPUT_OF;
    } else {
        fflush(stdin);
        input[strlen(input) - 1] = '\0';
        return strcmp(input, "exit") != 0 ? INT_FUC_SUCCESS : INT_FUC_EXIT;
    }
}

void call_menu() {
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
                while(XN_gets(input_1, MAX_INPUT) != INT_FUC_SUCCESS);
                while(XN_gets(input_2, MAX_INPUT) != INT_FUC_SUCCESS);
                auto_print(add_voca(input_1, input_2));
                break;
            case 2:
                printf("Input the word which you want to search for!\n");
                XN_gets(input_1, MAX_INPUT);
                auto_print(search_voca(input_1));
                break;
            case 3:
                printf("Let's explore the area ahead in the future!\n");        // 前面的区域以后再来探索吧！
                break;
            case 4:
                printf("Test Start!");
                if(voca_num == 0)
                    printf("......But you did not add vocabulary just now!\n");
                else {
                    for (;;) {
                        rec = rand_voca();
                        printf("\nWhat's the meaning of %s\n", VocaList[rec].word);
                        XN_gets(input_1, MAX_INPUT);
                        if (strcmp(input_1, "exit") == 0)
                            break;
                        else if (strcmp(input_1, VocaList[rec].meaning) == 0)
                            printf("Nice Job!");
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