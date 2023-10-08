#define MAX_INPUT 50

#define STR_SUCCESS "Success!"
#define STR_FAILURE "Failure!"
#define STR_NO_FOUND "No Found!"


typedef struct Vocabulary{
    char* word;
    char* meaning;
} voca;

extern voca* VocaList;
extern int voca_num;

int search_voca(char* in_word);       //查找单词

int add_voca(char* in_word, char* in_meaning);     // 添加单词

//char* del_voca();        // 删除单词

int rand_voca();       // 随机取词