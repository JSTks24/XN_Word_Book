#include "NewVoca.c"

#define MAX_INPUT 50

int main() {
    VocaList = (voca*) malloc(sizeof(voca));    // 先弄一个结构体的空间
    char input_1[MAX_INPUT] = {}, input_2[MAX_INPUT] = {}, rec[MAX_SAVE] = {};
    int input_0, exit_0 = 0, exit_1 = 0;
    printf("Welcome to the SC balabala!\n1.add word\n2.search for word\n3.delete word\n4.test\n5.exit_0\n");
    for(;exit_0 == 0;) {
        printf("Input the number:\n");
        scanf("%d", &input_0);      // 不考虑strtol，至少现在是
        while (getchar() != '\n');        // 一个很有意思的清空缓冲区的技巧，不然的话下面的fgets会读取一个换行符。顺带一提，我有想过在scanf里使用%d\n这种写法，却出现了奇怪的问题，所以换这个方式。
        switch (input_0) {
            case 1:
                printf("Enter the words and definitions in sequence, with a line break in the middle\n");
                fgets(input_1, MAX_INPUT, stdin);
                fgets(input_2, MAX_INPUT, stdin);
                strcpy(rec, add_voca(input_1, input_2));
                if (strcmp(rec, "Success!\n") == 0 || strcmp(rec, "Failure!\n") == 0)
                    printf("%s", rec);
                else
                    printf("You have saved it! Meaning : %s", rec);
                break;
            case 2:
                printf("Input the word which you want to search for!\n");
                fgets(input_1, MAX_INPUT, stdin);
                printf("%s", search_voca(input_1));
                break;
            case 3:
                printf("Let's explore the area ahead in the future!\n");        // 前面的区域以后再来探索吧！
                break;
            case 4:
                printf("Test Start!");
                for(strcpy(rec, rand_voca());strcmp(rec, "6") != 0 && exit_1 == 0;strcpy(rec, rand_voca())) {
                    fgets(input_1, MAX_INPUT, stdin);
                    if(strcmp(input_1, "exit\n") == 0)
                        break;
                    else if(strcmp(input_1, rec) == 0)
                        printf("Nice Job!\n");
                    else
                        printf("The true meaning is %s", rec);
                }
                break;
            case 5:
                exit_0 = 1;
                break;
            default:
                printf("?\n");
                break;
        }
    }
    free(VocaList);     // 另一个C文件里释放自我过了，现在可以变身了
    printf("See you\n");
    return 0;
}
