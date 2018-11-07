/****************************************************************************
 * File name    : linked_list.c
 * Author       : Alan Liang
 * Description  : ���������㷨������
 * History      :
 *                v0.1  Alan        2018/11/07 �����ļ�
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// ����
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

    // ��������
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

    // ����6�����ʵ�λ��
    t = head;
    while(t != NULL)
    {
        // �����⣬δ���ǲ���ͷ��������
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

    // ��������
    t = head;
    while(t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
    return 0;
}
