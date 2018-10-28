#include <stdio.h>

#define SRC_LEN 5

typedef struct {
    char name[21];
    char score;
} student;

int main()
{
    student input[5] = {
        {"huhu", 5},
        {"haha", 3},
        {"xixi", 5},
        {"hengheng", 2},
        {"gaoshou", 8}
    };
    student tmp;
    // 输出原始数组
    printf("原始数组：\n");
    for (int i = 0; i < SRC_LEN; ++i)
        printf("%s: %d\n", input[i].name, input[i].score);
    printf("\n");

    // 排序
    // [0, SRC_LEN-1] ==> [0, 1], n-1遍
    for (int i = 0; i < SRC_LEN-1; ++i)
        for (int j = 0; j < SRC_LEN-i-1; ++j)
            if (input[j].score > input[j+1].score)
            {
                tmp = input[j];
                input[j] = input[j+1];
                input[j+1] = tmp;
            }
    // 输出排序后的数组
    printf("排序后  ：\n");
    for (int i = 0; i < SRC_LEN; ++i)
        printf("%s: %d\n", input[i].name, input[i].score);

    printf("\n");

    return 0;        
}
