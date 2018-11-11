/****************************************************************************
 * File name    : island_bfs.c
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

// 记录一步的信息
typedef struct node
{
    int row;    // 行
    int col;    // 列
} node;

// 队列
node queue[MAX_ROW*MAX_COL];

int head;   // 记录队头
int tail;   // 记录队尾（下一个可用位置）

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

int main(void)
{
    // 初始化（起点）
    head = tail = 0;
    queue[tail].row = start_row;
    queue[tail].col = start_col;
    ++tail;
    done[start_row][start_col] = 1;
    sum = 1;

    // 当未遍历完地图中的点
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

            // 未走过且不是海洋
            if (map[next_row][next_col] > 0 &&
                done[next_row][next_col] == 0)
            {
                // 加入队列
                done[next_row][next_col] = 1;
                queue[tail].row = next_row;
                queue[tail].col = next_col;
                ++tail;

                ++sum;
            }
        }
        // 移除头结点
        ++head;
    }

    printf("降落的岛屿的面积为%d\n",sum);

    return 0;
}
