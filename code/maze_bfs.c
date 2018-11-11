/****************************************************************************
 * File name    : maze_bfs.c
 * Author       : Alan Liang
 * Description  : 《啊哈，算法》在迷宫中解救小哈
 *                  迷宫是由一格一格组成的，每次只能走一步，有上下左右四个方向
 * History      :
 *                v0.1  Alan        2018/11/11 建立文件
 ****************************************************************************/

#include <stdio.h>

#define NEXT_NO 4
#define MAX_ROW 50
#define MAX_COL 50

// 记录一步的信息
typedef struct node
{
    int row;    // 行
    int col;    // 列
    int step;   // 步数
} node;

// 队列
node queue[MAX_ROW*MAX_COL];

int head;   // 记录队头
int tail;   // 记录队尾（下一个可用位置）

// 迷宫上的点(行，列)
int maze[MAX_ROW][MAX_COL] = {
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 1},
};

// 该点是否已经走过
int done[MAX_ROW][MAX_COL];

// 开始位置
int start_row = 0, start_col = 0;
// 目标位置
int target_row = 3, target_col = 2;

// 最小步数
int min = 9999;

// 可以走的方向：右下左上
int next[NEXT_NO][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

// 边界(含)
int bound_left = 0;
int bound_right = 3;
int bound_top = 0;
int bound_bottom = 4;

int main(void)
{
    // 初始化（起点）
    head = tail = 0;
    queue[tail].row = start_row;
    queue[tail].col = start_col;
    queue[tail].step = 0;
    ++tail;
    done[start_row][start_col] = 1;

    // 是否到达目标标记
    int flag = 0;   

    // 当未遍历完迷宫中的点
    while(head < tail)
    {
        // 遍历4个方向
        for (int i = 0; i < NEXT_NO; ++i)
        {
            int next_row = queue[head].row + next[i][0];
            int next_col = queue[head].col + next[i][1];

            // 如果超出边界
            if (next_row < bound_top ||
                next_row > bound_bottom ||
                next_col < bound_left ||
                next_col > bound_right)
                continue;

            // 未走过且可以走
            if (maze[next_row][next_col] == 0 &&
                done[next_row][next_col] == 0)
            {
                done[next_row][next_col] = 1;
                queue[tail].row = next_row;
                queue[tail].col = next_col;
                queue[tail].step = queue[head].step+1;
                ++tail;
            }
            // 到达目标点？
            if (next_row == target_row && next_col == target_col)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
        // 移除头结点
        ++head;
    }

    printf("最小步数为%d\n", queue[tail-1].step);

    return 0;
}
