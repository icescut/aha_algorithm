#include <stdio.h>

#define SRC_LEN 10

int main()
{
    int input[] = {8, 100, 50, 22, 15, 6, 1, 1000, 999, 0};
    int tmp;

    // 输出原始数组
    printf("原始数组：");
    for (int i = 0; i < SRC_LEN; ++i)
        printf("%d ",input[i]);
    printf("\n");

    // 排序
    // [0, SRC_LEN-1] ==> [0, 1], n-1遍
    for (int i = 0; i < SRC_LEN-1; ++i)
        for (int j = 0; j < SRC_LEN-i-1; ++j)
            if (input[j] > input[j+1])
            {
                tmp = input[j];
                input[j] = input[j+1];
                input[j+1] = tmp;
            }

    // 输出排序后的数组
    printf("排序后  ：");
    for (int i = 0; i < SRC_LEN; ++i)
        printf("%d ", input[i]);

    printf("\n");

    return 0;        
}
