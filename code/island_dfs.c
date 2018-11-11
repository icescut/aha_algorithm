/****************************************************************************
 * File name    : island_dfs.c
 * Author       : Alan Liang
 * Description  : 《啊哈，算法》宝岛探险
 *                  0   - 海洋
 *                  1~9 - 陆地
 * History      :
 *                v0.1  Alan        2018/11/11 建立文件
 ****************************************************************************/

#include <stdio.h>

#define NEXT_NO 4
#define MAX_ROW 50
#define MAX_COL 50

// 地图
int map[MAX_ROW][MAX_COL] = {
//   0  1  2  3  4  5  6  7  8  9
    {1, 2, 1, 0, 0, 0, 0, 0, 2, 3}, // 0
    {3, 0, 2, 0, 1, 2, 1, 0, 1, 2}, // 1
    {4, 0, 1, 0, 1, 2, 3, 2, 0, 1}, // 2
    {3, 2, 0, 0, 0, 1, 2, 4, 0, 0}, // 3
    {0, 0, 0, 0, 0, 0, 1, 5, 3, 0}, // 4
    {0, 1, 2, 1, 0, 1, 5, 4, 3, 0}, // 5
    {0, 1, 2, 3, 1, 3, 6, 2, 1, 0}, // 6
    {0, 0, 3, 4, 8, 9, 7, 5, 0, 0}, // 7
    {0, 0, 0, 3, 7, 8, 6, 0, 1, 2}, // 8
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 9
};

// 该点是否已经判断过
int done[MAX_ROW][MAX_COL];

// 开始位置
int start_row = 5, start_col = 7;

// 降落岛屿的面积
int sum;

// 可以走的方向：右下左上
int next[NEXT_NO][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

// 边界(含)
int bound_left = 0;
int bound_right = 9;
int bound_top = 0;
int bound_bottom = 9;

void go(int row, int col)
{
    // 遍历4个方向
    for (int i = 0; i < NEXT_NO; ++i)
    {
        int next_row = row + next[i][0];
        int next_col = col + next[i][1];

        // 如果超出边界
        if (next_row < bound_top ||
            next_row > bound_bottom ||
            next_col < bound_left ||
            next_col > bound_right)
            continue;

        // 未走过且不是海洋
        if (map[next_row][next_col] > 0 &&
            done[next_row][next_col] == 0)
        {
            ++sum;
            done[next_row][next_col] = 1;
            go(next_row, next_col);
        }
    }
    return;
}

int main(void)
{
    done[start_row][start_col] = 1;
    sum = 1;
    go(start_row, start_col);

    printf("降落的岛屿的面积为%d\n",sum);

    return 0;
}
