/****************************************************************************
 * File name    : qq_number.c
 * Author       : Alan Liang
 * Description  : 《啊哈，算法》猜qq号码游戏
 * History      :
 *                v0.1  Alan        2018/11/03 建立文件
 ****************************************************************************/

#include <stdio.h>

int main(void)
{
    int list[100] = {6, 3, 1, 7, 5, 8, 9, 2, 4};
    int head = 0, tail = 9;
    while(head != tail)
    {
        // 删除一个数
        printf("%d", list[head++]);
        // 将下一个数移到队尾
        list[tail++] = list[head++];
    }
    printf("\n");
    return 0;
}
