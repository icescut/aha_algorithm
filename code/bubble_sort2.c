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
    // ���ԭʼ����
    printf("ԭʼ���飺\n");
    for (int i = 0; i < SRC_LEN; ++i)
        printf("%s: %d\n", input[i].name, input[i].score);
    printf("\n");

    // ����
    // [0, SRC_LEN-1] ==> [0, 1], n-1��
    for (int i = 0; i < SRC_LEN-1; ++i)
        for (int j = 0; j < SRC_LEN-i-1; ++j)
            if (input[j].score > input[j+1].score)
            {
                tmp = input[j];
                input[j] = input[j+1];
                input[j+1] = tmp;
            }
    // �������������
    printf("�����  ��\n");
    for (int i = 0; i < SRC_LEN; ++i)
        printf("%s: %d\n", input[i].name, input[i].score);

    printf("\n");

    return 0;        
}
