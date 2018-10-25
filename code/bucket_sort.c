#include <stdio.h>

#define SRC_LEN 5

int main()
{
    int a[11] = {0};
    int input[] = {8, 5, 2, 3, 5};

    // 输出原始数组
    printf("原始数组：");
    for (int i = 0; i < SRC_LEN; ++i)
        printf("%d ",input[i]);
    printf("\n");

    // 排序
    for (int i = 0; i < SRC_LEN; ++i)
        a[input[i]]++;

    // 输出排序后的数组
    printf("排序后  ：");
    for (int i = 0; i < 11; ++i)
        for (int j = 0; j < a[i]; ++j)
            printf("%d ", i);
    

    printf("\n");

    return 0;        
}
