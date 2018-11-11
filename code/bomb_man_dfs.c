/****************************************************************************
 * File name    : bomb_man_dfs.c
 * Author       : Alan Liang
 * Description  : 《啊哈，算法》炸弹人，dfs实现
 *                  # 墙
 *                  G 敌人
 *                  . 平地
 * History      :
 *                v0.1  Alan        2018/11/11 建立文件
 ****************************************************************************/

#include <stdio.h>

#define NEXT_NO 4
#define MAX_ROW 50
#define MAX_COL 50

// 地图
char map[MAX_ROW][MAX_COL] = {
//    0   1   2   3   4   5   6   7   8   9   10  11  12
    {'#','#','#','#','#','#','#','#','#','#','#','#','#'}, // 0
    {'#','G','G','.','G','G','G','#','G','G','G','.','#'}, // 1
    {'#','#','#','.','#','G','#','G','#','G','#','G','#'}, // 2
    {'#','.','.','.','.','.','.','.','#','.','.','G','#'}, // 3
    {'#','G','#','.','#','#','#','.','#','G','#','G','#'}, // 4
    {'#','G','G','.','G','G','G','.','#','.','G','G','#'}, // 5
    {'#','G','#','.','#','G','#','.','#','.','#',' ','#'}, // 6
    {'#','#','G','.','.','.','G','.','.','.','.','.','#'}, // 7
    {'#','G','#','.','#','G','#','#','#','.','#','G','#'}, // 8
    {'#','.','.','.','G','#','G','G','G','.','G','G','#'}, // 9
    {'#','G','#','.','#','G','#','G','#','.','#','G','#'}, // 10
    {'#','G','G','.','G','G','G','#','G','.','G','G','#'}, // 11
    {'#','#','#','#','#','#','#','#','#','#','#','#','#'}, // 12
};

// 该点是否已经判断过
int done[MAX_ROW][MAX_COL];

// 开始位置
int start_row = 3, start_col = 3;

// 最大消灭敌人数
int max = 0;
int sum;
int target_row, target_col;

// 可以走的方向：右下左上
int next[NEXT_NO][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

// 边界(含)
int bound_left = 1;
int bound_right = 11;
int bound_top = 1;
int bound_bottom = 11;

// 获取某个点上放置炸弹可以消灭的敌人数
int get_enemy(int row, int col)
{
    int sum = 0;
    int x, y;

    // 向上方向
    x = row;
    y = col;
    while(map[x][y] != '#') //不是墙
    {
        if(map[x][y] == 'G') ++sum;
        --x;
    }

    // 向下方向
    x = row;
    y = col;
    while(map[x][y] != '#') //不是墙
    {
        if(map[x][y] == 'G') ++sum;
        ++x;
    }

    // 向左方向
    x = row;
    y = col;
    while(map[x][y] != '#') //不是墙
    {
        if(map[x][y] == 'G') ++sum;
        --y;
    }

    // 向右方向
    x = row;
    y = col;
    while(map[x][y] != '#') //不是墙
    {
        if(map[x][y] == 'G') ++sum;
        ++y;
    }

    return sum;
}

// 当前点的判断
void go(int row, int col)
{
    sum = get_enemy(row, col);
    // 更新max
    if (sum > max) 
    {
        max = sum;
        target_row = row;
        target_col = col;
    }

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

        // 未走过且可以走
        if (map[next_row][next_col] == '.' &&
            done[next_row][next_col] == 0)
        {
            // 标记为已走过
            done[next_row][next_col] = 1;
            // 判断下一个点
            go(next_row, next_col);
            // 注意无需重新标记为未走过
        }
    }
    return;
}

int main(void)
{
    // 初始化（起点）
    done[start_row][start_col] = 1;

    go(start_row, start_col);

    printf("将炸弹放置在(%d,%d)，最多可以消灭%d个敌人\n",target_row, target_col, max);

    return 0;
}
