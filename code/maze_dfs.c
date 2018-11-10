/****************************************************************************
 * File name    : maze_dfs.c
 * Author       : Alan Liang
 * Description  : 《啊哈，算法》在迷宫中解救小哈
 *                  迷宫是由一格一格组成的，每次只能走一步，有上下左右四个方向
 * History      :
 *                v0.1  Alan        2018/11/10 建立文件
 ****************************************************************************/

#define NEXT_NO 4
#define MAX_ROW 50
#define MAX_COL 50

#include <stdio.h>

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

/*
 * Function     : 遍历当前位置所有可能走的方向，进行下一步
 * Description  :
 * In           : 当前位置，当前是第几步
 * Out          : void
 */
void go(int row, int col, int step)
{
    // printf("第%d步走到(%d,%d)\n", step, row, col);  // DEBUG
    // 到达小哈的位置
    if (row == target_row && col == target_col)
    {
        // printf("到达目的地\n"); // DEBUG
        if(step < min)
            min = step;
        return;
    }

    // 遍历4个方向
    for (int i = 0; i < NEXT_NO; ++i)
    {
        // 下一个位置
        int next_row = row + next[i][0];
        int next_col = col + next[i][1];

        // 如果超出边界
        if (next_row < bound_top ||
            next_row > bound_bottom ||
            next_col < bound_left ||
            next_col > bound_right)
            continue;

        // 可以走
        if (maze[next_row][next_col] == 0 &&
            done[next_row][next_col] == 0)
        {
            done[next_row][next_col] = 1;
            // 下一步
            go(next_row, next_col, step+1);
            // 恢复未走过
            done[next_row][next_col] = 0;
        }
    }
    // printf("回到第%d步\n", step-1);  // DEBUG
    return;
}

int main(void)
{
    done[start_row][start_col] = 1;
    go(start_row, start_col, 0);

    printf("最小步数为%d\n", min);

    return 0;
}
