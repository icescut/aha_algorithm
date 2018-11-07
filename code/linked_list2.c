/****************************************************************************
 * File name    : linked_list2.c
 * Author       : Alan Liang
 * Description  : 《啊哈，算法》模拟链表
 * History      :
 *                v0.1  Alan        2018/11/07 建立文件
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 数据
    int data[100] = {0, 2, 3, 5, 8, 9, 10, 18, 26, 32};
    // 该位置的下一个元素的位置
    int right[100] = {0};
    for (int i = 1; i < 9; ++i)
    {
        right[i] = i+1;
    }
    int head = 1;
    int tail = 10;
    int a = 6;

    // 插入6到合适的位置
    int t = head;
    while(t != 0)
    {
        // 有问题，未考虑插入头部的问题
        if (data[right[t]] > a)
        {
            data[tail] = a;
            right[tail] = right[t];
            right[t] = tail++;
            break;
        }
        t = right[t];
    }

    // 遍历链表
    t = head;
    while(t != 0)
    {
        printf("%d ", data[t]);
        t = right[t];
    }
    printf("\n");
    return 0;
}
