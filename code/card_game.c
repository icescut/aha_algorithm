/****************************************************************************
 * File name    : card_game.c
 * Author       : Alan Liang
 * Description  : ���������㷨��Сè������Ϸ
 *                ����ֻ��9�����棺1~9
 *                ��ͷΪ��һ��Ԫ��λ��
 *                ��βΪ��һ������λ��
 *                ջ��Ϊ��һ�����õ�λ��
 * History      :
 *                v0.1  Alan        2018/11/03 �����ļ�
 ****************************************************************************/

#include <stdio.h>

// ����
typedef struct queue
{
    int data[1000];
    int head;
    int tail;
} queue;

// ̨��
typedef struct stack
{
    int data[10];
    int top;
} stack;

// ��������ʲô��
int book[10] = {0};
stack s;

void play(queue *q);
void show_cards(queue q1, queue q2, stack s);
void show_info(queue q);

int main(void)
{
    queue q1, q2;

    // ��ʼ��
    q1.head = 0;
    q1.data[0] = 2;
    q1.data[1] = 4;
    q1.data[2] = 1;
    q1.data[3] = 2;
    q1.data[4] = 5;
    q1.data[5] = 6;
    q1.tail = 6;

    q2.head = 0;
    q2.data[0] = 3;
    q2.data[1] = 1;
    q2.data[2] = 3;
    q2.data[3] = 5;
    q2.data[4] = 6;
    q2.data[5] = 4;
    q2.tail = 6;

    s.top = 0;

    show_cards(q1, q2, s);

    while(q1.head < q1.tail && q2.head < q2.tail)
    {
        play(&q1);
        play(&q2);
        show_cards(q1, q2, s);
    }

    if(q1.head == q1.tail)
    {
        printf("С��win\n");
    } else
    {
        printf("С��win\n");
    }

    return 0;
}

/*
 * Function     : ����
 * Description  : 
 * In           : ����
 * Out          : void
 */
void play(queue *q)
{
    // �������
    int t = q->data[q->head++];

    // ̨��û��������
    if(!book[t])
    {
        // ��¼�������Ѿ�������
        book[t] = 1;
        // ���Ʒŵ�̨��
        s.data[s.top++] = t;
    } else
    // ���Ӯ��
    {
        // ���ղų��ĳ��ƷŻ�����
        q->data[q->tail++] = t;
        // ��̨���ϵ��Ʒŵ�����
        while(s.data[s.top-1] != t)
        {
            // ��¼�����Ʋ���̨����
            book[s.data[s.top-1]] = 0;
            // ��������
            q->data[q->tail++] = s.data[s.top-1];
            s.top--;
        }
    }
}

/*
 * Function     : ��ӡ���ƺ�̨�����
 * Description  : 
 * In           : ���ƣ�̨��
 * Out          : void
 */
void show_cards(queue q1, queue q2, stack s)
{
    printf("===========================================\n");
    printf("%s: ", "С�ߣ�");
    for (int i = q1.head; i < q1.tail; ++i)
        printf("%d ", q1.data[i]);
    printf("\n");

    printf("%s: ", "С����");
    for (int i = q2.head; i < q2.tail; ++i)
        printf("%d ", q2.data[i]);
    printf("\n");

    printf("%s: ", "̨�棺");
    for (int i = 0; i < s.top; i++)
        printf("%d ", s.data[i]);
    printf("\n");
}
