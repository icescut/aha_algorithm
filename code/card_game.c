/****************************************************************************
 * File name    : card_game.c
 * Author       : Alan Liang
 * Description  : 《啊哈，算法》小猫钓鱼游戏
 *                假设只有9种牌面：1~9
 *                队头为第一个元素位置
 *                队尾为下一个可用位置
 *                栈顶为下一个可用的位置
 * History      :
 *                v0.1  Alan        2018/11/03 建立文件
 ****************************************************************************/

#include <stdio.h>

// 手牌
typedef struct queue
{
    int data[1000];
    int head;
    int tail;
} queue;

// 台面
typedef struct stack
{
    int data[10];
    int top;
} stack;

// 桌面上有什么牌
int book[10] = {0};
stack s;

void play(queue *q);
void show_cards(queue q1, queue q2, stack s);
void show_info(queue q);

int main(void)
{
    queue q1, q2;

    // 初始化
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
        printf("小哈win\n");
    } else
    {
        printf("小哼win\n");
    }

    return 0;
}

/*
 * Function     : 出牌
 * Description  : 
 * In           : 手牌
 * Out          : void
 */
void play(queue *q)
{
    // 打出的牌
    int t = q->data[q->head++];

    // 台面没有这张牌
    if(!book[t])
    {
        // 记录这张牌已经出过了
        book[t] = 1;
        // 把牌放到台面
        s.data[s.top++] = t;
    } else
    // 如果赢牌
    {
        // 将刚才出的出牌放回手牌
        q->data[q->tail++] = t;
        // 将台面上的牌放到手牌
        while(s.data[s.top-1] != t)
        {
            // 记录这张牌不在台面了
            book[s.data[s.top-1]] = 0;
            // 放入手牌
            q->data[q->tail++] = s.data[s.top-1];
            s.top--;
        }
    }
}

/*
 * Function     : 打印手牌和台面情况
 * Description  : 
 * In           : 手牌，台面
 * Out          : void
 */
void show_cards(queue q1, queue q2, stack s)
{
    printf("===========================================\n");
    printf("%s: ", "小哼：");
    for (int i = q1.head; i < q1.tail; ++i)
        printf("%d ", q1.data[i]);
    printf("\n");

    printf("%s: ", "小哈：");
    for (int i = q2.head; i < q2.tail; ++i)
        printf("%d ", q2.data[i]);
    printf("\n");

    printf("%s: ", "台面：");
    for (int i = 0; i < s.top; i++)
        printf("%d ", s.data[i]);
    printf("\n");
}
