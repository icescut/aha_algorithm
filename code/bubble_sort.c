#include <stdio.h>

#define SRC_LEN 10

int main()
{
    int input[] = {8, 100, 50, 22, 15, 6, 1, 1000, 999, 0};
    int tmp;

    // ���ԭʼ����
    printf("ԭʼ���飺");
    for (int i = 0; i < SRC_LEN; ++i)
        printf("%d ",input[i]);
    printf("\n");

    // ����
    // [0, SRC_LEN-1] ==> [0, 1], n-1��
    for (int i = 0; i < SRC_LEN-1; ++i)
        for (int j = 0; j < SRC_LEN-i-1; ++j)
            if (input[j] > input[j+1])
            {
                tmp = input[j];
                input[j] = input[j+1];
                input[j+1] = tmp;
            }

    // �������������
    printf("�����  ��");
    for (int i = 0; i < SRC_LEN; ++i)
        printf("%d ", input[i]);

    printf("\n");

    return 0;        
}
