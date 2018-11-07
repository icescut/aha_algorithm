/****************************************************************************
 * File name    : linked_list.c
 * Author       : Alan Liang
 * Description  : 《啊哈，算法》链表
 * History      :
 *                v0.1  Alan        2018/11/07 建立文件
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// 链表
typedef struct node
{
    int data;
    struct node *next;
} node;

int main(void)
{
    node *head = NULL, *p, *q, *t;
    int input[] = {2, 3, 5, 8, 9, 10, 18, 26, 32};
    int a = 6;

    // 建立链表
    for (int i = 0; i < 9; ++i)
    {
        p = (node *)malloc(sizeof(node));
        p->data = input[i];
        p->next = NULL;
        if (head == NULL)
            head = p;
        else
            q->next = p;
        q = p;
    }

    // 插入6到合适的位置
    t = head;
    while(t != NULL)
    {
        // 有问题，未考虑插入头部的问题
        if (t->next->data > a)
        {
            p = (node *)malloc(sizeof(node));
            p->data = a;
            p->next = t->next;
            t->next = p;
            break;
        }
        t = t->next;
    }

    // 遍历链表
    t = head;
    while(t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
    return 0;
}
