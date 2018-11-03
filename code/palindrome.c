/****************************************************************************
 * File name    : card_game.c
 * Author       : Alan Liang
 * Description  : 《啊哈，算法》回文
 * History      :
 *                v0.1  Alan        2018/11/03 建立文件
 ****************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[100], stack[100];
    int top = 0, next;

    // 接受输入
    printf("请输入一个字符串：");
    gets(input);

    int len = strlen(input);
    int mid = len / 2 - 1;

    // 前半部分入栈
    for (int i = 0; i <= mid; ++i)
        stack[top++] = input[i];

    // 得到非中点的下一个位置
    if (len % 2 == 0)
        next = mid + 1;
    else
        next = mid + 2;

    // 依次比较
    for (int i = next; i < len; ++i)
    {
        if(stack[--top] != input[i])
        {
            printf("FALSE\n");
            return 0;
        }
    }
    printf("TRUE\n");
    return 0;
}
