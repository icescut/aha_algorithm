/****************************************************************************
 * File name    : card_game.c
 * Author       : Alan Liang
 * Description  : 《啊哈，算法》小猫钓鱼游戏
 *                假设只有9种牌面：1~9
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

int main(void)
{
    queue q1, q2;
    return 0;
}
